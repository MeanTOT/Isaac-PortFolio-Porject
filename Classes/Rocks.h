#pragma once
#include "ObjectBase.h"

class Rocks : public ObjectBase
{
private:
	
public:
	Rocks();
	~Rocks();
	void CreateRockBaseMent(Scene* scene, Vec2 position, int index);
};