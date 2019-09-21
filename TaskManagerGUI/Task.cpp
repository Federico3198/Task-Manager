#include "stdafx.h"
#include "Task.h"



void Task::AddSubTask(std::shared_ptr<SubTask> subTask)
{
	subTasks.push_back(subTask);
}

void Task::AddComment(std::shared_ptr<Comment> comment)
{
	comments.push_back(comment);
}

std::shared_ptr<SubTask> Task::GetSubTask(int index)
{
	auto iterator = subTasks.begin();
	std::advance(iterator, index);
	return *iterator;
}

std::shared_ptr<Comment> Task::GetComment(int index)
{
	auto iterator = comments.begin();
	std::advance(iterator, index);
	return *iterator;
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
