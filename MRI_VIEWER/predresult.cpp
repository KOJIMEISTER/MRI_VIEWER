#include "predresult.h"

void PredResult::addProbs(list& indexes, list& probs)
{
    for (int i = 0; i < len(indexes) && len(probs); ++i)
    {
        auto found = find_if(clProbs.begin(), clProbs.end(), [&indexes, &i](std::pair<int, float>& elem)
            {return elem.first == indexes[i]; });
        if (found != clProbs.end() && (*found).second < probs[i])
            (*found).second = extract<float>(probs[i]);
        else
            clProbs.push_back({ extract<int>(indexes[i]), extract<float>(probs[i])});
    }
}

std::list<std::pair<int, float>> PredResult::getProbs()
{
	std::list<std::pair<int, float>> topClasses;
	clProbs.sort([](const std::pair<int, float>& fir, const std::pair<int, float>& sec)
		{return fir.second < sec.second; });
	auto it = clProbs.cbegin();
	for (int i = 0; i < 3 && it != clProbs.cend(); ++i, ++it)
		topClasses.push_back(*it);
	return topClasses;
}

dict PredResult::getPyProbs()
{
	dict pyDict;
	clProbs.sort([](const std::pair<int,float>& fir, const std::pair<int, float>&sec) 
		{return fir.second < sec.second; });
	int i = 0;
	for (auto& itm : clProbs)
	{
		if (i++== 3)
			break;
		pyDict[itm.first] = itm.second;
	}
	return pyDict;
}
