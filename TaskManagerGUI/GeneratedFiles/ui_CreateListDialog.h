/********************************************************************************
** Form generated from reading UI file 'CreateListDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATELISTDIALOG_H
#define UI_CREATELISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateListDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *filedListName;

    void setupUi(QDialog *CreateListDialog)
    {
        if (CreateListDialog->objectName().isEmpty())
            CreateListDialog->setObjectName(QString::fromUtf8("CreateListDialog"));
        CreateListDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateListDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        filedListName = new QLineEdit(CreateListDialog);
        filedListName->setObjectName(QString::fromUtf8("filedListName"));
        filedListName->setGeometry(QRect(130, 100, 113, 24));

        retranslateUi(CreateListDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateListDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateListDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateListDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateListDialog)
    {
        CreateListDialog->setWindowTitle(QCoreApplication::translate("CreateListDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateListDialog: public Ui_CreateListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATELISTDIALOG_H
