#include "stdafx.h"
#include "ToDoListManager.h"

std::list<std::shared_ptr<Task>> ToDoListManager::GetImportantTasks()
{
	std::list<std::shared_ptr<Task>> importantTasks;
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		auto tasks = (*toDoListIterator)->GetUncompletedTasks();
		for (auto taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
		{
			if ((*taskIterator)->isImportant)
			{
				importantTasks.push_back(*taskIterator);
			}
		}
	}
	return importantTasks;
}

std::list<std::shared_ptr<Task>> ToDoListManager::GetTodayTasks()
{
	std::list<std::shared_ptr<Task>> todayTasks;
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		auto tasks = (*toDoListIterator)->GetUncompletedTasks();
		for (auto taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
		{
			DateTime dueDate = (*taskIterator)->dueDate;
			DateTime endOfToday(TimeUtils::GetEndOfToday());

			if (dueDate <= endOfToday)
			{
				todayTasks.push_back(*taskIterator);
			}
		}
	}
	return todayTasks;
}

std::list<std::shared_ptr<Task>> ToDoListManager::GetThisWeekTasks()
{
	std::list<std::shared_ptr<Task>> thisWeekTasks;
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		auto tasks = (*toDoListIterator)->GetUncompletedTasks();
		for (auto taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
		{
			DateTime dueDate = (*taskIterator)->dueDate;
			DateTime endOfWeek(TimeUtils::GetEndOfWeek());

			if (dueDate <= endOfWeek)
			{
				thisWeekTasks.push_back(*taskIterator);
			}
		}
	}
	return thisWeekTasks;
}

bool ToDoListManager::AddTask(std::shared_ptr<Task> task, int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if ((*toDoListIterator)->GetId() == listId)
		{
			(*toDoListIterator)->AddTask(task);
			return true;
		}
	}
	return false;
}

bool ToDoListManager::RemoveTask(std::shared_ptr<Task> task, int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if ((*toDoListIterator)->GetId() == listId)
		{
			(*toDoListIterator)->RemoveTask(task);
			return true;
		}
	}
	return false;
}

void ToDoListManager::AddList(std::shared_ptr<ToDoList> newList)
{
	toDoLists.push_back(newList);
}

bool ToDoListManager::RemoveList(int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if ((*toDoListIterator)->GetId() == listId)
		{
			toDoLists.remove(*toDoListIterator);
			return true;
		}
	}
	return false;
}

std::shared_ptr<ToDoList> ToDoListManager::GetListByID(int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if ((*toDoListIterator)->GetId() == listId)
		{
			return (*toDoListIterator);
		}
	}
	return false;
}

void ToDoListManager::SaveToJson(std::string filePath)
{
	boost::property_tree::ptree jsonRoot;
	boost::property_tree::ptree todoListsRoot;

	for (auto iterator = toDoLists.begin(); iterator != toDoLists.end(); iterator++)
	{
		auto tdList = (*iterator);

		boost::property_tree::ptree todoListNode;
		todoListNode.put("listName", tdList->listName);
		auto tasks = tdList->GetAllTasks();


		boost::property_tree::ptree tasksNode;
		for (auto tasksIterator = tasks.begin(); tasksIterator != tasks.end(); tasksIterator++)
		{
			boost::property_tree::ptree taskNode;
			taskNode.put("title", (*tasksIterator)->title);
			taskNode.put("isCompleted", (*tasksIterator)->isCompleted);
			taskNode.put("isImportant", (*tasksIterator)->isImportant);
			taskNode.put("dueDate", (*tasksIterator)->dueDate.GetSecondsSince1970());
			taskNode.put("expire", (*tasksIterator)->expire);
			taskNode.put("repetition", RepetitionTypeUtils::ConvertEnumToIta((*tasksIterator)->repetition));
			taskNode.put("notes", (*tasksIterator)->notes);

			auto subTasks = (*tasksIterator)->GetSubTasks();
			boost::property_tree::ptree subTasksNode;
			for (auto subTaskIterator = subTasks.begin(); subTaskIterator != subTasks.end(); subTaskIterator++)
			{
				boost::property_tree::ptree subTaskNode;
				subTaskNode.put("text", (*subTaskIterator)->GetText());
				subTaskNode.put("isCompleted", (*subTaskIterator)->GetIsCompleted());
				subTasksNode.push_back(std::make_pair("", subTaskNode));
			}

			taskNode.add_child("subTasks", subTasksNode);

			auto comments = (*tasksIterator)->GetComments();
			boost::property_tree::ptree commentsNode;
			for (auto commentsIterator = comments.begin(); commentsIterator!=comments.end(); commentsIterator++)
			{
				boost::property_tree::ptree commentNode;
				commentNode.put("owner", (*commentsIterator)->GetOwner());
				commentNode.put("creationDate", (*commentsIterator)->GetCreationDate().GetSecondsSince1970());
				commentNode.put("text", (*commentsIterator)->GetText());
				commentsNode.push_back(std::make_pair("", commentNode));
			}

			taskNode.add_child("comments", commentsNode);

			tasksNode.push_back(std::make_pair("", taskNode));
		}

		todoListNode.add_child("tasks", tasksNode);

		auto child = jsonRoot.find("todoLists");

		if (child == jsonRoot.not_found())
		{
			todoListsRoot.push_back(std::make_pair("", todoListNode));
			jsonRoot.add_child("todoLists", todoListsRoot);
		}
		else
		{
			std::string first = child->first;
			auto second = child->second;

			jsonRoot.clear();
			todoListsRoot.push_back(std::make_pair("", todoListNode));
			jsonRoot.add_child("todoLists", todoListsRoot);
		}
	}

	boost::property_tree::write_json(filePath, jsonRoot);
}

