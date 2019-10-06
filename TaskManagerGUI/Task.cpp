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
