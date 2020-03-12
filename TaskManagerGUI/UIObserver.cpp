#include "stdafx.h"
#include "UIObserver.h"
#include "TaskManagerMainWindow.h"

UIObserver::UIObserver(TaskManagerMainWindow *mainWindow)
{
	this->mainWindow = mainWindow;
	this->ui = mainWindow->GetUI();
	this->tdManager = mainWindow->GetTdManager();
}
