#include "stdafx.h"
#include "UISetSubTaskCompletionObserver.h"


UISetSubTaskCompletionObserver::UISetSubTaskCompletionObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UISubTaskObserver(ui, tdManager)
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

		ShowTaskInfo(currentTaskItem);
	}

	tdManager->SaveToJson(filePath);
}
