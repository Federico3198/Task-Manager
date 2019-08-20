#include "pch.h"
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
	return std::list<std::shared_ptr<Task>>();
}

std::list<std::shared_ptr<Task>> ToDoListManager::GetThisWeekTasks()
{
	return std::list<std::shared_ptr<Task>>();
}

void ToDoListManager::AddTask(std::shared_ptr<Task> task, int listId)
{
}

void ToDoListManager::RemoveTask(std::shared_ptr<Task> task, int listId)
{
}

ToDoListManager::ToDoListManager()
{
}


ToDoListManager::~ToDoListManager()
{
}
