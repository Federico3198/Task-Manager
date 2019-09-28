#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerMainWindow.h"
#include <iostream>
#include <sstream>
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
	void on_listWidgetUncompletedTasks_itemClicked(QListWidgetItem * listWidgetItem);
	void on_listWidgetCompletedTasks_itemClicked(QListWidgetItem * listWidgetItem);
	void on_actionSet_CompletedTask_triggered();
	void on_actionSet_UncompletedTask_triggered();
	void on_actionAdd_Sub_Task_triggered();
	void on_actionRemove_Sub_Task_triggered();

private:
	void ShowTaskInfo(QListWidgetItem * taskListItem);
	QListWidget * GetSelectedTaskList();

	Ui::TaskManagerMainWindowClass ui;
	ToDoListManager tdManager;
};
