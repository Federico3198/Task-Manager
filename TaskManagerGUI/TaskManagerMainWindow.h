#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TaskManagerMainWindow.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "ToDoListManager.h"
#include "ToDoList.h"
#include "CreateListDialog.h"
#include "createtaskdialog.h"
#include "CreateSubTaskDialog.h"
#include "ToDoListWidgetItem.h"
#include "TaskWidgetItem.h"
#include "SubTaskWidgetItem.h"
#include "qlist.h"
#include <typeinfo>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>

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
	void on_actionSet_Sub_Task_Completed_triggered();
	void on_actionSet_Sub_Task_Uncompleted_triggered();
	void on_actionModifyList_triggered();
	void on_actionModifyTask_triggered();
	void RefreshImportantList(std::shared_ptr<Task> &task, QListWidget * listWidget, QListWidgetItem * taskListItem);
	void on_actionModify_Sub_Task_triggered();

private:
	boost::property_tree::ptree todoListsRoot;
	std::string filePath = "taskData.json";

	void ShowTaskInfo(QListWidgetItem * taskListItem);
	void SetSubTaskCompleted(bool isCompleted);
	void RefreshUI();
	QListWidget * GetSelectedTaskList();

	Ui::TaskManagerMainWindowClass ui;
	ToDoListManager tdManager;
	const char* important = "Importanti";
};
