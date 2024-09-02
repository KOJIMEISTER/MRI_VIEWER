/********************************************************************************
** Form generated from reading UI file 'dialogwhichwind.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWHICHWIND_H
#define UI_DIALOGWHICHWIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogWhichWind
{
public:
    QPushButton *btnToWin1;
    QPushButton *btnToWin2;

    void setupUi(QDialog *DialogWhichWind)
    {
        if (DialogWhichWind->objectName().isEmpty())
            DialogWhichWind->setObjectName(QString::fromUtf8("DialogWhichWind"));
        DialogWhichWind->resize(102, 41);
        btnToWin1 = new QPushButton(DialogWhichWind);
        btnToWin1->setObjectName(QString::fromUtf8("btnToWin1"));
        btnToWin1->setGeometry(QRect(0, 20, 101, 21));
        QFont font;
        font.setPointSize(6);
        btnToWin1->setFont(font);
        btnToWin2 = new QPushButton(DialogWhichWind);
        btnToWin2->setObjectName(QString::fromUtf8("btnToWin2"));
        btnToWin2->setGeometry(QRect(0, 0, 101, 21));
        btnToWin2->setFont(font);

        retranslateUi(DialogWhichWind);

        QMetaObject::connectSlotsByName(DialogWhichWind);
    } // setupUi

    void retranslateUi(QDialog *DialogWhichWind)
    {
        DialogWhichWind->setWindowTitle(QString());
        btnToWin1->setText(QApplication::translate("DialogWhichWind", "\320\236\320\272\320\275\320\276 1", nullptr));
        btnToWin2->setText(QApplication::translate("DialogWhichWind", "\320\236\320\272\320\275\320\276 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogWhichWind: public Ui_DialogWhichWind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWHICHWIND_H
