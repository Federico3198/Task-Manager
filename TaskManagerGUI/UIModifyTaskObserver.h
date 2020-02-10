#pragma once
#include "UITaskObserver.h"
#include "createtaskdialog.h"
#include "UISubTaskObserver.h"

class UIModifyTaskObserver :
	public UITaskObserver
{
public:
	UISubTaskObserver *subTaskObserver;
	UIModifyTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UIModifyTaskObserver();

	void update(QListWidgetItem *currentItem, QListWidget *currentList);
};