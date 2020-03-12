#pragma once
#include "ui_TaskManagerMainWindow.h"
#include "ToDoListManager.h"

class TaskManagerMainWindow;

class UIObserver
{
public:
	UIObserver(TaskManagerMainWindow *mainWindow);

protected:
	Ui_TaskManagerMainWindowClass* ui;
	ToDoListManager *tdManager;
	TaskManagerMainWindow *mainWindow;
};