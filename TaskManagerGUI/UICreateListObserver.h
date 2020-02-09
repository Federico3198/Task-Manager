#pragma once
#include "UIObserver.h"
#include "CreateListDialog.h"
#include "ToDoListWidgetItem.h"

class UICreateListObserver : 
	public UIObserver
{
public:
	UICreateListObserver(Ui_TaskManagerMainWindowClass* ui, ToDoListManager *tdManager);

	virtual void update();
};

