#pragma once
#include "UITaskObserver.h"
#include "UISubTaskObserver.h"

class UISetTaskCompletionObserver :
	public UITaskObserver
{
public:
	UISubTaskObserver *subTaskObserver;
	UISetTaskCompletionObserver(Ui_TaskManagerMainWindowClass *ui, ToDoListManager *tdManager);
	~UISetTaskCompletionObserver();

	void update(bool isCompleted);
};