/********************************************************************************
** Form generated from reading UI file 'createtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETASKDIALOG_H
#define UI_CREATETASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CreateTaskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *fieldName;
    QLabel *label;
    QCheckBox *checkIsImportant;
    QDateTimeEdit *dateTimeDueDate;
    QLabel *label_2;
    QTextEdit *textNotes;
    QLabel *label_3;
    QComboBox *comboBoxRepetition;
    QLabel *label_4;

    void setupUi(QDialog *CreateTaskDialog)
    {
        if (CreateTaskDialog->objectName().isEmpty())
            CreateTaskDialog->setObjectName(QString::fromUtf8("CreateTaskDialog"));
        CreateTaskDialog->resize(463, 364);
        buttonBox = new QDialogButtonBox(CreateTaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 320, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        fieldName = new QLineEdit(CreateTaskDialog);
        fieldName->setObjectName(QString::fromUtf8("fieldName"));
        fieldName->setGeometry(QRect(80, 10, 113, 24));
        label = new QLabel(CreateTaskDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 55, 16));
        checkIsImportant = new QCheckBox(CreateTaskDialog);
        checkIsImportant->setObjectName(QString::fromUtf8("checkIsImportant"));
        checkIsImportant->setGeometry(QRect(20, 40, 121, 22));
        dateTimeDueDate = new QDateTimeEdit(CreateTaskDialog);
        dateTimeDueDate->setObjectName(QString::fromUtf8("dateTimeDueDate"));
        dateTimeDueDate->setGeometry(QRect(100, 70, 194, 25));
        label_2 = new QLabel(CreateTaskDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 55, 16));
        textNotes = new QTextEdit(CreateTaskDialog);
        textNotes->setObjectName(QString::fromUtf8("textNotes"));
        textNotes->setGeometry(QRect(20, 190, 421, 121));
        label_3 = new QLabel(CreateTaskDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 160, 61, 16));
        comboBoxRepetition = new QComboBox(CreateTaskDialog);
        comboBoxRepetition->setObjectName(QString::fromUtf8("comboBoxRepetition"));
        comboBoxRepetition->setGeometry(QRect(100, 110, 161, 24));
        comboBoxRepetition->setEditable(false);
        label_4 = new QLabel(CreateTaskDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 110, 55, 16));

        retranslateUi(CreateTaskDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateTaskDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateTaskDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateTaskDialog)
    {
        CreateTaskDialog->setWindowTitle(QCoreApplication::translate("CreateTaskDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CreateTaskDialog", "Nome", nullptr));
        checkIsImportant->setText(QCoreApplication::translate("CreateTaskDialog", "Importante", nullptr));
        label_2->setText(QCoreApplication::translate("CreateTaskDialog", "Scadenza", nullptr));
        label_3->setText(QCoreApplication::translate("CreateTaskDialog", "Note:", nullptr));
        comboBoxRepetition->setCurrentText(QString());
        label_4->setText(QCoreApplication::translate("CreateTaskDialog", "Ripeti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTaskDialog: public Ui_CreateTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETASKDIALOG_H
