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
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuLista;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TaskManagerMainWindowClass)
    {
        if (TaskManagerMainWindowClass->objectName().isEmpty())
            TaskManagerMainWindowClass->setObjectName(QString::fromUtf8("TaskManagerMainWindowClass"));
        TaskManagerMainWindowClass->resize(1002, 714);
        actionCreateList = new QAction(TaskManagerMainWindowClass);
        actionCreateList->setObjectName(QString::fromUtf8("actionCreateList"));
        centralWidget = new QWidget(TaskManagerMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TaskManagerMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TaskManagerMainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1002, 25));
        menuLista = new QMenu(menuBar);
        menuLista->setObjectName(QString::fromUtf8("menuLista"));
        TaskManagerMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TaskManagerMainWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TaskManagerMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TaskManagerMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TaskManagerMainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuLista->menuAction());
        menuLista->addAction(actionCreateList);

        retranslateUi(TaskManagerMainWindowClass);

        QMetaObject::connectSlotsByName(TaskManagerMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TaskManagerMainWindowClass)
    {
        TaskManagerMainWindowClass->setWindowTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "TaskManagerMainWindow", nullptr));
        actionCreateList->setText(QCoreApplication::translate("TaskManagerMainWindowClass", "Create", nullptr));
        menuLista->setTitle(QCoreApplication::translate("TaskManagerMainWindowClass", "List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskManagerMainWindowClass: public Ui_TaskManagerMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGERMAINWINDOW_H
