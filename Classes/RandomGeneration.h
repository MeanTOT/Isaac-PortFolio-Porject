#pragma once
#include "iostream"
#include "random"

using namespace std;

class RandomGeneration
{
private:
	static RandomGeneration* instance;
	RandomGeneration() {}
	~RandomGeneration() {}
public:
	static RandomGeneration* getInstance();
	static void releaseInstance();

	int getRandomNumberWithRange(int min, int max);
	bool getPercentage(float per);

};