#include "stdafx.h"
#include "TaskWidgetItem.h"


TaskWidgetItem::TaskWidgetItem(std::shared_ptr<Task> task)
{
	setText(QString(task->title.c_str()));
	this->task = task;
}

std::shared_ptr<Task> TaskWidgetItem::GetTask()
{
	return task;
}

TaskWidgetItem::~TaskWidgetItem()
{
}
