#pragma once
#include "UIObserverBool.h"

class UISetSubTaskCompletionObserver :
	public UIObserverBool
{
public:
	UISetSubTaskCompletionObserver(TaskManagerMainWindow *mainWindow);
	~UISetSubTaskCompletionObserver();

	void update(bool isCompleted) override;
};