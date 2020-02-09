#pragma once
#include "UISubTaskObserver.h"
class UISetSubTaskCompletionObserver :
	public UISubTaskObserver
{
public:
	UISetSubTaskCompletionObserver(Ui_TaskManagerMainWindowClass * ui, ToDoListManager * tdManager);
	~UISetSubTaskCompletionObserver();

	void update(QListWidgetItem *currentTaskItem, QListWidgetItem *currentSubTaskItem, bool isCompleted);
};

