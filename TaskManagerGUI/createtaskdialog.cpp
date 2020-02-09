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

QCheckBox * CreateTaskDialog::GetCheckExpire()
{
	return ui->checkBoxDueDate;
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

void CreateTaskDialog::SetName(QString name)
{
	ui->fieldName->setText(name);
}

void CreateTaskDialog::SetCheckIsImportant(bool isImportant)
{
	ui->checkIsImportant->setChecked(isImportant);
}

void CreateTaskDialog::SetCheckExpire(bool expire)
{
	ui->checkBoxDueDate->setChecked(expire);
}

void CreateTaskDialog::SetDueDate(DateTime dueDate)
{
	QDate date(dueDate.GetYear(), dueDate.GetMonth(), dueDate.GetDay());
	QTime time(dueDate.GetHours(), dueDate.GetMinutes());

	QDateTime dateTime(date, time);

	ui->dateTimeDueDate->setDateTime(dateTime);
}

void CreateTaskDialog::SetRepetition(RepetitionType repetition)
{
	ui->comboBoxRepetition->setCurrentText(QString(RepetitionTypeUtils::ConvertEnumToIta(repetition).c_str()));
}

void CreateTaskDialog::SetNotes(QString notes)
{
	ui->textNotes->setText(notes);
}

CreateTaskDialog::~CreateTaskDialog()
{
    delete ui;
}
