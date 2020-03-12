#pragma once
#include "UIObserverEmpty.h"
#include "CreateListDialog.h"
#include "ToDoListWidgetItem.h"
#include "ToDoList.h"

class TaskManagerMainWindow;

class UICreateListObserver : 
	public UIObserverEmpty
{
public:
	UICreateListObserver(TaskManagerMainWindow *mainWindow);

	void update() override;
};