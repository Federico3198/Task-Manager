#pragma once
#include "UITaskObserver.h"
#include "TaskWidgetItem.h"
#include "CreateTaskDialog.h"

class UIAddTaskObserver :
	public UITaskObserver
{
public:
	UIAddTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIAddTaskObserver();

	//void update(QListWidgetItem *currentItem);
};
