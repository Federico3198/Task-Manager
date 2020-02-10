#ifndef CREATESUBTASKDIALOG_H
#define CREATESUBTASKDIALOG_H
#include <QDialog>

namespace Ui {
class CreateSubTaskDialog;
}

class CreateSubTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateSubTaskDialog(QWidget *parent = nullptr);
	QLineEdit * GetText();
	void SetText(QString text);
    ~CreateSubTaskDialog();

private:
    Ui::CreateSubTaskDialog *ui;
};

#endif // CREATESUBTASKDIALOG_H
