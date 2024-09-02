#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&dialWW, SIGNAL(pickWindow(const int&)), this, SLOT(onDialWWBtn(const int&)));
    connect(&dialPL, SIGNAL(newImagePack(ImagePack)), this, SLOT(addImagePack(ImagePack)));
    connect(&dialCL, SIGNAL(pickedToClassify(ImagePack, QTime, bool)), this, SLOT(classifyPick(ImagePack, QTime, bool)));
    connect(&dialCLW, SIGNAL(sendPreds(PredResult)), this, SLOT(predictsDone(PredResult)));
    connect(&dialCLW.infoWrap, &InfoWrap::segmsMade, this, &MainWindow::segmsDone);
    connect(&dialPL, &DialPL::editedImagePack, this, &MainWindow::editImagePack);
    connect(&dialPL, &DialPL::callDelete, this, &MainWindow::deletedPack);

    styleSheetFile->open(QFile::ReadOnly);

    QString styleSheet = QLatin1String(styleSheetFile->readAll());
    this->setStyleSheet(styleSheet);

    dialWW.setAttribute(Qt::WA_QuitOnClose, false);
    dialWW.setStyleSheet(styleSheet);
    dialWW.setWindowFlag(Qt::FramelessWindowHint);
    dialPL.setAttribute(Qt::WA_QuitOnClose, false);
    dialPL.setStyleSheet(styleSheet);
    dialPL.setWindowFlag(Qt::FramelessWindowHint);
    dialCL.setAttribute(Qt::WA_QuitOnClose, false);
    dialCL.setStyleSheet(styleSheet);
    dialCL.setWindowFlag(Qt::FramelessWindowHint);
    dialCLW.setAttribute(Qt::WA_QuitOnClose, false);
    dialCLW.setStyleSheet(styleSheet);
    dialCLW.setWindowFlag(Qt::FramelessWindowHint);

    ui->lvPacks->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
    ui->lvPacks->setWrapping(true);
    ui->lvPacks->setWordWrap(true);
    ui->lvPacks->setUniformItemSizes(true);
    ui->lvPacks->setViewMode(QListView::IconMode);

    qRegisterMetaType<PredResult>();
    qRegisterMetaType<ImagePack>();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete styleSheetFile;
    delete packsModel;
}

void MainWindow::on_actionLoadPack_triggered()
{
    dialPL.prepareMode();
    dialPL.exec();
}

void MainWindow::on_lvPacks_clicked(const QModelIndex &index)
{
    idxCurPack = index.row();
    if(dialWW.isVisible())
    {
        dialWW.close();
    }
    dialWW.move(QCursor::pos() + QPoint(50,0));
    dialWW.show();
}

void MainWindow::mousePressEvent(QMouseEvent* evt)
{
    if(dialWW.isVisible())
    {
        if(!dialWW.rect().contains(evt->pos()))
        {
            dialWW.close();
        }
    }
}

void MainWindow::onDialWWBtn(const int& windIdx)
{
    if(windIdx == 0)
    {
        if(firWind != nullptr)
            delete firWind;
        firWind = new PackScroll(packs[idxCurPack], *ui->lbWindFir);
        QString pathToImg = packs[idxCurPack].content.getDirPath().c_str();
        QString imgName = packs[idxCurPack].content.getStdImgNames().front().c_str();
        ui->lbWindFirName->setText(QString(packs[idxCurPack].params.getName().c_str()));
        ui->vsbWindFir->setMaximum(packs[idxCurPack].content.getAmm()-1);
    }
    else if(windIdx == 1)
    {
        if(secWind != nullptr)
            delete secWind;
        secWind = new PackScroll(packs[idxCurPack], *ui->lbWindSec);
        QString pathToImg = packs[idxCurPack].content.getDirPath().c_str();
        QString imgName = packs[idxCurPack].content.getStdImgNames().front().c_str();
        ui->lbWindSecName->setText(QString(packs[idxCurPack].params.getName().c_str()));
        ui->vsbWindSec->setMaximum(packs[idxCurPack].content.getAmm()-1);
    }
}

