#include "stdafx.h"
#include "UIModifySubTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIModifySubTaskObserver::UIModifySubTaskObserver(TaskManagerMainWindow *mainWindow): UISubTaskObserver(mainWindow)
{
}

UIModifySubTaskObserver::~UIModifySubTaskObserver()
{
}

void UIModifySubTaskObserver::update(QListWidgetItem * currentTaskItem, QListWidgetItem * currentSubTaskItem)
{
	if (currentTaskItem != NULL && currentSubTaskItem != NULL && typeid(*currentSubTaskItem) == typeid(SubTaskWidgetItem))
	{
		auto subTaskItem = static_cast<SubTaskWidgetItem *>(currentSubTaskItem);
		auto subTask = subTaskItem->GetSubTask();

		CreateSubTaskDialog createSubTaskDialog;
		createSubTaskDialog.setModal(true);
		createSubTaskDialog.SetText(QString(subTask->GetText().c_str()));

		int result = createSubTaskDialog.exec();

		if (result == 1)
		{
			auto text = createSubTaskDialog.GetText()->text().toStdString();

			subTask->SetText(text);

			tdManager->SaveToJson(mainWindow->filePath);
		}
		mainWindow->ShowTaskInfo(currentTaskItem);
	}
}
