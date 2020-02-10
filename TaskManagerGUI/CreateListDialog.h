#ifndef CREATELISTDIALOG_H
#define CREATELISTDIALOG_H
#include <QDialog>

namespace Ui {
class CreateListDialog;
}

class CreateListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateListDialog(QWidget *parent = nullptr);
    ~CreateListDialog();
    QLineEdit * GetFieldListName();
	void SetFieldListName(QString listName);

private:
    Ui::CreateListDialog *ui;
};

#endif // CREATELISTDIALOG_H
