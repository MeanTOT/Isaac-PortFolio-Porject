#include "RandomGeneration.h"

// min���� max ������ ������ ����
int RandomGeneration::getRandomNumberWithRange(int min, int max)
{
	random_device rn;
	mt19937_64 rnd(rn());

	uniform_int_distribution<int> range(min, max);

	return range(rnd);
}

//  �Ű������� ���� Ȯ���� true ��ȯ
bool RandomGeneration::getPercentage(float per)
{
	random_device rn;
	mt19937_64 rnd(rn());

	bernoulli_distribution percent(per);

	return percent(rnd);
}
