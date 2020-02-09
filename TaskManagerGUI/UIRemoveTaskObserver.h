#pragma once
#include "UIObserver.h"

class UIRemoveTaskObserver :
	public UIObserver
{
public:
	UIRemoveTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIRemoveTaskObserver();
};