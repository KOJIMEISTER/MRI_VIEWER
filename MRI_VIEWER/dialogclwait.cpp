#include "dialogclwait.h"
#include "ui_dialogclwait.h"

void InfoWrap::run()
{
    if(type)
    {
        PredResult res = PINFIN::doClassification(*pack);
        predsMade(res);
    }
    else
    {
        ImagePack newPack = PINFIN::doSegmentation(*pack);
        newPack.setParams((*pack).params);
        newPack.params.setName(newPack.params.getName() + " SEG");
        segmsMade(newPack);
    }
    finish();
}

void InfoWrap::setPack(ImagePack* pack, const bool type)
{
    this->pack = pack;
    this->type = type;
}

DialogCLWait::DialogCLWait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCLWait)
{
    ui->setupUi(this);
    connect(&infoWrap, &InfoWrap::finish, this, &DialogCLWait::finished);
    connect(&infoWrap, &InfoWrap::predsMade, this, &DialogCLWait::getPreds);
    gifProc->setScaledSize({32,32});
    ui->lbGifProcess->setMovie(gifProc);
    connect(&timer, &QTimer::timeout, this, [=]{
        waited = waited.addMSecs(1000);
        ui->lbTimeGone->setText(waited.toString());
    });
    connect(&classifier, &QThread::started, &infoWrap, &InfoWrap::run);
    connect(&infoWrap, SIGNAL(predsMade(PredResult)), this, SLOT(getPreds(PredResult)));
    infoWrap.moveToThread(&classifier);
}

DialogCLWait::~DialogCLWait()
{
    delete ui;
    delete gifProc;
    classifier.terminate();
}

void DialogCLWait::start()
{
    infoWrap.setPack(pack, type);
    waited = QTime(0,0,0);
    timer.start(1000);
    gifProc->start();
    classifier.start();
}

void DialogCLWait::setPack(ImagePack &pack, const bool type)
{
    this->pack = &pack;
    this->type = type;
}

void DialogCLWait::setTime(QTime time)
{
    toWait = time;
    ui->lbTimeWait->setText(toWait.toString());
}

void DialogCLWait::on_btnCancel_clicked()
{
    finished();
}

void DialogCLWait::finished()
{
    classifier.terminate();
    timer.stop();
    gifProc->stop();
    close();
}

void DialogCLWait::getPreds(PredResult res)
{
    Q_EMIT sendPreds(res);
}
