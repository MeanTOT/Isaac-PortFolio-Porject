#pragma once
#include "ObjectBase.h"

class Fire : public ObjectBase
{
private:

public:
	Fire() {}
	~Fire() {}

	Sprite* fire;


	void CreateObject(Scene* scene, Vec2 position, int index);
	void tick();
};


