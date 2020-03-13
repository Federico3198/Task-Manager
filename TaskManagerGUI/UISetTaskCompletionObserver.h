#pragma once
#include "UIObserverBool.h"

class UISetTaskCompletionObserver :
	public UIObserverBool
{
public:
	UISetTaskCompletionObserver(TaskManagerMainWindow *mainWindow);
	~UISetTaskCompletionObserver();

	void update(bool isCompleted) override;
};