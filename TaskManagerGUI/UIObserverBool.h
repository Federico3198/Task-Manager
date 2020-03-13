#pragma once
#include "UIObserver.h"
class UIObserverBool :
	public UIObserver
{
public:
	UIObserverBool(TaskManagerMainWindow *mainWindow);
	~UIObserverBool();
	void virtual update(bool boolValue) {}
};

