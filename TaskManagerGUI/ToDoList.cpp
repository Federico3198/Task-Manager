#include "stdafx.h"
#include "ToDoList.h"

int ToDoList::nextId = 0;

int ToDoList::GetId()
{
	return id;
}

void ToDoList::AddTask(std::shared_ptr<Task> task)
{
	tasks.push_back(task);
}

void ToDoList::RemoveTask(std::shared_ptr<Task> task)
{
	tasks.remove(task);
}

int ToDoList::GetUncompletedTaskCount()
{
	return GetTaskCount(false);
}

std::shared_ptr<Task> ToDoList::GetCompletedTask(int index)
{
	return GetTask(index, true);
}

int ToDoList::GetCompletedTaskCount()
{
	return GetTaskCount(true);
}

std::shared_ptr<Task> ToDoList::GetUncompletedTask(int index)
{
	return GetTask(index, false);
}

std::list<std::shared_ptr<Task>> ToDoList::GetUncompletedTasks()
{
	std::list<std::shared_ptr<Task>> uncompletedTasks = std::list<std::shared_ptr<Task>>();
	for (auto taskIterator = tasks.begin(); taskIterator != tasks.end(); taskIterator++)
	{
		if (!(*taskIterator)->isCompleted)
		{
			uncompletedTasks.push_back(*taskIterator);
		}
	}
	return uncompletedTasks;
}

ToDoList::ToDoList(std::string listName)
{
	this->id = nextId;
	nextId++;

	this->listName = listName;
	tasks = std::list<std::shared_ptr<Task>>();
}

bool ToDoList::operator==(const ToDoList & other)
{
	return id==other.id;
}

ToDoList::~ToDoList()
{
}

std::shared_ptr<Task> ToDoList::GetTask(int index, bool isCompleted)
{
	int taskCount = 0;
	for (auto iterator = tasks.begin(); iterator != tasks.end(); iterator++)
	{
		if ((*iterator)->isCompleted == isCompleted)
		{
			if (taskCount == index)
			{
				return *iterator;
			}
			taskCount++;
		}
	}
	return NULL;
}

int ToDoList::GetTaskCount(bool isCompleted)
{
	int taskCount = 0;
	for (auto iterator = tasks.begin(); iterator != tasks.end(); iterator++)
	{
		if ((*iterator)->isCompleted == isCompleted)
		{
			taskCount++;
		}
	}
	return taskCount;
}
