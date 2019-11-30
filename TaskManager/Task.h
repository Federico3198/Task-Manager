#pragma once
#include "DateTime.h"
#include "RepetitionType.cpp"
#include "Comment.h"
#include <string>
#include <list>
#include <queue>
#include "SubTask.h"

class Task
{
public:
	bool isCompleted;
	bool isImportant;
	DateTime dueDate;
	bool expire;
	std::string notes;
	std::string title;
	RepetitionType repetition;

	void AddSubTask(std::shared_ptr<SubTask> subTask);
	void RemoveSubTask(std::shared_ptr<SubTask> subTask);
	std::shared_ptr<SubTask> GetSubTask(int index);
	std::list<std::shared_ptr<SubTask>> GetSubTasks();
	Task(std::string title);
	~Task();

private:
	std::list<std::shared_ptr<SubTask>> subTasks;
};

