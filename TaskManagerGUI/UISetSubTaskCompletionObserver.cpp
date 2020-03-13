#include "stdafx.h"
#include "UISetSubTaskCompletionObserver.h"
#include "TaskManagerMainWindow.h"

UISetSubTaskCompletionObserver::UISetSubTaskCompletionObserver(TaskManagerMainWindow *mainWindow) : UIObserverBool(mainWindow)
{
}

UISetSubTaskCompletionObserver::~UISetSubTaskCompletionObserver()
{
}

void UISetSubTaskCompletionObserver::update(bool isCompleted)
{
	auto currentSubTaskItem = ui->listWidgetTaskInfo->item(ui->listWidgetTaskInfo->currentRow());
	auto listWidget = mainWindow->GetSelectedTaskList();
	auto currentTaskItem = listWidget->item(listWidget->currentRow());

	if (currentTaskItem != NULL && currentSubTaskItem != NULL && typeid(*currentSubTaskItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(currentSubTaskItem);
		auto subTask = subTaskItem->GetSubTask();

		subTask->SetIsCompleted(isCompleted);

		mainWindow->ShowTaskInfo(currentTaskItem);
	}

	tdManager->SaveToJson(mainWindow->filePath);
}
