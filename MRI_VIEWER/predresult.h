#pragma once
#include <list>
#include <algorithm>
#include <boost/python.hpp>
#include <QMetaType>
using namespace boost::python;

class PredResult
{
	std::list <std::pair<int, float>> clProbs;
public:
	void addProbs(list& indexes, list& probs);
	std::list<std::pair<int, float>> getProbs();
	dict getPyProbs();

};

Q_DECLARE_METATYPE(PredResult);
