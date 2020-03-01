#pragma once
#include "ObjectBase.h"
#include "Explosion.h"

class Pit : public ObjectBase
{
private:

public:
	Pit() {}
	~Pit() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);

	int _index;
};