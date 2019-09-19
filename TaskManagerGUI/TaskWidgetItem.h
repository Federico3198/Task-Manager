#pragma once
#include <qlistwidget.h>
#include "Task.h"

class TaskWidgetItem :
	public QListWidgetItem
{
public:
	TaskWidgetItem(std::shared_ptr<Task> task);
	std::shared_ptr<Task> GetTask();
	~TaskWidgetItem();

private:
	std::shared_ptr<Task> task;
};