void MainWindow::wheelEvent(QWheelEvent* evt)
{
    PackScroll * curPack = nullptr;
    bool turn = false;
    if(ui->lbWindFir->underMouse())
    {
        curPack = firWind;
    }
    else if(ui->lbWindSec->underMouse())
    {
        curPack = secWind;
        turn = true;
    }

    if(curPack == nullptr)
        return;
    if(evt->angleDelta().y()>0)
    {
        curPack->scrollUp();
        if(!turn)
            ui->vsbWindFir->setValue(curPack->getCur());
        else
            ui->vsbWindSec->setValue(curPack->getCur());
    }
    if(evt->angleDelta().y()<0)
    {
        curPack->scrollDown();
        if(!turn)
            ui->vsbWindFir->setValue(curPack->getCur());
        else
            ui->vsbWindSec->setValue(curPack->getCur());
    }
}

void MainWindow::on_vsbWindFir_valueChanged(int value)
{
    if(firWind != nullptr)
    {
        firWind->scrollTo(value);
    }
}

void MainWindow::on_vsbWindSec_valueChanged(int value)
{
    if(secWind != nullptr)
    {
        secWind->scrollTo(value);
    }
}

void MainWindow::addImagePack(ImagePack pack)
{
    packs << pack;
    packsModel->setModelData(packs);
    ui->lvPacks->setModel(packsModel);
}

void MainWindow::on_actionClassify_triggered()
{
    dialCL.setPacks(packs);
    dialCL.exec();
}

void MainWindow::classifyPick(ImagePack pack, QTime time, bool type)
{
    dialCLW.setPack(pack, type);
    dialCLW.setTime(time);
    dialCLW.start();
    dialCLW.exec();
}

void MainWindow::predictsDone(PredResult res)
{
    ui->lbPredFir->clear();
    ui->lbPredSec->clear();
    ui->lbPredThird->clear();
    int i = 0;
    auto preds = res.getProbs();
    preds.sort([](const std::pair<int,float>& fir, const std::pair<int,float>& sec)
    {
        return fir.second > sec.second;
    });
    if(preds.size() == 0)
        ui->lbPredFir->setText("Мозг здоров");
    else
        for(auto& pred : preds)
        {
            QString name = PredsClasses::recognizeTumor(pred.first);
            float probability = PredsClasses::relativeDensity(preds, pred.first) * 100;
            if(probability == 0)
                continue;
            QString text = QString::number(probability);
            text += '(';
            text += QString::number(pred.second * 100);
            text += ")% ";
            text += name;
            switch(i)
            {
            case 0: ui->lbPredFir->setText(text);break;
            case 1: ui->lbPredSec->setText(text);break;
            case 2: ui->lbPredThird->setText(text);break;
            default:
                break;
            }
            ++i;
        }
}

void MainWindow::on_actionSegmenty_triggered()
{
    dialCL.setPacks(packs, 0);
    dialCL.exec();
}

void MainWindow::segmsDone(ImagePack pack)
{
    packs << pack;
    packsModel->setModelData(packs);
    ui->lvPacks->setModel(packsModel);
}

void MainWindow::on_lvPacks_doubleClicked(const QModelIndex &index)
{
    if(!index.isValid())
        return;
    dialPL.startEditMode(&packs[index.row()], index.row());
    dialPL.exec();
}

void MainWindow::editImagePack(ImagePack pack, const int idx)
{
    clearWindowByPack(idx);
    packs[idx] = pack;
    packsModel->setModelData(packs);
    ui->lvPacks->setModel(packsModel);
}

void MainWindow::deletedPack(const int idx)
{
    clearWindowByPack(idx);
    packs.removeAt(idx);
    packsModel->setModelData(packs);
    ui->lvPacks->setModel(packsModel);
}

void MainWindow::clearWindowByPack(const int idx)
{
    if(firWind != nullptr && firWind->comparePacks(&packs[idx]))
    {
        delete firWind;
        firWind = nullptr;
        ui->lbWindFir->clear();
        ui->lbWindFirName->clear();
        ui->vsbWindFir->setMaximum(0);
    }
    if(secWind != nullptr && secWind->comparePacks(&packs[idx]))
    {
        delete secWind;
        secWind = nullptr;
        ui->lbWindSec->clear();
        ui->lbWindSecName->clear();
        ui->vsbWindSec->setMaximum(0);
    }
}
