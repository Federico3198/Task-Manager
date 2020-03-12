#pragma once
#include "UITaskObserver.h"
#include "UISubTaskObserver.h"

class UISetTaskCompletionObserver :
	public UITaskObserver
{
public:
	UISubTaskObserver *subTaskObserver;
	UISetTaskCompletionObserver(TaskManagerMainWindow *mainWindow);
	~UISetTaskCompletionObserver();

	void update(bool isCompleted);
};