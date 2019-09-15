#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerMainWindow.h"
#include <iostream>
#include "ToDoListManager.h"
#include "ToDoList.h"

class TaskManagerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	TaskManagerMainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_actionCreateList_triggered();

private:
	Ui::TaskManagerMainWindowClass ui;
	ToDoListManager tdManager;
};
