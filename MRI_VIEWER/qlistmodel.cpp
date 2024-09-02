#include "qlistmodel.h"

QListModel::QListModel(QObject* parent)
{

}

int QListModel::rowCount(const QModelIndex & parent) const
{
    return packs->count();
}
QVariant QListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    QVariant val;
    switch (role) {
        case Qt::DisplayRole:
    {
        val = QString(packs->at(index.row()).params.getName().c_str());
        break;
    }
    case Qt::DecorationRole:
    {
        QString dirPath = packs->at(index.row()).content.getDirPath().c_str();
        dirPath += packs->at(index.row()).content.getStdImgNames().front().c_str();
        QPixmap icon(dirPath);
        icon = icon.scaled(123, 123);
        val = icon;
        break;
    }
    default:
    {
        val = QVariant();
        break;
    }
    }
    return val;
};
bool QListModel::setData(const  QModelIndex &index, const QVariant &value, int role)
{
    return false;
};
Qt::ItemFlags QListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
};
void QListModel::setModelData(const QList<ImagePack> &packs, const bool& inited)
{
    if(!inited)
        this->packs = &packs;
    else
    {
        this->beginResetModel();
        this->packs = &packs;
        this->endResetModel();
    }
}
