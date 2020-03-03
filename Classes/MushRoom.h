#pragma once
#include "ObjectBase.h"

class MushRoom : public ObjectBase
{
private:

public:
	MushRoom() {}
	~MushRoom() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);

	Sprite* RockDregs[4];
	Dregs* _dregs;

	int _index;

};