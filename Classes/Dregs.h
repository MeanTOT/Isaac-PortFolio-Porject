#pragma once
#include "ProjectFW.h"

class Dregs
{
private:
	SpriteFrameCache* cache; // Ä³½¬


	Sprite* dregs[30];
	PhysicsBody* dregsPhysics[30];

	int randomPosX[30];
	int randomPosY[30];

	int randomHeight[30];

	bool randomAddChild[30];

public:
	Dregs(Scene* scene, Vec2 position, ObjectName objectname, int zoder);
	~Dregs();

	void RemovePhysicsBody();
};