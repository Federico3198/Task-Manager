#include "pch.h"
#include "Task.h"

void Task::AddSubTask(std::shared_ptr<SubTask> subTask)
{
	if (subTask != NULL)
	{
		subTasks.push_back(subTask);
	}
}

void Task::RemoveSubTask(std::shared_ptr<SubTask> subTask)
{
	subTasks.remove(subTask);
}

std::shared_ptr<SubTask> Task::GetSubTask(int index)
{
	if (index > -1)
	{
		auto iterator = subTasks.begin();
		std::advance(iterator, index);
		return *iterator;
	}
	else
	{
		return NULL;
	}
}

std::list<std::shared_ptr<SubTask>> Task::GetSubTasks()
{
	return subTasks;
}

Task::Task(std::string title)
{
	if ((&title) == NULL)
	{
		title = "";
	}
	this->title = title;
	repetition = RepetitionType::None;
	isImportant = false;
	isCompleted = false;
	notes = "";
	dueDate = DateTime();
}

Task::~Task() {}