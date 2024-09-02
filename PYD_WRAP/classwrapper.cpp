#pragma once
#include <boost/python.hpp>
#include "imagePack.h"
#include "packContain.h"
#include "packParams.h"

BOOST_PYTHON_MODULE(imgclasses)
{
	using namespace boost::python;
	class_<PackParams>("PackParams")
		.def("setSeq", &PackParams::setSeq, args("seqType"))
		.def("setPlane", &PackParams::setPlane, args("planeType"))
		.def("setName", &PackParams::setName, args("packName"))
		.def("getSeq", &PackParams::getSeq)
		.def("getPlane", &PackParams::getPlane)
		.def("getName", &PackParams::getName);
	class_<PackContain>("PackContain")
		.def("setPath", &PackContain::setPath, args("mainPath"))
		.def("fillImgs", &PackContain::fillImgs, args("mainPath"))
		.def("getAmm", &PackContain::getAmm)
		.def("getPath", &PackContain::getPath)
		.def("getImgNames", &PackContain::getImgNames);
	class_<ImagePack>("ImagePack")
		.def("setCont", &ImagePack::setCont, args("conent"))
		.def("setParams", &ImagePack::setParams, args("params"))
		.def_readonly("packCont", &ImagePack::content)
		.def_readonly("packParams", &ImagePack::params);
}