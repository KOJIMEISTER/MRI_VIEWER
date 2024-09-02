/********************************************************************************
** Form generated from reading UI file 'dialpl.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALPL_H
#define UI_DIALPL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialPL
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *lbStatusMsg;
    QFrame *line;
    QLabel *lbTextEnterPath;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lePathToDir;
    QPushButton *btnOpenDirPath;
    QFrame *line_2;
    QLabel *label_3;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *rbSeqT1;
    QRadioButton *rbSeqT2;
    QRadioButton *rbSeqFLAIR;
    QFrame *line_3;
    QLabel *label_4;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbPlaneAX;
    QRadioButton *rbPlaneCOR;
    QRadioButton *rbPlaneSAG;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnExit;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnApply;

    void setupUi(QDialog *DialPL)
    {
        if (DialPL->objectName().isEmpty())
            DialPL->setObjectName(QString::fromUtf8("DialPL"));
        DialPL->resize(493, 351);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialPL->sizePolicy().hasHeightForWidth());
        DialPL->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DialPL);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(DialPL);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        lbStatusMsg = new QLabel(DialPL);
        lbStatusMsg->setObjectName(QString::fromUtf8("lbStatusMsg"));
        lbStatusMsg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(lbStatusMsg);


        verticalLayout->addLayout(horizontalLayout_5);

        line = new QFrame(DialPL);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lbTextEnterPath = new QLabel(DialPL);
        lbTextEnterPath->setObjectName(QString::fromUtf8("lbTextEnterPath"));

        verticalLayout->addWidget(lbTextEnterPath);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lePathToDir = new QLineEdit(DialPL);
        lePathToDir->setObjectName(QString::fromUtf8("lePathToDir"));

        horizontalLayout->addWidget(lePathToDir);

        btnOpenDirPath = new QPushButton(DialPL);
        btnOpenDirPath->setObjectName(QString::fromUtf8("btnOpenDirPath"));

        horizontalLayout->addWidget(btnOpenDirPath);


        verticalLayout->addLayout(horizontalLayout);

        line_2 = new QFrame(DialPL);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_3 = new QLabel(DialPL);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        line_5 = new QFrame(DialPL);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        rbSeqT1 = new QRadioButton(DialPL);
        rbSeqT1->setObjectName(QString::fromUtf8("rbSeqT1"));
        rbSeqT1->setChecked(true);

        horizontalLayout_4->addWidget(rbSeqT1);

        rbSeqT2 = new QRadioButton(DialPL);
        rbSeqT2->setObjectName(QString::fromUtf8("rbSeqT2"));

        horizontalLayout_4->addWidget(rbSeqT2);

        rbSeqFLAIR = new QRadioButton(DialPL);
        rbSeqFLAIR->setObjectName(QString::fromUtf8("rbSeqFLAIR"));

        horizontalLayout_4->addWidget(rbSeqFLAIR);


        verticalLayout->addLayout(horizontalLayout_4);

        line_3 = new QFrame(DialPL);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_4 = new QLabel(DialPL);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        line_6 = new QFrame(DialPL);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rbPlaneAX = new QRadioButton(DialPL);
        rbPlaneAX->setObjectName(QString::fromUtf8("rbPlaneAX"));
        rbPlaneAX->setChecked(true);

        horizontalLayout_3->addWidget(rbPlaneAX);

        rbPlaneCOR = new QRadioButton(DialPL);
        rbPlaneCOR->setObjectName(QString::fromUtf8("rbPlaneCOR"));
        rbPlaneCOR->setEnabled(false);

        horizontalLayout_3->addWidget(rbPlaneCOR);

        rbPlaneSAG = new QRadioButton(DialPL);
        rbPlaneSAG->setObjectName(QString::fromUtf8("rbPlaneSAG"));
        rbPlaneSAG->setEnabled(false);

        horizontalLayout_3->addWidget(rbPlaneSAG);


        verticalLayout->addLayout(horizontalLayout_3);

        line_4 = new QFrame(DialPL);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnExit = new QPushButton(DialPL);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_2->addWidget(btnExit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnDelete = new QPushButton(DialPL);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        horizontalLayout_2->addWidget(btnDelete);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnApply = new QPushButton(DialPL);
        btnApply->setObjectName(QString::fromUtf8("btnApply"));

        horizontalLayout_2->addWidget(btnApply);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(DialPL);

        QMetaObject::connectSlotsByName(DialPL);
    } // setupUi

    void retranslateUi(QDialog *DialPL)
    {
        DialPL->setWindowTitle(QApplication::translate("DialPL", "Dialog", nullptr));
        label->setText(QApplication::translate("DialPL", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\277\320\260\320\272\320\265\321\202\320\260", nullptr));
        lbStatusMsg->setText(QString());
        lbTextEnterPath->setText(QApplication::translate("DialPL", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\321\203\321\202\321\214 \320\272 \320\277\320\260\320\272\320\265\321\202\321\203", nullptr));
        btnOpenDirPath->setText(QApplication::translate("DialPL", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        label_3->setText(QApplication::translate("DialPL", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \321\201\320\275\320\270\320\274\320\272\320\276\320\262", nullptr));
        rbSeqT1->setText(QApplication::translate("DialPL", "T1", nullptr));
        rbSeqT2->setText(QApplication::translate("DialPL", "T2", nullptr));
        rbSeqFLAIR->setText(QApplication::translate("DialPL", "FLAIR", nullptr));
        label_4->setText(QApplication::translate("DialPL", "\320\237\320\273\320\276\321\201\320\272\320\276\321\201\321\202\321\214 \321\201\320\275\320\270\320\274\320\272\320\276\320\262", nullptr));
        rbPlaneAX->setText(QApplication::translate("DialPL", "AX", nullptr));
        rbPlaneCOR->setText(QApplication::translate("DialPL", "COR", nullptr));
        rbPlaneSAG->setText(QApplication::translate("DialPL", "SAG", nullptr));
        btnExit->setText(QApplication::translate("DialPL", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        btnDelete->setText(QApplication::translate("DialPL", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnApply->setText(QApplication::translate("DialPL", "\320\236\320\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialPL: public Ui_DialPL {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALPL_H
