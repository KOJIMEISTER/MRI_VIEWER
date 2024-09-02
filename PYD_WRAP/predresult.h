#pragma once
#include <list>
#include <algorithm>
#include <boost/python.hpp>
using namespace boost::python;

class PredResult
{
	std::list <std::pair<int, float>> clProbs;
public:
	void addProbs(list& indexes, list& probs);
	std::list<std::pair<int, float>> getProbs();
	dict getPyProbs();

};
