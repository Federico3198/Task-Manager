#include "createtaskdialog.h"
#include "ui_createtaskdialog.h"

CreateTaskDialog::CreateTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTaskDialog)
{
    ui->setupUi(this);
	ui->comboBoxRepetition->addItem(QString("Nessuna"));
	ui->comboBoxRepetition->addItem(QString("Giornaliero"));
	ui->comboBoxRepetition->addItem(QString("Settimanale"));
	ui->comboBoxRepetition->addItem(QString("Mensile"));
	ui->comboBoxRepetition->addItem(QString("Annuale"));
}

QLineEdit * CreateTaskDialog::GetName()
{
	return ui->fieldName;
}

QCheckBox *CreateTaskDialog::GetCheckIsImportant()
{
	return ui->checkIsImportant;
}

QDateTimeEdit *CreateTaskDialog::GetDueDate()
{
	return ui->dateTimeDueDate;
}

QComboBox* CreateTaskDialog::GetRepetition()
{
	return ui->comboBoxRepetition;
}

QTextEdit* CreateTaskDialog::GetNotes()
{
	return ui->textNotes;
}

CreateTaskDialog::~CreateTaskDialog()
{
    delete ui;
}
