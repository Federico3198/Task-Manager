/********************************************************************************
** Form generated from reading UI file 'AddCommentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMMENTDIALOG_H
#define UI_ADDCOMMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddCommentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *fieldName;
    QLabel *label_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *AddCommentDialog)
    {
        if (AddCommentDialog->objectName().isEmpty())
            AddCommentDialog->setObjectName(QString::fromUtf8("AddCommentDialog"));
        AddCommentDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddCommentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(40, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddCommentDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 121, 16));
        fieldName = new QLineEdit(AddCommentDialog);
        fieldName->setObjectName(QString::fromUtf8("fieldName"));
        fieldName->setGeometry(QRect(170, 40, 113, 24));
        label_2 = new QLabel(AddCommentDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 131, 16));
        textEdit = new QTextEdit(AddCommentDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 120, 351, 121));

        retranslateUi(AddCommentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddCommentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddCommentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddCommentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddCommentDialog)
    {
        AddCommentDialog->setWindowTitle(QCoreApplication::translate("AddCommentDialog", "Aggiungi Commento", nullptr));
        label->setText(QCoreApplication::translate("AddCommentDialog", "Inserisci il tuo nome:", nullptr));
        label_2->setText(QCoreApplication::translate("AddCommentDialog", "Inserisci il commento:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddCommentDialog: public Ui_AddCommentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMMENTDIALOG_H
