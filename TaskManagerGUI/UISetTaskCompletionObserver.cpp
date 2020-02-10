#include "stdafx.h"
#include "UISetTaskCompletionObserver.h"

UISetTaskCompletionObserver::UISetTaskCompletionObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager) : UITaskObserver(ui, tdManager)
{
	subTaskObserver = new UISubTaskObserver(ui, tdManager);
}

UISetTaskCompletionObserver::~UISetTaskCompletionObserver()
{
	delete subTaskObserver;
}

void UISetTaskCompletionObserver::update(bool isCompleted)
{
	auto listFrom = isCompleted ? ui->listWidgetUncompletedTasks : ui->listWidgetCompletedTasks;
	auto listTo = isCompleted ? ui->listWidgetCompletedTasks : ui->listWidgetUncompletedTasks;

	if (listFrom->selectedItems().length() > 0)
	{
		auto taskListItem = listFrom->item(listFrom->currentRow());
		if (taskListItem != NULL && typeid(*taskListItem) == typeid(TaskWidgetItem))
		{
			taskListItem = listFrom->takeItem(listFrom->currentRow());
			auto taskItem = static_cast<TaskWidgetItem*>(taskListItem);
			auto task = taskItem->GetTask();
			task->isCompleted = isCompleted;

			listTo->addItem(taskListItem);
			listTo->clearSelection();
			listFrom->clearSelection();
			listTo->setCurrentItem(taskListItem);


			if (ui->listWidgetLists->item(ui->listWidgetLists->currentRow())->text().compare(important) == 0)
			{
				listFrom->clear();
				ui->listWidgetTaskInfo->clear();
			}

			subTaskObserver->ShowTaskInfo(taskListItem);
			RefreshImportantList(task, listTo, taskListItem);

			tdManager->SaveToJson(filePath);
		}
	}
}
