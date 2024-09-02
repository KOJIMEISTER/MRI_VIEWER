#include "predsclasses.h"

QString PredsClasses::recognizeTumor(const int &index)
{
    switch (index) {
    case ASTROCITOMA: return "Астроцитома";
    case CARCINOMA:return "Карцинома";
    case EPENDIMOMA:return "Эпендимома";
    case GANGLIOGLIOMA:return "Ганглиоглиома";
    case GERMINOMA:return "Герминома";
    case GLIOBLASTOMA:return "Глиобластома";
    case GRANULOMA:return "Гранулема";
    case MEDUBLASTOMA:return "Медубластома";
    case MENINGIOMA:return "Менингиома";
    case NEUROCITOMA:return "Нейроцитома";
    case OLIGODENDROGLIOMA:return "Олигодендроглиома";
    case PAPILOMA:return "Папилома";
    case SCHWANNOMA:return "Шваннома";
    case TUBERCULOMA:return "Туберкулома";
    case NORMAL:return "Мозг здоров";
    default:break;
    }
    return QString();
}

float PredsClasses::relativeDensity(const std::list<std::pair<int, float> > &preds, const int &idxWhich)
{
    float total = 0.;
    float whichVal = 0.;
    for(auto& elem : preds)
    {
        total += elem.second;
        if(elem.first == idxWhich)
            whichVal = elem.second;
    }
    if(total == 0.)
        return 0.;
    else
        return whichVal / total;
}
