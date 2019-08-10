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
	std::list<Task> subTasks;
	std::deque<Comment> comments;
public:
	void AddSubTask(Task subTask);
	void AddComment(Comment comment);
	Task GetSubTask(int index);
	Comment GetComment(int index);
	
	Task();

	~Task();
};

