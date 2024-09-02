#ifndef DIALOGCLASSIFY_H
#define DIALOGCLASSIFY_H

#include <QDialog>
#include <QList>
#include <QTime>
#include <QThread>
#include "imagePack.h"
#include "qlistmodel.h"
#include "interp.h"

namespace Ui {
class DialogClassify;
}

class DialogClassify : public QDialog
{
    Q_OBJECT
    QListModel model;
    QList<ImagePack> packs;
    QTime timeToComplete;
    bool type = 1;
public:
    explicit DialogClassify(QWidget *parent = nullptr);
    ~DialogClassify();
    void setPacks(QList<ImagePack>& packs, const bool& type = 1);
    QTime calcTime(const int& amm);

Q_SIGNALS:
    void pickedToClassify(ImagePack pack, QTime time, bool type);

private Q_SLOTS:
    void on_btnCancel_clicked();
    void on_btnApply_clicked();

    void on_lvAllowedPacks_clicked(const QModelIndex &index);

private:
    Ui::DialogClassify *ui;
};

#endif // DIALOGCLASSIFY_H
