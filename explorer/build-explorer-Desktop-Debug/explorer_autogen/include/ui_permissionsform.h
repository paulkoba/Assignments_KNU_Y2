/********************************************************************************
** Form generated from reading UI file 'permissionsform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERMISSIONSFORM_H
#define UI_PERMISSIONSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PermissionsForm
{
public:
    QGroupBox *groupBox;
    QComboBox *accessCombo;
    QComboBox *modifyCombo;
    QComboBox *executeCombo;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *location;

    void setupUi(QWidget *PermissionsForm)
    {
        if (PermissionsForm->objectName().isEmpty())
            PermissionsForm->setObjectName(QString::fromUtf8("PermissionsForm"));
        PermissionsForm->resize(400, 300);
        PermissionsForm->setMinimumSize(QSize(400, 300));
        PermissionsForm->setMaximumSize(QSize(400, 300));
        groupBox = new QGroupBox(PermissionsForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 130, 381, 161));
        accessCombo = new QComboBox(groupBox);
        accessCombo->addItem(QString());
        accessCombo->addItem(QString());
        accessCombo->addItem(QString());
        accessCombo->addItem(QString());
        accessCombo->setObjectName(QString::fromUtf8("accessCombo"));
        accessCombo->setGeometry(QRect(240, 50, 72, 22));
        modifyCombo = new QComboBox(groupBox);
        modifyCombo->addItem(QString());
        modifyCombo->addItem(QString());
        modifyCombo->addItem(QString());
        modifyCombo->addItem(QString());
        modifyCombo->setObjectName(QString::fromUtf8("modifyCombo"));
        modifyCombo->setGeometry(QRect(240, 80, 72, 22));
        executeCombo = new QComboBox(groupBox);
        executeCombo->addItem(QString());
        executeCombo->addItem(QString());
        executeCombo->addItem(QString());
        executeCombo->addItem(QString());
        executeCombo->setObjectName(QString::fromUtf8("executeCombo"));
        executeCombo->setGeometry(QRect(240, 110, 72, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 50, 181, 21));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 80, 181, 21));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 110, 181, 21));
        label_4->setAlignment(Qt::AlignCenter);
        label = new QLabel(PermissionsForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 401, 20));
        label->setAlignment(Qt::AlignCenter);
        location = new QLabel(PermissionsForm);
        location->setObjectName(QString::fromUtf8("location"));
        location->setGeometry(QRect(0, 70, 401, 20));
        location->setAlignment(Qt::AlignCenter);

        retranslateUi(PermissionsForm);

        QMetaObject::connectSlotsByName(PermissionsForm);
    } // setupUi

    void retranslateUi(QWidget *PermissionsForm)
    {
        PermissionsForm->setWindowTitle(QCoreApplication::translate("PermissionsForm", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PermissionsForm", "Access control", nullptr));
        accessCombo->setItemText(0, QCoreApplication::translate("PermissionsForm", "--", nullptr));
        accessCombo->setItemText(1, QCoreApplication::translate("PermissionsForm", "Anyone", nullptr));
        accessCombo->setItemText(2, QCoreApplication::translate("PermissionsForm", "Only owner and group", nullptr));
        accessCombo->setItemText(3, QCoreApplication::translate("PermissionsForm", "Only owner", nullptr));

        modifyCombo->setItemText(0, QCoreApplication::translate("PermissionsForm", "--", nullptr));
        modifyCombo->setItemText(1, QCoreApplication::translate("PermissionsForm", "Anyone", nullptr));
        modifyCombo->setItemText(2, QCoreApplication::translate("PermissionsForm", "Only owner and group", nullptr));
        modifyCombo->setItemText(3, QCoreApplication::translate("PermissionsForm", "Only owner", nullptr));

        executeCombo->setItemText(0, QCoreApplication::translate("PermissionsForm", "--", nullptr));
        executeCombo->setItemText(1, QCoreApplication::translate("PermissionsForm", "Anyone", nullptr));
        executeCombo->setItemText(2, QCoreApplication::translate("PermissionsForm", "Only owner and group", nullptr));
        executeCombo->setItemText(3, QCoreApplication::translate("PermissionsForm", "Only owner", nullptr));

        label_2->setText(QCoreApplication::translate("PermissionsForm", "Acess", nullptr));
        label_3->setText(QCoreApplication::translate("PermissionsForm", "Modify", nullptr));
        label_4->setText(QCoreApplication::translate("PermissionsForm", "Execute", nullptr));
        label->setText(QCoreApplication::translate("PermissionsForm", "Properties", nullptr));
        location->setText(QCoreApplication::translate("PermissionsForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PermissionsForm: public Ui_PermissionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERMISSIONSFORM_H
