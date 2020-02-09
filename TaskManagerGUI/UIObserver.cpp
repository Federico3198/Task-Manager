#include "stdafx.h"
#include "UIObserver.h"


UIObserver::UIObserver(Ui_TaskManagerMainWindowClass* ui, ToDoListManager *tdManager)
{
	this->ui = ui;
	this->tdManager = tdManager;
}
