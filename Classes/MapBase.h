#pragma once
#include "ProjectFW.h"
#include "ObjectBase.h"
#include "Rocks.h"

class MapBase
{
private:
	SpriteFrameCache* cache;

	Sprite* shading_1_1;

	Vec2 _position;

public:
	MapBase();
	~MapBase();

	int RoomNumber;

	bool RoomClear;
	bool isMakeDoorR;
	bool isMakeDoorL;
	bool isMakeDoorT;
	bool isMakeDoorB;

	Sprite* mapLT;
	Sprite* mapLB;
	Sprite* mapRT;
	Sprite* mapRB;

	Sprite* doorR;
	Sprite* doorR_1;
	Sprite* doorL;
	Sprite* doorL_1;
	Sprite* doorT;
	Sprite* doorT_1;
	Sprite* doorB;
	Sprite* doorB_1;

	std::vector<ObjectBase*> obvec;

	void CreateBaseMentRoom(Scene* scene, Vec2 position);
	void CreateNormalDoorL(Scene* scene, Vec2 position);
	void CreateNormalDoorR(Scene* scene, Vec2 position);
	void CreateNormalDoorT(Scene* scene, Vec2 position);
	void CreateNormalDoorB(Scene* scene, Vec2 position);

	void CollisionToDoor();


	virtual void tick() {};
	


};
