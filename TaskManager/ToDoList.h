#pragma once
#include <list>
#include "Task.h"
class ToDoList
{
public:
	std::string listName;

private:
	std::list<std::shared_ptr<Task>> tasks;

public:
	void AddTask(std::shared_ptr<Task> task);
	void RemoveTask(std::shared_ptr<Task> task);
	int GetUncompletedTaskCount();
	std::shared_ptr<Task> GetCompletedTask(int index);
	int GetCompletedTaskCount();
	std::shared_ptr<Task> GetUncompletedTask(int index);
	ToDoList(std::string listName);
	~ToDoList();

private:
	std::shared_ptr<Task> GetTask(int index, bool isCompleted);
	int GetTaskCount(bool isCompleted);
};

