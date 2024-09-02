#ifndef PREDSCLASSES_H
#define PREDSCLASSES_H

#include <QString>
#include <list>

class PredsClasses
{
    enum TUMOR
    {
        ASTROCITOMA,
        CARCINOMA,
        EPENDIMOMA,
        GANGLIOGLIOMA,
        GERMINOMA,
        GLIOBLASTOMA,
        GRANULOMA,
        MEDUBLASTOMA,
        MENINGIOMA,
        NEUROCITOMA,
        OLIGODENDROGLIOMA,
        PAPILOMA,
        SCHWANNOMA,
        TUBERCULOMA,
        NORMAL
    };

public:
    static QString recognizeTumor(const int& index);
    static float relativeDensity(const std::list<std::pair<int,float>>& preds, const int& idxWhich);
};

#endif // PREDSCLASSES_H
