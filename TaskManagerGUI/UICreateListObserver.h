#pragma once
#include "UIObserver.h"
#include "CreateListDialog.h"
#include "ToDoListWidgetItem.h"
#include "ToDoList.h"
class TaskManagerMainWindow;

class UICreateListObserver : 
	public UIObserver
{
public:
	UICreateListObserver(TaskManagerMainWindow *mainWindow);

	virtual void update();
};