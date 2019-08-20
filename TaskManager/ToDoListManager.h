#pragma once
#include <list>
#include "ToDoList.h"

class ToDoListManager
{
public:
	std::list<ToDoList> toDoLists;

public:
	std::list<std::shared_ptr<Task>> GetImportantTasks();
	std::list<std::shared_ptr<Task>> GetTodayTasks();
	std::list<std::shared_ptr<Task>> GetThisWeekTasks();
	void AddTask(std::shared_ptr<Task> task, int listId);
	void RemoveTask(std::shared_ptr<Task> task, int listId);
	ToDoListManager();
	~ToDoListManager();
};

