#pragma once
#include "ToDoList.h"
#include "Task.h"

class ToDoListTaskPair
{
public:
	std::shared_ptr<ToDoList> list;
	std::shared_ptr<Task> task;
};

