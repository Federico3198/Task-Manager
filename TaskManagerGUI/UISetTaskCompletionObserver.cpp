#include "stdafx.h"
#include "UISetTaskCompletionObserver.h"
#include "TaskManagerMainWindow.h"

UISetTaskCompletionObserver::UISetTaskCompletionObserver(TaskManagerMainWindow *mainWindow) : UIObserverBool(mainWindow)
{
}

UISetTaskCompletionObserver::~UISetTaskCompletionObserver()
{
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

			auto importantItem = ui->listWidgetLists->item(ui->listWidgetLists->currentRow());
			if (importantItem != NULL && importantItem->text().contains(mainWindow->important))
			{
				listFrom->clear();
				ui->listWidgetTaskInfo->clear();
			}

			mainWindow->ShowTaskInfo(taskListItem);
			mainWindow->RefreshImportantList(task, listTo, taskListItem);

			tdManager->SaveToJson(mainWindow->filePath);
		}
	}

	mainWindow->RefreshUI();
}
