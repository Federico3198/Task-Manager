#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"
#include "TaskWidgetItem.h"

class UITaskObserver : 
	public UIObserver
{
public:

	UITaskObserver(TaskManagerMainWindow *mainWindow);
	~UITaskObserver();
};