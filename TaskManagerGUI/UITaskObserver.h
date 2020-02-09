#pragma once
#include "UIObserver.h"
#include "ToDoListWidgetItem.h"
#include "TaskWidgetItem.h"

class UITaskObserver : 
	public UIObserver
{
public:

	UITaskObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager);
	~UITaskObserver();

protected:

	void RefreshImportantList(std::shared_ptr<Task> &task, QListWidget * listWidget, QListWidgetItem * taskListItem);
};

