#ifndef CREATETASKDIALOG_H
#define CREATETASKDIALOG_H

#include <QDialog>

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
	QDateTimeEdit* GetDueDate();
	QComboBox* GetRepetition();
	QTextEdit* GetNotes();
	~CreateTaskDialog();

private:
    Ui::CreateTaskDialog *ui;
};

#endif // CREATETASKDIALOG_H
