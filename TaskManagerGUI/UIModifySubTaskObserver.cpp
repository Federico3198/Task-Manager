#include "stdafx.h"
#include "UIModifySubTaskObserver.h"
#include "TaskManagerMainWindow.h"

UIModifySubTaskObserver::UIModifySubTaskObserver(TaskManagerMainWindow *mainWindow): UIObserverEmpty(mainWindow)
{
}

UIModifySubTaskObserver::~UIModifySubTaskObserver()
{
}

void UIModifySubTaskObserver::update()
{
	auto currentSubTaskItem = ui->listWidgetTaskInfo->item(ui->listWidgetTaskInfo->currentRow());
	auto listWidget = mainWindow->GetSelectedTaskList();
	auto currentTaskItem = listWidget->item(listWidget->currentRow());

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
