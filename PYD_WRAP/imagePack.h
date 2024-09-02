#pragma once
#include "packContain.h"
#include "packParams.h"

class ImagePack
{
public:
    ImagePack(){}
    ImagePack(PackContain content, PackParams params);
	PackContain content;
	PackParams params;
	void setCont(const PackContain& packCont);
	void setParams(const PackParams& packParams);
};
