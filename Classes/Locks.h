#pragma once
#include "ObjectBase.h"
#include "Explosion.h"

class Locks : public ObjectBase
{
private:

public:
	Locks() {}
	~Locks() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
	void RemovePhysicsBody();

	Sprite* RockDregs[4];
	Dregs* _dregs;

	int _index;

	Explosion* _explosion;

};