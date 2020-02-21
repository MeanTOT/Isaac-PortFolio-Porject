#pragma once
#include "ObjectBase.h"
#include "Explosion.h"

class Rocks : public ObjectBase
{
private:
	
public:
	Rocks() {}
	~Rocks() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);

	Sprite* RockDregs[4];
	Dregs* _dregs; 

	int _index;

	Explosion* _explosion;

};