void ToDoListManager::LoadFromJson(std::string filePath)
{

	struct stat buffer;
	bool exists (stat(filePath.c_str(), &buffer) == 0);

	if (!exists)
	{
		std::fstream fs;

		fs.open(filePath, std::fstream::in | std::fstream::out | std::fstream::trunc);

		if (fs.is_open())
		{
			fs << "{}" << std::endl;
			fs.close();
		}
	}

	boost::property_tree::ptree jsonRoot;
	boost::property_tree::read_json(filePath, jsonRoot);
	if (!jsonRoot.empty())
	{
		auto todoListsRoot = jsonRoot.get_child("todoLists");
		BOOST_FOREACH(boost::property_tree::ptree::value_type& todoListsPair, todoListsRoot)
		{

			auto todoListNode = todoListsPair.second;

			auto listName = todoListNode.get<std::string>("listName");

			std::shared_ptr<ToDoList> sharedToDoList(new ToDoList(listName));

			auto tasksRoot = todoListNode.get_child("tasks");

			BOOST_FOREACH(boost::property_tree::ptree::value_type& tasksPair, tasksRoot)
			{
				auto taskNode = tasksPair.second;


				auto title = taskNode.get<std::string>("title");
				std::shared_ptr<Task> sharedTask(new Task(title));

				sharedTask->isCompleted = taskNode.get<bool>("isCompleted");
				sharedTask->isImportant = taskNode.get<bool>("isImportant");
				sharedTask->dueDate = DateTime(taskNode.get<time_t>("dueDate"));
				sharedTask->expire = taskNode.get<bool>("expire");
				sharedTask->repetition = RepetitionTypeUtils::ConvertItaToEnum(taskNode.get<std::string>("repetition"));
				sharedTask->notes = taskNode.get<std::string>("notes");

				auto subTasksRoot = taskNode.get_child("subTasks");

				BOOST_FOREACH(boost::property_tree::ptree::value_type& subTasksPair, subTasksRoot)
				{
					auto subTaskNode = subTasksPair.second;

					auto text = subTaskNode.get<std::string>("text");
					std::shared_ptr<SubTask> sharedSubTask(new SubTask(text));
					sharedSubTask->SetIsCompleted(subTaskNode.get<bool>("isCompleted"));

					sharedTask->AddSubTask(sharedSubTask);
				}

				auto commentsRoot = taskNode.get_child("comments");

				BOOST_FOREACH(boost::property_tree::ptree::value_type& commentsPair, commentsRoot)
				{
					auto commentNode = commentsPair.second;

					auto owner = commentNode.get<std::string>("owner");
					auto creationDate = DateTime(commentNode.get<time_t>("creationDate"));
					auto text = commentNode.get<std::string>("text");

					std::shared_ptr<Comment> sharedComment(new Comment(owner,text,creationDate));

					sharedTask->AddComment(sharedComment);
				}


				sharedToDoList->AddTask(sharedTask);
			}

			AddList(sharedToDoList);
		}
	}

}

std::list<std::shared_ptr<ToDoList>> ToDoListManager::GetToDoLists()
{
	return toDoLists;
}

std::list<ToDoListTaskPair> ToDoListManager::Find(std::string searchString)
{
	std::list<ToDoListTaskPair> result = std::list<ToDoListTaskPair>();

	if (!searchString.empty())
	{
		auto todoLists = GetToDoLists();

		for (auto tdListIterator = todoLists.begin(); tdListIterator != todoLists.end(); tdListIterator++)
		{
			auto tdList = *tdListIterator;
			auto taskList = tdList->GetAllTasks();

			for (auto taskIterator = taskList.begin(); taskIterator != taskList.end(); taskIterator++)
			{
				auto task = *taskIterator;
				if (task->title.find(searchString) != std::string::npos)
				{
					ToDoListTaskPair pair;
					pair.list = tdList;
					pair.task = task;

					result.push_back(pair);
				}
			}
		}
	}

	return result;
}

ToDoListManager::ToDoListManager()
{
	toDoLists = std::list<std::shared_ptr<ToDoList> >();
}

ToDoListManager::ToDoListManager(std::list<std::shared_ptr<ToDoList> > toDoLists)
{
	this->toDoLists = toDoLists;
}


ToDoListManager::~ToDoListManager()
{
}