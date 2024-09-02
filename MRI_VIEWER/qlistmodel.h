#ifndef QLISTMODEL_H
#define QLISTMODEL_H

#include <QObject>
#include <QSize>
#include <QList>
#include <QPixmap>
#include <QString>
#include <QAbstractListModel>
#include "imagePack.h"

class QListModel : public QAbstractListModel
{
    Q_OBJECT
    const QList<ImagePack>* packs = nullptr;
public:
    explicit QListModel(QObject* parent = nullptr);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const  QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void setModelData(const QList<ImagePack>& packs, const bool& inited = true);
};

#endif // QLISTMODEL_H
