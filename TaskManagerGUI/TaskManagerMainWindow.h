#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerMainWindow.h"
#include <iostream>
#include "ToDoListManager.h"
#include "ToDoList.h"
#include "CreateListDialog.h"
#include "createtaskdialog.h"
#include "ToDoListWidgetItem.h"
#include "TaskWidgetItem.h"
#include "qlist.h"


class TaskManagerMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	TaskManagerMainWindow(QWidget *parent = Q_NULLPTR);

private slots:
    void on_actionCreateList_triggered();
    void on_actionDeleteList_triggered();
    void on_listWidgetLists_currentRowChanged(int currentRow);
	void on_actionAddTask_triggered();
	void on_actionRemoveTask_triggered();

private:
	Ui::TaskManagerMainWindowClass ui;
	ToDoListManager tdManager;
};
