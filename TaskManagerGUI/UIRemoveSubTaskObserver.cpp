#include "stdafx.h"
#include "UIRemoveSubTaskObserver.h"


UIRemoveSubTaskObserver::UIRemoveSubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UISubTaskObserver(ui,tdManager)
{
}


UIRemoveSubTaskObserver::~UIRemoveSubTaskObserver()
{
}

void UIRemoveSubTaskObserver::update(QListWidgetItem * currentTaskItem, QListWidgetItem *currentSubTaskItem)
{
	if (currentTaskItem != NULL && currentSubTaskItem != NULL && typeid(*currentSubTaskItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(currentSubTaskItem);
		auto subTask = subTaskItem->GetSubTask();

		auto taskItem = static_cast<TaskWidgetItem*>(currentTaskItem);
		auto task = taskItem->GetTask();

		task->RemoveSubTask(subTask);

		ShowTaskInfo(currentTaskItem);
		tdManager->SaveToJson(filePath);
	}
}