#include "stdafx.h"
#include "TaskManagerMainWindow.h"

TaskManagerMainWindow::TaskManagerMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    tdManager = ToDoListManager();
}

void TaskManagerMainWindow::on_actionCreateList_triggered()
{
    //TODO chiedere il nome della lista all' utente
    CreateListDialog createListDialog;
    createListDialog.setModal(true);
    int result = createListDialog.exec();

    std::cout <<"fine dialogo"<<std::endl;

    if(result==1)
    {
        auto fieldlistName = createListDialog.GetFieldListName();
        auto listName = fieldlistName->text().toStdString();
        ToDoList td = ToDoList(listName);
        tdManager.toDoLists.push_back(td);
    }
}
