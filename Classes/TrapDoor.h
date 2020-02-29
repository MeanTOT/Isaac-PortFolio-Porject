#pragma once
#include "ObjectBase.h"

class TrapDoor : public ObjectBase
{
private:

public:
	TrapDoor() {}
	~TrapDoor() {}

	void tick();
	void CreateObject(Scene* scene, Vec2 position, int index);
	void SceneChange();

};