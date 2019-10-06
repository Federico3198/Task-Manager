#include "stdafx.h"
#include "SubTaskWidgetItem.h"

SubTaskWidgetItem::SubTaskWidgetItem(std::shared_ptr<SubTask> subTask)
{
	std::string completedChar = subTask->GetIsCompleted() ? "(X)" : "( )";

	auto stringStream = std::stringstream();
	stringStream << completedChar << ": " << subTask->GetText();
	
	setText(QString(stringStream.str().c_str()));
	this->subTask = subTask;
}

std::shared_ptr<SubTask> SubTaskWidgetItem::GetSubTask()
{
	return subTask;
}

SubTaskWidgetItem::~SubTaskWidgetItem()
{
}
