#pragma once
#include <string>
#include <list>
#include <filesystem>
#include <boost/python.hpp>
#include <Windows.h>
using namespace boost::python;

class PackContain
{
    int imgAmm = 0;
    std::list<std::string> imgNames;
    std::string mainPath;
    std::string dirPath;
    std::string dirName;
public:
    PackContain(){}
    PackContain(const std::string& mainPath);
    void setPath(const std::string& mainPath, const bool& isSegPack);
    void fillImgs();
    void sortNames();
    int getAmm() const;
    std::string getDirPath() const;
    std::string getMainPath() const;
    std::string getDirName() const;
    std::list<std::string> const& getStdImgNames() const;
    list getPyImgNames() const;
};

