#include "stdafx.h"
#include "UIRemoveSubTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIRemoveSubTaskObserver::UIRemoveSubTaskObserver(TaskManagerMainWindow *mainWindow) : UISubTaskObserver(mainWindow)
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

		mainWindow->ShowTaskInfo(currentTaskItem);
		tdManager->SaveToJson(mainWindow->filePath);
	}
}