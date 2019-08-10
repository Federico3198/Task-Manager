#include "pch.h"
#include "Task.h"



void Task::AddSubTask(Task subTask)
{
	subTasks.push_back(subTask);
}

void Task::AddComment(Comment comment)
{
	comments.push_back(comment);
}

Task Task::GetSubTask(int index)
{
	auto iterator = subTasks.begin();
	std::advance(iterator, index);
	return *iterator;
}

Comment Task::GetComment(int index)
{
	auto iterator = comments.begin();
	std::advance(iterator, index);
	return *iterator;
}

Task::Task()
{
 


Task::~Task()
{
}
