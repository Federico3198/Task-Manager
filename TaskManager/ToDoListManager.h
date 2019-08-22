#pragma once
#include <list>
#include "ToDoList.h"
#include <ctime>
#include "TimeUtils.h"

class ToDoListManager
{
public:
	std::list<ToDoList> toDoLists;

public:
	std::list<std::shared_ptr<Task>> GetImportantTasks();
	std::list<std::shared_ptr<Task>> GetTodayTasks();
	std::list<std::shared_ptr<Task>> GetThisWeekTasks();
	bool AddTask(std::shared_ptr<Task> task, int listId);
	bool RemoveTask(std::shared_ptr<Task> task, int listId);
	ToDoListManager();
	ToDoListManager(std::list<ToDoList> toDoLists);
	~ToDoListManager();
};

