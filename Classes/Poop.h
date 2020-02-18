#pragma once
#include "ObjectBase.h"

class Poop : public ObjectBase
{
private:

public:
	Poop() {}
	~Poop() {}

	Dregs* _dregs;

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
};
