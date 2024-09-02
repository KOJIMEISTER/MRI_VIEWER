#include "packscroll.h"

PackScroll::PackScroll(const ImagePack& pack, QLabel& image)
{
    this->pack = &pack;
    names = &pack.content.getStdImgNames();
    dirPath = pack.content.getDirPath().c_str();
    this->image = &image;
    if(names->size() != 0)
    {
        QPixmap pm(dirPath + names->front().c_str());
        pm = pm.scaled(512,512);
        this->image->setPixmap(pm);
    }
}

void PackScroll::scrollUp()
{
    if(curIdx - 1 < 0)
        return;
    else
       --curIdx;
    auto it = names->begin();
    std::advance(it, curIdx);
    QPixmap pm(dirPath + (*it).c_str());
    pm = pm.scaled(512,512);
    image->setPixmap(pm);
}

void PackScroll::scrollDown()
{
    if(curIdx + 1 >= getMax())
        return;
    else
       ++curIdx;
    auto it = names->begin();
    std::advance(it, curIdx);
    QPixmap pm(dirPath + (*it).c_str());
    pm = pm.scaled(512,512);
    image->setPixmap(pm);
}

int PackScroll::getMax()
{
    return pack->content.getAmm();
}

void PackScroll::scrollTo(const int& val)
{
    if(val >= getMax() || val < 0)
        return;
    else
       curIdx = val;
    auto it = names->begin();
    std::advance(it, curIdx);
    QPixmap pm(dirPath + (*it).c_str());
    pm = pm.scaled(512,512);
    image->setPixmap(pm);
}

int PackScroll::getCur()
{
    return curIdx;
}

bool PackScroll::comparePacks(ImagePack *pack)
{
    return this->pack == pack;
}
