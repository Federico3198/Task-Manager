#pragma once
#include "UIObserverEmpty.h"

class UIRemoveTaskObserver :
	public UIObserverEmpty
{
public:
	UIRemoveTaskObserver(TaskManagerMainWindow *mainWindow);
	~UIRemoveTaskObserver();

	void update() override;
};