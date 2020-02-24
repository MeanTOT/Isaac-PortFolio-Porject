#pragma once
#include "ObjectBase.h"

class altar : public ObjectBase
{
private:

public:
	altar() {}
	~altar() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
};