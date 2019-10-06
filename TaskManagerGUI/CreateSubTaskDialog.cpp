#include "CreateSubTaskDialog.h"
#include "ui_CreateSubTaskDialog.h"

CreateSubTaskDialog::CreateSubTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateSubTaskDialog)
{
    ui->setupUi(this);
}

QLineEdit * CreateSubTaskDialog::GetText()
{
	return ui->lblText;
}

CreateSubTaskDialog::~CreateSubTaskDialog()
{
    delete ui;
}


