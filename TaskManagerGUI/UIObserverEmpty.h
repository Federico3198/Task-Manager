#pragma once
#include "UIObserver.h"

class UIObserverEmpty :
	public UIObserver
{
public:
	UIObserverEmpty(TaskManagerMainWindow *mainWindow);
	~UIObserverEmpty();
	virtual void update() {}
};

