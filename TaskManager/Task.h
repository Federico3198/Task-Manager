#pragma once
#include "DateTime.h"
#include "RepetitionType.cpp"
#include "Comment.h"
#include <string>
#include <list>
#include <queue>
class Task
{
public:
	bool isCompleted;
	bool isImportant;
	DateTime dueDate;
	std::string notes;
	std::string title;
	RepetitionType repetition;

private:
	std::list<std::shared_ptr<Task>> subTasks;
	std::deque<std::shared_ptr<Comment>> comments;

public:
	void AddSubTask(std::shared_ptr<Task> subTask);
	void AddComment(std::shared_ptr<Comment> comment);
	std::shared_ptr<Task> GetSubTask(int index);
	std::shared_ptr<Comment> GetComment(int index);

	Task(std::string title);
	~Task();
};

