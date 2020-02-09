#include "stdafx.h"
#include "UIModifySubTaskObserver.h"


UIModifySubTaskObserver::UIModifySubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager): UISubTaskObserver(ui,tdManager)
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

			tdManager->SaveToJson(filePath);
		}
		ShowTaskInfo(currentTaskItem);
	}
}
