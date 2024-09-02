/********************************************************************************
** Form generated from reading UI file 'dialogclassify.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCLASSIFY_H
#define UI_DIALOGCLASSIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogClassify
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *lbErrorStatus;
    QFrame *line;
    QListView *lvAllowedPacks;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lbTime;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnApply;

    void setupUi(QDialog *DialogClassify)
    {
        if (DialogClassify->objectName().isEmpty())
            DialogClassify->setObjectName(QString::fromUtf8("DialogClassify"));
        DialogClassify->resize(593, 427);
        verticalLayout = new QVBoxLayout(DialogClassify);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(DialogClassify);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lbErrorStatus = new QLabel(DialogClassify);
        lbErrorStatus->setObjectName(QString::fromUtf8("lbErrorStatus"));
        lbErrorStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lbErrorStatus);


        verticalLayout->addLayout(horizontalLayout_3);

        line = new QFrame(DialogClassify);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lvAllowedPacks = new QListView(DialogClassify);
        lvAllowedPacks->setObjectName(QString::fromUtf8("lvAllowedPacks"));

        verticalLayout->addWidget(lvAllowedPacks);

        line_2 = new QFrame(DialogClassify);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DialogClassify);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        lbTime = new QLabel(DialogClassify);
        lbTime->setObjectName(QString::fromUtf8("lbTime"));
        lbTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lbTime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCancel = new QPushButton(DialogClassify);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnApply = new QPushButton(DialogClassify);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));

        horizontalLayout->addWidget(btnApply);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogClassify);

        QMetaObject::connectSlotsByName(DialogClassify);
    } // setupUi

    void retranslateUi(QDialog *DialogClassify)
    {
        DialogClassify->setWindowTitle(QApplication::translate("DialogClassify", "Dialog", nullptr));
        label->setText(QApplication::translate("DialogClassify", "\320\222\321\213\320\261\320\270\321\200\320\265\321\202\320\265 \320\277\320\260\320\272\320\265\321\202 \320\264\320\273\321\217 \320\264\320\270\320\260\320\263\320\275\320\276\320\267\320\260", nullptr));
        lbErrorStatus->setText(QString());
        label_2->setText(QApplication::translate("DialogClassify", "\320\237\321\200\320\270\320\274\320\265\321\200\320\275\320\276\320\265 \320\262\321\200\320\265\320\274\321\217 \321\201\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\264\320\270\320\260\320\263\320\275\320\276\320\267\320\260:", nullptr));
        lbTime->setText(QApplication::translate("DialogClassify", "00.00.00", nullptr));
        btnCancel->setText(QApplication::translate("DialogClassify", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        btnApply->setText(QApplication::translate("DialogClassify", "\320\236\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogClassify: public Ui_DialogClassify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCLASSIFY_H
