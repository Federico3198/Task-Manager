#include "stdafx.h"
#include "UISetSubTaskCompletionObserver.h"
#include "TaskManagerMainWindow.h"

UISetSubTaskCompletionObserver::UISetSubTaskCompletionObserver(TaskManagerMainWindow *mainWindow) : UISubTaskObserver(mainWindow)
{
}

UISetSubTaskCompletionObserver::~UISetSubTaskCompletionObserver()
{
}

void UISetSubTaskCompletionObserver::update(QListWidgetItem *currentTaskItem, QListWidgetItem *currentSubTaskItem, bool isCompleted)
{
	if (currentTaskItem != NULL && currentSubTaskItem != NULL && typeid(*currentSubTaskItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(currentSubTaskItem);
		auto subTask = subTaskItem->GetSubTask();

		subTask->SetIsCompleted(isCompleted);

		mainWindow->ShowTaskInfo(currentTaskItem);
	}

	tdManager->SaveToJson(mainWindow->filePath);
}
