#include "CreateListDialog.h"
#include "ui_CreateListDialog.h"

CreateListDialog::CreateListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateListDialog)
{
    ui->setupUi(this);
}

QLineEdit * CreateListDialog::GetFieldListName()
{
    return ui->filedListName;
}

CreateListDialog::~CreateListDialog()
{
    delete ui;
}
