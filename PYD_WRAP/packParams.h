#pragma once
#include <string>
class PackParams
{
	int seqType = 0;
	int planeType = 0;
	std::string packName = "";
    std::string packSeqRecognize(const int& seqType);
    std::string packPlaneRecognize(const int& planeType);
public:
    PackParams(){}
    PackParams(const int& seqType, const int& planeType);
	void setSeq(const int& seqType);
	void setPlane(const int& planeType);
	void setName(const std::string& packName);
    int getSeq() const;
    int getPlane() const;
    std::string getName() const;
};

