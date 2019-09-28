#include "AddSubTaskDialog.h"
#include "ui_AddSubTaskDialog.h"

AddSubTaskDialog::AddSubTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSubTaskDialog)
{
    ui->setupUi(this);
}

AddSubTaskDialog::~AddSubTaskDialog()
{
    delete ui;
}
