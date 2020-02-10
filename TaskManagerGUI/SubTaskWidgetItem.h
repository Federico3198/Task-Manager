#pragma once
#include <qlistwidget.h>
#include "SubTask.h"
#include <sstream>

class SubTaskWidgetItem :
	public QListWidgetItem
{
public:
	SubTaskWidgetItem(std::shared_ptr<SubTask> subTask);
	std::shared_ptr<SubTask> GetSubTask();
	~SubTaskWidgetItem();

private:
	std::shared_ptr<SubTask> subTask;
};