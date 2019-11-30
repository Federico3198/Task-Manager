#pragma once
#include <list>
#include "ToDoList.h"
#include <ctime>
#include "TimeUtils.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

class ToDoListManager
{
public:
	std::list<std::shared_ptr<Task>> GetImportantTasks();
	std::list<std::shared_ptr<Task>> GetTodayTasks();
	std::list<std::shared_ptr<Task>> GetThisWeekTasks();
	bool AddTask(std::shared_ptr<Task> task, int listId);
	bool RemoveTask(std::shared_ptr<Task> task, int listId);
	void AddList(std::shared_ptr<ToDoList> newList);
	bool RemoveList(int listId);
	std::shared_ptr<ToDoList> GetListByID(int listId);
	void SaveToJson(std::string filePath);
	void LoadFromJson(std::string filePath);
	std::list<std::shared_ptr<ToDoList>> GetToDoLists();
	ToDoListManager();
	ToDoListManager(std::list<std::shared_ptr<ToDoList> > toDoLists);
	~ToDoListManager();

private:
	std::list<std::shared_ptr<ToDoList> > toDoLists;
};