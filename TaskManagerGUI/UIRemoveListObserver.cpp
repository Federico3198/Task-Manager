#include "stdafx.h"
#include "UIRemoveListObserver.h"
#include "TaskManagerMainWindow.h"

void UIRemoveListObserver::update(QListWidgetItem * currentItem)
{
	if (currentItem != NULL && !currentItem->text().contains(mainWindow->important))
	{
		currentItem = ui->listWidgetLists->takeItem(ui->listWidgetLists->currentRow());
		auto listItem = static_cast<ToDoListWidgetItem*>(currentItem);

		int listId = listItem->GetListId();

		tdManager->RemoveList(listId);
		delete currentItem;

		if (tdManager->GetToDoLists().size() == 0)
		{
			ui->listWidgetCompletedTasks->clear();
			ui->listWidgetUncompletedTasks->clear();
			ui->listWidgetTaskInfo->clear();
		}
		tdManager->SaveToJson(mainWindow->filePath);
	}

}


UIRemoveListObserver::UIRemoveListObserver(TaskManagerMainWindow *mainWindow) : UIObserverListItem(mainWindow) {}

UIRemoveListObserver::~UIRemoveListObserver()
{
}
