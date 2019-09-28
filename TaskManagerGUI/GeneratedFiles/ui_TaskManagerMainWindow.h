/********************************************************************************
** Form generated from reading UI file 'TaskManagerMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGERMAINWINDOW_H
#define UI_TASKMANAGERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManagerMainWindowClass
{
public:
    QAction *actionCreateList;
    QAction *actionAddTask;
    QAction *actionRemoveTask;
    QAction *actionDeleteList;
    QAction *actionModifyTask;
    QAction *actionModifyList;
    QAction *actionSet_CompletedTask;
    QAction *actionAdd_Sub_Task;
    QAction *actionRemove_Sub_Task;
    QAction *actionSet_Sub_Task_Completed;
    QAction *actionSet_Sub_Task_Uncompleted;
    QAction *actionSet_UncompletedTask;
    QWidget *centralWidget;
    QListWidget *listWidgetLists;
    QListWidget *listWidgetUncompletedTasks;
    QListWidget *listWidgetTaskInfo;
    QListWidget *listWidgetCompletedTasks;
    QMenuBar *menuBar;
    QMenu *menuLista;
    QMenu *menuTask;
    QMenu *menuTask_Info;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaskManagerMainWindowClass)
    {
        if (TaskManagerMainWindowClass->objectName().isEmpty())
            TaskManagerMainWindowClass->setObjectName(QString::fromUtf8("TaskManagerMainWindowClass"));
        TaskManagerMainWindowClass->resize(1002, 714);
        actionCreateList = new QAction(TaskManagerMainWindowClass);
        actionCreateList->setObjectName(QString::fromUtf8("actionCreateList"));
        actionAddTask = new QAction(TaskManagerMainWindowClass);
        actionAddTask->setObjectName(QString::fromUtf8("actionAddTask"));
        actionRemoveTask = new QAction(TaskManagerMainWindowClass);
        actionRemoveTask->setObjectName(QString::fromUtf8("actionRemoveTask"));
        actionDeleteList = new QAction(TaskManagerMainWindowClass);
        actionDeleteList->setObjectName(QString::fromUtf8("actionDeleteList"));
        actionModifyTask = new QAction(TaskManagerMainWindowClass);
        actionModifyTask->setObjectName(QString::fromUtf8("actionModifyTask"));
        actionModifyList = new QAction(TaskManagerMainWindowClass);
        actionModifyList->setObjectName(QString::fromUtf8("actionModifyList"));
        actionSet_CompletedTask = new QAction(TaskManagerMainWindowClass);
        actionSet_CompletedTask->setObjectName(QString::fromUtf8("actionSet_CompletedTask"));
        actionAdd_Sub_Task = new QAction(TaskManagerMainWindowClass);
        actionAdd_Sub_Task->setObjectName(QString::fromUtf8("actionAdd_Sub_Task"));
        actionRemove_Sub_Task = new QAction(TaskManagerMainWindowClass);
        actionRemove_Sub_Task->setObjectName(QString::fromUtf8("actionRemove_Sub_Task"));
        actionSet_Sub_Task_Completed = new QAction(TaskManagerMainWindowClass);
        actionSet_Sub_Task_Completed->setObjectName(QString::fromUtf8("actionSet_Sub_Task_Completed"));
        actionSet_Sub_Task_Uncompleted = new QAction(TaskManagerMainWindowClass);
        actionSet_Sub_Task_Uncompleted->setObjectName(QString::fromUtf8("actionSet_Sub_Task_Uncompleted"));
        actionSet_UncompletedTask = new QAction(TaskManagerMainWindowClass);
        actionSet_UncompletedTask->setObjectName(QString::fromUtf8("actionSet_UncompletedTask"));
        centralWidget = new QWidget(TaskManagerMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidgetLists = new QListWidget(centralWidget);
        listWidgetLists->setObjectName(QString::fromUtf8("listWidgetLists"));
        listWidgetLists->setGeometry(QRect(40, 20, 256, 461));
        listWidgetUncompletedTasks = new QListWidget(centralWidget);
        listWidgetUncompletedTasks->setObjectName(QString::fromUtf8("listWidgetUncompletedTasks"));
        listWidgetUncompletedTasks->setGeometry(QRect(350, 20, 256, 221));
        listWidgetTaskInfo = new QListWidget(centralWidget);
        listWidgetTaskInfo->setObjectName(QString::fromUtf8("listWidgetTaskInfo"));
        listWidgetTaskInfo->setGeometry(QRect(660, 20, 256, 451));
        listWidgetCompletedTasks = new QListWidget(centralWidget);
        listWidgetCompletedTasks->setObjectName(QString::fromUtf8("listWidgetCompletedTasks"));
        listWidgetCompletedTasks->setGeometry(QRect(350, 270, 256, 211));
        TaskManagerMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1002, 25));
        menuLista = new QMenu(menuBar);
        menuLista->setObjectName(QString::fromUtf8("menuLista"));
        menuTask = new QMenu(menuBar);
        menuTask->setObjectName(QString::fromUtf8("menuTask"));
        menuTask_Info = new QMenu(menuBar);
        menuTask_Info->setObjectName(QString::fromUtf8("menuTask_Info"));
        TaskManagerMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerMainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuLista->menuAction());
        menuBar->addAction(menuTask->menuAction());
        menuBar->addAction(menuTask_Info->menuAction());
        menuLista->addAction(actionCreateList);
        menuLista->addAction(actionDeleteList);
        menuLista->addAction(actionModifyList);
        menuTask->addAction(actionAddTask);
        menuTask->addAction(actionRemoveTask);
        menuTask->addAction(actionModifyTask);
        menuTask->addAction(actionSet_CompletedTask);
        menuTask->addAction(actionSet_UncompletedTask);
        menuTask_Info->addAction(actionAdd_Sub_Task);
        menuTask_Info->addAction(actionRemove_Sub_Task);
        menuTask_Info->addAction(actionSet_Sub_Task_Completed);
        menuTask_Info->addAction(actionSet_Sub_Task_Uncompleted);

        retranslateUi(TaskManagerMainWindowClass);

        QMetaObject::connectSlotsByName(TaskManagerMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerMainWindowClass)
    {
        TaskManagerMainWindowClass->setWindowTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "TaskManagerMainWindow", nullptr));
        actionCreateList->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Create", nullptr));
        actionAddTask->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Add", nullptr));
        actionRemoveTask->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Remove", nullptr));
        actionDeleteList->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Delete", nullptr));
        actionModifyTask->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Modify", nullptr));
        actionModifyList->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Modify", nullptr));
        actionSet_CompletedTask->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Set Completed", nullptr));
        actionAdd_Sub_Task->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Add Sub Task", nullptr));
        actionRemove_Sub_Task->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Remove Sub Task", nullptr));
        actionSet_Sub_Task_Completed->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Set Sub Task Completed", nullptr));
        actionSet_Sub_Task_Uncompleted->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Set Sub Task Uncompleted", nullptr));
        actionSet_UncompletedTask->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Set Uncompleted", nullptr));
        menuLista->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "List", nullptr));
        menuTask->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "Task", nullptr));
        menuTask_Info->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "Task Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerMainWindowClass: public Ui_TaskManagerMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGERMAINWINDOW_H
