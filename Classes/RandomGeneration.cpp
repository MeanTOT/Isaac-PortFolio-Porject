#include "RandomGeneration.h"

RandomGeneration* RandomGeneration::instance = nullptr;

RandomGeneration * RandomGeneration::getInstance()
{
	if (!instance)
		instance = new RandomGeneration;

	return instance;
}

void RandomGeneration::releaseInstance()
{
	if (instance)
		delete instance;
}

// min부터 max 까지의 난수를 생성
int RandomGeneration::getRandomNumberWithRange(int min, int max)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(min, max);

	return range(rnd);
}

//  매개변수로 들어온 확률로 true 반환
bool RandomGeneration::getPercentage(float per)
{
	random_device rn;
	mt19937_64 rnd(rn());

	bernoulli_distribution percent(per);

	return percent(rnd);
}
