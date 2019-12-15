#include "stdafx.h"
#include "Task.h"


void Task::AddSubTask(std::shared_ptr<SubTask> subTask)
{
	subTasks.push_back(subTask);
}

void Task::RemoveSubTask(std::shared_ptr<SubTask> subTask)
{
	subTasks.remove(subTask);
}

void Task::AddComment(std::shared_ptr<Comment> comment)
{
	comments.push_back(comment);
}

void Task::RemoveComment(std::shared_ptr<Comment> comment)
{
	comments.remove(comment);
}

std::shared_ptr<SubTask> Task::GetSubTask(int index)
{
	auto iterator = subTasks.begin();
	std::advance(iterator, index);
	return *iterator;
}

std::list<std::shared_ptr<SubTask>> Task::GetSubTasks()
{
	return subTasks;
}

std::list<std::shared_ptr<Comment>> Task::GetComments()
{
	return comments;
}

Task::Task(std::string title)
{
	this->title = title;
	repetition = RepetitionType::None;
	isImportant = false;
	isCompleted = false;
	notes = "";
	dueDate = DateTime();
}

Task::~Task() {}