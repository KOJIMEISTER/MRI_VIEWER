/********************************************************************************
** Form generated from reading UI file 'dialogclwait.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCLWAIT_H
#define UI_DIALOGCLWAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogCLWait
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *lbTimeGone;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLabel *lbTimeWait;
    QLabel *lbGifProcess;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DialogCLWait)
    {
        if (DialogCLWait->objectName().isEmpty())
            DialogCLWait->setObjectName(QString::fromUtf8("DialogCLWait"));
        DialogCLWait->resize(470, 204);
        verticalLayout = new QVBoxLayout(DialogCLWait);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(DialogCLWait);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lbTimeGone = new QLabel(DialogCLWait);
        lbTimeGone->setObjectName(QString::fromUtf8("lbTimeGone"));

        horizontalLayout->addWidget(lbTimeGone);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_4 = new QLabel(DialogCLWait);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        lbTimeWait = new QLabel(DialogCLWait);
        lbTimeWait->setObjectName(QString::fromUtf8("lbTimeWait"));

        horizontalLayout->addWidget(lbTimeWait);


        verticalLayout->addLayout(horizontalLayout);

        lbGifProcess = new QLabel(DialogCLWait);
        lbGifProcess->setObjectName(QString::fromUtf8("lbGifProcess"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbGifProcess->sizePolicy().hasHeightForWidth());
        lbGifProcess->setSizePolicy(sizePolicy);
        lbGifProcess->setMinimumSize(QSize(448, 49));
        lbGifProcess->setMaximumSize(QSize(448, 49));
        lbGifProcess->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbGifProcess);

        label = new QLabel(DialogCLWait);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnCancel = new QPushButton(DialogCLWait);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialogCLWait);

        QMetaObject::connectSlotsByName(DialogCLWait);
    } // setupUi

    void retranslateUi(QDialog *DialogCLWait)
    {
        DialogCLWait->setWindowTitle(QApplication::translate("DialogCLWait", "Dialog", nullptr));
        label_3->setText(QApplication::translate("DialogCLWait", "\320\237\321\200\320\276\321\210\320\273\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270:", nullptr));
        lbTimeGone->setText(QApplication::translate("DialogCLWait", "00:00:00", nullptr));
        label_4->setText(QApplication::translate("DialogCLWait", "\320\237\321\200\320\270\320\274\320\265\321\200\320\275\320\276\320\265 \320\276\320\266\320\270\320\264\320\260\320\275\320\270\320\265", nullptr));
        lbTimeWait->setText(QApplication::translate("DialogCLWait", "00:00:00", nullptr));
        lbGifProcess->setText(QString());
        label->setText(QApplication::translate("DialogCLWait", "\320\236\320\266\320\270\320\264\320\260\320\271\321\202\320\265...", nullptr));
        btnCancel->setText(QApplication::translate("DialogCLWait", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogCLWait: public Ui_DialogCLWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCLWAIT_H
