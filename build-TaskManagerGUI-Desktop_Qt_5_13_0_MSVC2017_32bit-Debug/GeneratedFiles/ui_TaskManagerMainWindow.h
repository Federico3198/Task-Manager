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
    QWidget *centralWidget;
    QListWidget *listWidgetLists;
    QListWidget *listWidgetTasks;
    QListWidget *listWidgetTaskInfo;
    QMenuBar *menuBar;
    QMenu *menuLista;
    QMenu *menuTask;
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
        centralWidget = new QWidget(TaskManagerMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listWidgetLists = new QListWidget(centralWidget);
        listWidgetLists->setObjectName(QString::fromUtf8("listWidgetLists"));
        listWidgetLists->setGeometry(QRect(40, 20, 256, 461));
        listWidgetTasks = new QListWidget(centralWidget);
        listWidgetTasks->setObjectName(QString::fromUtf8("listWidgetTasks"));
        listWidgetTasks->setGeometry(QRect(350, 20, 256, 451));
        listWidgetTaskInfo = new QListWidget(centralWidget);
        listWidgetTaskInfo->setObjectName(QString::fromUtf8("listWidgetTaskInfo"));
        listWidgetTaskInfo->setGeometry(QRect(660, 20, 256, 451));
        TaskManagerMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1002, 25));
        menuLista = new QMenu(menuBar);
        menuLista->setObjectName(QString::fromUtf8("menuLista"));
        menuTask = new QMenu(menuBar);
        menuTask->setObjectName(QString::fromUtf8("menuTask"));
        TaskManagerMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerMainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuLista->menuAction());
        menuBar->addAction(menuTask->menuAction());
        menuLista->addAction(actionCreateList);
        menuLista->addAction(actionDeleteList);
        menuTask->addAction(actionAddTask);
        menuTask->addAction(actionRemoveTask);

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
        menuLista->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "List", nullptr));
        menuTask->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "Task", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerMainWindowClass: public Ui_TaskManagerMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGERMAINWINDOW_H
