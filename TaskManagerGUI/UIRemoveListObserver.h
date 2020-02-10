#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"

class UIRemoveListObserver :
	public UIObserver
{
public:

	void update(QListWidgetItem *currentItem);

	UIRemoveListObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager);
	~UIRemoveListObserver();
};