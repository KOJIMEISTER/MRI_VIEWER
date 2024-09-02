#include "imagePack.h"

ImagePack::ImagePack(PackContain content, PackParams params)
{
    this->content = content;
    this->params = params;
}

void ImagePack::setCont(const PackContain& content)
{
	this->content = content;
}

void ImagePack::setParams(const PackParams& params)
{
	this->params = params;
}
