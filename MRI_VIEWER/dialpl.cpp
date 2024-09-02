#include "dialpl.h"
#include "ui_dialpl.h"

DialPL::DialPL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialPL)
{
    ui->setupUi(this);
    seqBtns.addButton(ui->rbSeqT1, 0);
    seqBtns.addButton(ui->rbSeqT2, 1);
    seqBtns.addButton(ui->rbSeqFLAIR, 2);
    planeBtns.addButton(ui->rbPlaneAX, 0);
    planeBtns.addButton(ui->rbPlaneCOR, 1);
    planeBtns.addButton(ui->rbPlaneSAG, 2);
    ui->btnDelete->setHidden(true);
}

DialPL::~DialPL()
{
    delete ui;
}

void DialPL::prepareMode()
{
    editMode = false;
    ui->btnDelete->setHidden(true);
    ui->lePathToDir->clear();
    ui->lbStatusMsg->clear();
    ui->rbSeqT1->setChecked(false);
    ui->rbSeqT2->setChecked(false);
    ui->rbSeqFLAIR->setChecked(false);
    ui->rbPlaneAX->setChecked(false);
    ui->rbPlaneCOR->setChecked(false);
    ui->rbPlaneSAG->setChecked(false);
}

void DialPL::on_btnExit_clicked()
{
    editMode = false;
    ui->btnDelete->setHidden(true);
    close();
}

void DialPL::on_btnOpenDirPath_clicked()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("Укажите папку"), "C:/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks );
    ui->lePathToDir->setText(dirPath);
}

void DialPL::on_btnApply_clicked()
{
    if(ui->lePathToDir->text().length() == 0 || !QDir(ui->lePathToDir->text()).exists())
    {
        ui->lbStatusMsg->setText("<span style='color: red'>Указанная папка не существует!</span>");
        return;
    }
    if(seqBtns.checkedId() == -1)
    {
        ui->lbStatusMsg->setText("<span style='color: red'>Последовательность пакета не указана!</span>");
        return;
    }
    if(planeBtns.checkedId() == -1)
    {
        ui->lbStatusMsg->setText("<span style='color: red'>Проекция пакета не указана!</span>");
        return;
    }
    std::string dirPath = ui->lePathToDir->text().toStdString();
    if(dirPath.back() != '/')
        dirPath += '/';
    ImagePack pack({dirPath},{seqBtns.checkedId(), planeBtns.checkedId()});
    pack.content.fillImgs();
    if(editMode)
    {
        editedImagePack(pack, editIdx);
    }
    else {
        newImagePack(pack);
    }
    close();
}

void DialPL::startEditMode(const ImagePack* pack, const int idx)
{
    editIdx = idx;
    editMode = true;
    ui->btnDelete->setHidden(false);
    int seq = pack->params.getSeq();
    int plane = pack->params.getPlane();
    QString path = pack->content.getDirPath().c_str();
    ui->lePathToDir->setText(path);
    switch (seq)
    {
    case 0: {
        ui->rbSeqT1->setChecked(true);
        break;
    }
    case 1: {
        ui->rbSeqT2->setChecked(true);
        break;
    }
    case 2: {
        ui->rbSeqFLAIR->setChecked(true);
    }
    }
    switch(plane)
    {
    case 0: {
        ui->rbPlaneAX->setChecked(true);
        break;
    }
    case 1: {
        ui->rbPlaneCOR->setChecked(true);
        break;
    }
    case 2: {
        ui->rbPlaneSAG->setChecked(true);
        break;
    }
    }
}

void DialPL::on_btnDelete_clicked()
{
    callDelete(editIdx);
    close();
}
