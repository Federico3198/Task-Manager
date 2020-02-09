#pragma once
#include "UISubTaskObserver.h"
#include "CreateSubTaskDialog.h"

class UIAddSubTaskObserver :
	public UISubTaskObserver
{
public:
	UIAddSubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIAddSubTaskObserver();

	void update(QListWidgetItem *currentItem);
};

