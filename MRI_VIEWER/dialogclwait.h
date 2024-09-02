#ifndef DIALOGCLWAIT_H
#define DIALOGCLWAIT_H

#include <QDialog>
#include <QTime>
#include <QMovie>
#include <QTimer>
#include <QThread>
#include <QList>
#include <QDebug>
#include <QElapsedTimer>
#include "interp.h"
#include "predresult.h"
#include "imagePack.h"

namespace Ui {
class DialogCLWait;
}

class InfoWrap : public QObject
{
    Q_OBJECT
    ImagePack* pack = nullptr;
    bool type = 1;
    public:
    explicit InfoWrap(QObject *parent = nullptr) : QObject (parent){}
    ~InfoWrap(){}
    InfoWrap(ImagePack* pack):pack(pack){}
    void setPack(ImagePack* pack, const bool type);
Q_SIGNALS:
    void predsMade(PredResult res);
    void segmsMade(ImagePack pack);
    void finish();
    public Q_SLOTS:
    void run();
};

class DialogCLWait : public QDialog
{
    Q_OBJECT
    QTime toWait;
    QTime waited = QTime(0,0,0);
    QTimer timer;
    QElapsedTimer elTimer;
    ImagePack *pack = nullptr;
    QMovie *gifProc = new QMovie("loading.gif");
    QThread classifier;
    InfoWrap infoWrap;
    bool type = 1;
    friend class MainWindow;
public:
    explicit DialogCLWait(QWidget *parent = nullptr);
    ~DialogCLWait();
    void setTime(QTime time);
    void setPack(ImagePack& pack, const bool type);
    void start();

Q_SIGNALS:
    void sendPreds(PredResult res);

public Q_SLOTS:
    void on_btnCancel_clicked();
    void finished();
    void getPreds(PredResult res);

private:
    Ui::DialogCLWait *ui;
};

#endif // DIALOGCLWAIT_H
