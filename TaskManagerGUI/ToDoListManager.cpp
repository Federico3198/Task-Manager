#include "stdafx.h"
#include "ToDoListManager.h"


std::list<std::shared_ptr<Task>> ToDoListManager::GetImportantTasks()
{
	std::list<std::shared_ptr<Task>> importantTasks;
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		auto tasks = toDoListIterator->GetUncompletedTasks();
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
		auto tasks = toDoListIterator->GetUncompletedTasks();
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
		auto tasks = toDoListIterator->GetUncompletedTasks();
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
		if (toDoListIterator->GetId() == listId)
		{
			toDoListIterator->AddTask(task);
			return true;
		}
	}
	return false;
}

bool ToDoListManager::RemoveTask(std::shared_ptr<Task> task, int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if (toDoListIterator->GetId() == listId)
		{
			toDoListIterator->RemoveTask(task);
			return true;
		}
	}
	return false;
}

void ToDoListManager::AddList(ToDoList newList)
{
	toDoLists.push_back(newList);
}

bool ToDoListManager::RemoveList(int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if (toDoListIterator->GetId() == listId)
		{
			toDoLists.remove(*toDoListIterator);
			return true;
		}
	}
	return false;
}

ToDoList ToDoListManager::GetListByID(int listId)
{
	for (auto toDoListIterator = toDoLists.begin(); toDoListIterator != toDoLists.end(); toDoListIterator++)
	{
		if (toDoListIterator->GetId() == listId)
		{
			return *toDoListIterator;
		}
	}
	return false;
}

ToDoListManager::ToDoListManager()
{
	toDoLists = std::list<ToDoList>();
}

ToDoListManager::ToDoListManager(std::list<ToDoList> toDoLists)
{
	this->toDoLists = toDoLists;
}


ToDoListManager::~ToDoListManager()
{
}
