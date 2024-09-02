#include <iostream>
#include <fstream>
#include "packContain.h"
#include "imagePack.h"
#include "predresult.h"
#include <boost/python.hpp>
using namespace boost::python;

static bool clInited;
static bool segInited;

struct PINFIN
{
	PINFIN() {
		Py_Initialize();
	}
	~PINFIN()
	{
		Py_Finalize();
	}
};

void initCl()
{
	object module = import("__main__");
	object nspace = module.attr("__dict__");
	std::string pathScript = "classification.py";
	std::string scriptCont = "";
	std::ifstream input(pathScript);
	while (!input.eof())
		scriptCont += input.get();
	scriptCont = scriptCont.erase(scriptCont.size() - 1, 1);
	object ignore = exec(scriptCont.c_str(), nspace, nspace);
	clInited = true;
}

void initSeg()
{
	object module = import("__main__");
	object nspace = module.attr("__dict__");
	std::string pathScript = "segmentation.py";
	std::string scriptCont = "";
	std::ifstream input(pathScript);
	while (!input.eof())
		scriptCont += input.get();
	scriptCont = scriptCont.erase(scriptCont.size() - 1, 1);
	object ignore = exec(scriptCont.c_str(), nspace, nspace);
	segInited = true;
}

PredResult doClassification(const ImagePack& pack)
{
	if (!clInited)
		initCl();
	object module = import("__main__");
	object nspace = module.attr("__dict__");
	object func = nspace["doClassification"];
	object res = func(pack);
	return extract<PredResult>(res);
}

ImagePack doSegmentation(const ImagePack& pack)
{
	if (!segInited)
		initSeg();
	object module = import("__main__");
	object nspace = module.attr("__dict__");
	object func = nspace["doSegmentation"];
	return extract<ImagePack>(func(pack));
}

int main()
{
	clInited = false;
	segInited = false;
	PINFIN pifin;
	ImagePack pack;
	pack.content.setPath("C:\\C++\\Projects\\INTERP\\T1,T2\\Germinoma T1\\", false);
	pack.content.fillImgs();
	PredResult res = doClassification(pack);
	for (auto& pred : res.getProbs())
	{
		std::cout << "\nIndex: " << pred.first << " Val: " << pred.second;
	}
	return 0;
}