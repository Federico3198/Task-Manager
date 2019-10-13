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

void CreateListDialog::SetFieldListName(QString listName)
{
	ui->filedListName->setText(listName);
}

CreateListDialog::~CreateListDialog()
{
    delete ui;
}
