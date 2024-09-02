/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoadPack;
    QAction *actionClassify;
    QAction *actionSegmenty;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lbWindFirName;
    QLabel *lbWindSecName;
    QHBoxLayout *horizontalLayout;
    QListView *lvPacks;
    QFrame *line_2;
    QLabel *lbWindFir;
    QScrollBar *vsbWindFir;
    QLabel *lbWindSec;
    QScrollBar *vsbWindSec;
    QFrame *line;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbPredFir;
    QLabel *lbPredSec;
    QLabel *lbPredThird;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 771);
        MainWindow->setMinimumSize(QSize(1300, 0));
        MainWindow->setMaximumSize(QSize(1300, 16777215));
        actionLoadPack = new QAction(MainWindow);
        actionLoadPack->setObjectName(QString::fromUtf8("actionLoadPack"));
        actionClassify = new QAction(MainWindow);
        actionClassify->setObjectName(QString::fromUtf8("actionClassify"));
        actionSegmenty = new QAction(MainWindow);
        actionSegmenty->setObjectName(QString::fromUtf8("actionSegmenty"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(150, 0));
        label_2->setMaximumSize(QSize(150, 16777215));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        lbWindFirName = new QLabel(centralWidget);
        lbWindFirName->setObjectName(QString::fromUtf8("lbWindFirName"));
        lbWindFirName->setMinimumSize(QSize(550, 0));
        lbWindFirName->setMaximumSize(QSize(550, 16777215));
        lbWindFirName->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbWindFirName);

        lbWindSecName = new QLabel(centralWidget);
        lbWindSecName->setObjectName(QString::fromUtf8("lbWindSecName"));
        lbWindSecName->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lbWindSecName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lvPacks = new QListView(centralWidget);
        lvPacks->setObjectName(QString::fromUtf8("lvPacks"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lvPacks->sizePolicy().hasHeightForWidth());
        lvPacks->setSizePolicy(sizePolicy1);
        lvPacks->setMinimumSize(QSize(150, 0));
        lvPacks->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(lvPacks);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        lbWindFir = new QLabel(centralWidget);
        lbWindFir->setObjectName(QString::fromUtf8("lbWindFir"));
        lbWindFir->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbWindFir);

        vsbWindFir = new QScrollBar(centralWidget);
        vsbWindFir->setObjectName(QString::fromUtf8("vsbWindFir"));
        vsbWindFir->setMaximum(0);
        vsbWindFir->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(vsbWindFir);

        lbWindSec = new QLabel(centralWidget);
        lbWindSec->setObjectName(QString::fromUtf8("lbWindSec"));
        lbWindSec->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lbWindSec);

        vsbWindSec = new QScrollBar(centralWidget);
        vsbWindSec->setObjectName(QString::fromUtf8("vsbWindSec"));
        vsbWindSec->setMaximum(0);
        vsbWindSec->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(vsbWindSec);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lbPredFir = new QLabel(centralWidget);
        lbPredFir->setObjectName(QString::fromUtf8("lbPredFir"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbPredFir->sizePolicy().hasHeightForWidth());
        lbPredFir->setSizePolicy(sizePolicy2);
        lbPredFir->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setPointSize(24);
        lbPredFir->setFont(font);
        lbPredFir->setAlignment(Qt::AlignCenter);
        lbPredFir->setWordWrap(true);

        horizontalLayout_3->addWidget(lbPredFir);

        lbPredSec = new QLabel(centralWidget);
        lbPredSec->setObjectName(QString::fromUtf8("lbPredSec"));
        sizePolicy2.setHeightForWidth(lbPredSec->sizePolicy().hasHeightForWidth());
        lbPredSec->setSizePolicy(sizePolicy2);
        lbPredSec->setMinimumSize(QSize(0, 50));
        lbPredSec->setFont(font);
        lbPredSec->setAlignment(Qt::AlignCenter);
        lbPredSec->setWordWrap(true);

        horizontalLayout_3->addWidget(lbPredSec);

        lbPredThird = new QLabel(centralWidget);
        lbPredThird->setObjectName(QString::fromUtf8("lbPredThird"));
        sizePolicy2.setHeightForWidth(lbPredThird->sizePolicy().hasHeightForWidth());
        lbPredThird->setSizePolicy(sizePolicy2);
        lbPredThird->setMinimumSize(QSize(0, 50));
        lbPredThird->setFont(font);
        lbPredThird->setAlignment(Qt::AlignCenter);
        lbPredThird->setWordWrap(true);

        horizontalLayout_3->addWidget(lbPredThird);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionLoadPack);
        menu_2->addAction(actionClassify);
        menu_3->addAction(actionSegmenty);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MRI Viewer", nullptr));
        actionLoadPack->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\277\320\260\320\272\320\265\321\202", nullptr));
        actionClassify->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\260\320\262\320\270\321\202\321\214 \320\264\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        actionSegmenty->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\260\320\272\320\265\321\202\321\213:", nullptr));
        lbWindFirName->setText(QString());
        lbWindSecName->setText(QString());
        lbWindFir->setText(QString());
        lbWindSec->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\320\275\320\276\320\267\321\213:", nullptr));
        lbPredFir->setText(QString());
        lbPredSec->setText(QString());
        lbPredThird->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\263\320\275\320\276\320\267", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\260\321\200\321\203\320\266\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
