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

void CreateSubTaskDialog::SetText(QString text)
{
	ui->lblText->setText(text);
}

CreateSubTaskDialog::~CreateSubTaskDialog()
{
    delete ui;
}


