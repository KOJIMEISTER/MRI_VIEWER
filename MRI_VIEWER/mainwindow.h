#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMouseEvent>
#include <QCursor>
#include <QDebug>
#include <QTime>
#include <QWheelEvent>
#include <QMetaType>
#include <QtNumeric>
#include "dialogclwait.h"
#include "qlistmodel.h"
#include "dialogwhichwind.h"
#include "packscroll.h"
#include "dialpl.h"
#include "dialogclassify.h"
#include "predsclasses.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QFile *styleSheetFile = new QFile("Combinear.qss");
    QListModel *packsModel = new QListModel();
    QList<ImagePack> packs;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent* evt);
    void wheelEvent(QWheelEvent* evt);
    void clearWindowByPack(const int idx);
private Q_SLOTS:
    void on_actionLoadPack_triggered();
    void on_lvPacks_clicked(const QModelIndex &index);
    void onDialWWBtn(const int& windIdx);
    void on_vsbWindFir_valueChanged(int value);
    void on_vsbWindSec_valueChanged(int value);
    void addImagePack(ImagePack pack);
    void editImagePack(ImagePack pack, const int idx);
    void on_actionClassify_triggered();
    void classifyPick(ImagePack pack, QTime time, bool type);
    void predictsDone(PredResult res);
    void segmsDone(ImagePack pack);
    void deletedPack(const int idx);

    void on_actionSegmenty_triggered();

    void on_lvPacks_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    DialogWhichWind dialWW;
    DialPL dialPL;
    DialogClassify dialCL;
    DialogCLWait dialCLW;
    int idxCurPack = 0;
    PackScroll *firWind = nullptr;
    PackScroll *secWind = nullptr;
};

#endif // MAINWINDOW_H
