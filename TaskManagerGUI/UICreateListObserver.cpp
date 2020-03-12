#include "stdafx.h"
#include "UICreateListObserver.h"
#include "TaskManagerMainWindow.h"

UICreateListObserver::UICreateListObserver(TaskManagerMainWindow *mainWindow): UIObserver(mainWindow)
{
}

void UICreateListObserver::update()
{
	CreateListDialog createListDialog;
	createListDialog.setModal(true);
	int result = createListDialog.exec();

	if (result == 1)
	{
		auto fieldlistName = createListDialog.GetFieldListName();
		auto listName = fieldlistName->text();
		std::shared_ptr<ToDoList> sharedTDL(new ToDoList(listName.toStdString()));
		tdManager->AddList(sharedTDL);

		auto listItem = new ToDoListWidgetItem(listName, sharedTDL->GetId());

		ui->listWidgetLists->addItem(listItem);

		tdManager->SaveToJson(mainWindow->filePath);
	}
}
