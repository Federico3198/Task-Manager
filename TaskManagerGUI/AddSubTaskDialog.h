#ifndef ADDSUBTASKDIALOG_H
#define ADDSUBTASKDIALOG_H

#include <QDialog>

namespace Ui {
class AddSubTaskDialog;
}

class AddSubTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSubTaskDialog(QWidget *parent = nullptr);
    ~AddSubTaskDialog();

private:
    Ui::AddSubTaskDialog *ui;
};

#endif // ADDSUBTASKDIALOG_H
