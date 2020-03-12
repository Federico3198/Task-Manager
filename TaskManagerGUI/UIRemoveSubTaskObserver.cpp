#include "stdafx.h"
#include "UIRemoveSubTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIRemoveSubTaskObserver::UIRemoveSubTaskObserver(TaskManagerMainWindow *mainWindow) : UIObserverEmpty(mainWindow)
{
}

UIRemoveSubTaskObserver::~UIRemoveSubTaskObserver()
{
}

void UIRemoveSubTaskObserver::update()
{
	auto currentSubTaskItem = ui->listWidgetTaskInfo->item(ui->listWidgetTaskInfo->currentRow());
	auto listWidget = mainWindow->GetSelectedTaskList();
	auto currentTaskItem = listWidget->item(listWidget->currentRow());

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