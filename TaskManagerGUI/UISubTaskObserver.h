#pragma once
#include "UIObserver.h"
#include "TaskWidgetItem.h"
#include "SubTaskWidgetItem.h"
#include "CommentWidgetItem.h"
class UISubTaskObserver :
	public UIObserver
{
public:
	UISubTaskObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UISubTaskObserver();

	void ShowTaskInfo(QListWidgetItem *taskListItem);
};

