#include "packParams.h"

PackParams::PackParams(const int& seqType, const int& planeType)
{
    this->seqType = seqType;
    this->planeType = planeType;
    packName += packSeqRecognize(seqType);
    packName += ' ';
    packName += packPlaneRecognize(planeType);
}

std::string PackParams::packSeqRecognize(const int &seqType)
{
    switch (seqType) {
    case 0: return "T1";
    case 1: return "T2";
    case 2: return "FLAIR";
    default: return "UNDEF";
    }
}

std::string PackParams::packPlaneRecognize(const int &planeType)
{
    switch (planeType) {
    case 0: return "AX";
    case 1: return "COR";
    case 2: return "SAG";
    default: return "UNDEF";
    }
}

void PackParams::setSeq(const int& seqType)
{
    this->seqType = seqType;
}

void PackParams::setPlane(const int& planeType)
{
    this->planeType = planeType;
}

void PackParams::setName(const std::string& packName)
{
    this->packName = packName;
}

int PackParams::getSeq() const
{
    return seqType;
}

int PackParams::getPlane() const
{
    return planeType;
}

std::string PackParams::getName() const
{
    return packName;
}
