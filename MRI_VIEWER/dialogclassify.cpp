#include "dialogclassify.h"
#include "ui_dialogclassify.h"

DialogClassify::DialogClassify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogClassify)
{
    ui->setupUi(this);
}

DialogClassify::~DialogClassify()
{
    delete ui;
}

void DialogClassify::setPacks(QList<ImagePack>& packs, const bool& type)
{
    this->type = type;
    this->packs.clear();
    if(packs.size() == 0)
        return;
    for(auto elem : packs)
    {
        if(type)
        {
            if(elem.params.getSeq() == 0 || elem.params.getSeq() == 1)
                this->packs.push_back(elem);
        }
        else
            if(elem.params.getSeq() == 2)
                this->packs.push_back(elem);
    }
    model.setModelData(this->packs, (ui->lvAllowedPacks->model() != nullptr));
    ui->lvAllowedPacks->setModel(&model);
}

void DialogClassify::on_btnCancel_clicked()
{
    close();
}

void DialogClassify::on_btnApply_clicked()
{
    int curIdx = ui->lvAllowedPacks->currentIndex().row();
    if(curIdx == -1)
    {
        ui->lbErrorStatus->setText("<span style='color: red'>Выбирете пакет для диагноза!</span>");
        return;
    }
    if(!timeToComplete.isValid())
        timeToComplete = calcTime(packs[curIdx].content.getAmm());
    close();
    pickedToClassify(packs[curIdx], timeToComplete, type);
}

void DialogClassify::on_lvAllowedPacks_clicked(const QModelIndex &index)
{
    if(!index.isValid())
        return;
    timeToComplete = calcTime(packs[index.row()].content.getAmm());
    ui->lbTime->setText(timeToComplete.toString());
}

QTime DialogClassify::calcTime(const int& amm)
{
    QTime time(0,0,0);
    if(type)
    {
        time = time.addMSecs(amm*150);
        if(!PINFIN::isClInited())
            time = time.addMSecs(20000);
    }
    else
    {
        time = time.addMSecs(amm*450);
        if(!PINFIN::isSegInited())
            time = time.addMSecs(20000);
    }
    return time;
}
