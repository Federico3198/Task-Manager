/********************************************************************************
** Form generated from reading UI file 'CreateSubTaskDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESUBTASKDIALOG_H
#define UI_CREATESUBTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateSubTaskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lblText;
    QLabel *label;

    void setupUi(QDialog *CreateSubTaskDialog)
    {
        if (CreateSubTaskDialog->objectName().isEmpty())
            CreateSubTaskDialog->setObjectName(QString::fromUtf8("CreateSubTaskDialog"));
        CreateSubTaskDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateSubTaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        lblText = new QLineEdit(CreateSubTaskDialog);
        lblText->setObjectName(QString::fromUtf8("lblText"));
        lblText->setGeometry(QRect(110, 130, 241, 24));
        label = new QLabel(CreateSubTaskDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 130, 55, 16));

        retranslateUi(CreateSubTaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateSubTaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateSubTaskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateSubTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateSubTaskDialog)
    {
        CreateSubTaskDialog->setWindowTitle(QCoreApplication::translate("CreateSubTaskDialog", "Crea Sotto-Task", nullptr));
        label->setText(QCoreApplication::translate("CreateSubTaskDialog", "Nome:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateSubTaskDialog: public Ui_CreateSubTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESUBTASKDIALOG_H
