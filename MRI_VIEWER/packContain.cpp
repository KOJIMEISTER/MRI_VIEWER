#include "packContain.h"

PackContain::PackContain(const std::string& dirPath)
{
    setPath(dirPath, false);
}

void PackContain::setPath(const std::string& dirPath, const bool& isSegPack)
{
	imgNames.clear();
	this->dirPath = dirPath;
	std::filesystem::path path(dirPath);
	dirName = path.parent_path().stem().string();
	mainPath = path.parent_path().parent_path().string();
	mainPath += '/';
	if (isSegPack)
		CreateDirectoryA(std::string(dirPath).c_str(), NULL);
}

void PackContain::fillImgs()
{
	imgNames.clear();
	std::filesystem::path path(dirPath);
	for (std::filesystem::directory_iterator next(path), end; next != end; ++next)
		if ((*next).is_regular_file())
		{
			std::string ext = (*next).path().extension().string();
			if (ext == ".png" || ext == ".jpg" || ext == ".jpeg" || ext == ".tif" || ext == ".PNG" ||
				ext == ".JPG" || ext == ".JPEG" || ext == ".TIF")
			{
				imgNames.push_back((*next).path().filename().string());
				++imgAmm;
			}
		}
}

int PackContain::getAmm() const
{
	return imgAmm;
}

std::string PackContain::getDirPath() const
{
	return dirPath;
}

std::string PackContain::getMainPath() const
{
	return mainPath;
}

std::string PackContain::getDirName() const
{
	return dirName;
}

std::list<std::string> const& PackContain::getStdImgNames() const
{
	return imgNames;
}

list PackContain::getPyImgNames() const
{
	list pyList;
	for (auto& img : imgNames)
		pyList.append(img);
	return pyList;
}

void PackContain::sortNames()
{
    imgNames.sort();
}

