#pragma once
#include "ProjectFW.h"

class Dregs
{
private:
	SpriteFrameCache* cache; // Ä³½¬


	Sprite* dregs[20];

	int randomPosX[20];
	int randomPosY[20];

	int randomHeight[20];

	bool randomAddChild[20];

public:
	Dregs(Scene* scene, Vec2 position, ObjectName objectname, int zoder);
	~Dregs();
};