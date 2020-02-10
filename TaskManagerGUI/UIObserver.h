#pragma once
#include "ui_TaskManagerMainWindow.h"
#include "ToDoListManager.h"

class UIObserver
{
public:
	UIObserver(Ui_TaskManagerMainWindowClass* ui, ToDoListManager *tdManager);

protected:
	Ui_TaskManagerMainWindowClass* ui;
	ToDoListManager *tdManager;
	const std::string filePath = "taskData.json";
	const char* important = "Importanti";
};