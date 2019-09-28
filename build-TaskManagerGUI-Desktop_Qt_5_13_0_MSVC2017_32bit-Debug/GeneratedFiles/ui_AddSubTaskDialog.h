/********************************************************************************
** Form generated from reading UI file 'AddSubTaskDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUBTASKDIALOG_H
#define UI_ADDSUBTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddSubTaskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *fieldDescription;

    void setupUi(QDialog *AddSubTaskDialog)
    {
        if (AddSubTaskDialog->objectName().isEmpty())
            AddSubTaskDialog->setObjectName(QString::fromUtf8("AddSubTaskDialog"));
        AddSubTaskDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddSubTaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        fieldDescription = new QLineEdit(AddSubTaskDialog);
        fieldDescription->setObjectName(QString::fromUtf8("fieldDescription"));
        fieldDescription->setGeometry(QRect(100, 120, 231, 24));

        retranslateUi(AddSubTaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddSubTaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddSubTaskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddSubTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSubTaskDialog)
    {
        AddSubTaskDialog->setWindowTitle(QCoreApplication::translate("AddSubTaskDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSubTaskDialog: public Ui_AddSubTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUBTASKDIALOG_H
