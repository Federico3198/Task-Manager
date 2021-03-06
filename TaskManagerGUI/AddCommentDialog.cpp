#include "AddCommentDialog.h"
#include "ui_AddCommentDialog.h"

AddCommentDialog::AddCommentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCommentDialog)
{
    ui->setupUi(this);
}

AddCommentDialog::~AddCommentDialog()
{
    delete ui;
}

QLineEdit * AddCommentDialog::GetOwnerField()
{
	return ui->fieldName;
}

QTextEdit * AddCommentDialog::GetCommentText()
{
	return ui->textEdit;
}
