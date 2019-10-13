#ifndef CREATETASKDIALOG_H
#define CREATETASKDIALOG_H

#include <QDialog>
#include "DateTime.h"
#include "TaskManagerMainWindow.h"
namespace Ui {
class CreateTaskDialog;
}

class CreateTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateTaskDialog(QWidget *parent = nullptr);
	QLineEdit* GetName();
	QCheckBox* GetCheckIsImportant();
	QCheckBox* GetCheckExpire();
	QDateTimeEdit* GetDueDate();
	QComboBox* GetRepetition();
	QTextEdit* GetNotes();

	void SetName(QString name);
	void SetCheckIsImportant(bool isImportant);
	void SetCheckExpire(bool expire);
	void SetDueDate(DateTime dueDate);
	void SetRepetition(RepetitionType repetition);
	void SetNotes(QString notes);

	~CreateTaskDialog();

private:
    Ui::CreateTaskDialog *ui;
};

#endif // CREATETASKDIALOG_H
