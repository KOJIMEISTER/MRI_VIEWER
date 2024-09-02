#ifndef PACKSCROLL_H
#define PACKSCROLL_H

#include "imagePack.h"
#include <QLabel>
#include <QPixmap>
#include <list>
#include <string>

class PackScroll
{
    const ImagePack* pack = nullptr;
    QLabel* image = nullptr;
    QString dirPath;
    const std::list<std::string> *names = nullptr;
    int curIdx = 0;
public:
    PackScroll(const ImagePack& pack, QLabel& image);
    void scrollUp();
    void scrollDown();
    void scrollTo(const int& val);
    bool comparePacks(ImagePack* pack);
    int getCur();
    int getMax();
};

#endif // PACKSCROLL_H
