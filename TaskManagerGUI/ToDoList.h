#pragma once
#include <list>
#include "Task.h"
class ToDoList
{
public:
	std::string listName;

private:
	int id = 0;
	static int nextId;
	std::list<std::shared_ptr<Task>> tasks;

public:
	int GetId();
	void AddTask(std::shared_ptr<Task> task);
	void RemoveTask(std::shared_ptr<Task> task);
	int GetUncompletedTaskCount();
	std::shared_ptr<Task> GetCompletedTask(int index);
	int GetCompletedTaskCount();
	std::shared_ptr<Task> GetUncompletedTask(int index);

	std::list<std::shared_ptr<Task> > GetUncompletedTasks();
	std::list<std::shared_ptr<Task>> GetCompletedTasks();
	ToDoList(std::string listName);
	bool operator ==(const ToDoList &other);

	std::list<std::shared_ptr<Task>> GetAllTasks();

	~ToDoList();


private:
	std::shared_ptr<Task> GetTask(int index, bool isCompleted);
	int GetTaskCount(bool isCompleted);
};

