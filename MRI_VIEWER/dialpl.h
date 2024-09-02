#ifndef DIALPL_H
#define DIALPL_H

#include <QDebug>
#include <QFileDialog>
#include <QButtonGroup>
#include <QDebug>
#include "imagePack.h"

namespace Ui {
class DialPL;
}

class DialPL : public QDialog
{
    Q_OBJECT
    bool editMode = false;
    int editIdx = 0;
public:
    explicit DialPL(QWidget *parent = nullptr);
    ~DialPL();
    void startEditMode(const ImagePack* pack, const int idx);
    void prepareMode();
Q_SIGNALS:
    void newImagePack(ImagePack pack);
    void editedImagePack(ImagePack pack, const int idx);
    void callDelete(const int idx);

private Q_SLOTS:
    void on_btnExit_clicked();

    void on_btnOpenDirPath_clicked();

    void on_btnApply_clicked();

    void on_btnDelete_clicked();

private:
    QButtonGroup seqBtns;
    QButtonGroup planeBtns;
    Ui::DialPL *ui;
};

#endif // DIALPL_H
