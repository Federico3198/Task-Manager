#include "stdafx.h"
#include "UIAddSubTaskObserver.h"


UIAddSubTaskObserver::UIAddSubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager) : UISubTaskObserver(ui, tdManager)
{
}


UIAddSubTaskObserver::~UIAddSubTaskObserver()
{
}

void UIAddSubTaskObserver::update(QListWidgetItem * currentItem)
{
	if (currentItem != NULL && typeid(*currentItem) == typeid(TaskWidgetItem))
	{
		auto taskItem = static_cast<TaskWidgetItem*>(currentItem);
		auto task = taskItem->GetTask();

		CreateSubTaskDialog createSubTaskDialog;
		createSubTaskDialog.setModal(true);
		int result = createSubTaskDialog.exec();

		if (result == 1)
		{
			auto text = createSubTaskDialog.GetText()->text().toStdString();

			SubTask* subTask;
			subTask = new SubTask(text);
			task->AddSubTask(std::shared_ptr<SubTask>(subTask));
			ShowTaskInfo(currentItem);

			tdManager->SaveToJson(filePath);
		}
	}
}
