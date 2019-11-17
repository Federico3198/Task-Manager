#pragma once
#include <list>
#include "ToDoList.h"
#include <ctime>
#include "TimeUtils.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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
	void SaveToJson();
	ToDoListManager();
	ToDoListManager(std::list<ToDoList> toDoLists);
	~ToDoListManager();
};

