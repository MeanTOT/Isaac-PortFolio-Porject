#pragma once
#include "ProjectFW.h"
#include "ObjectBase.h"
#include "Rocks.h"
#include "Poop.h"
#include "Fire.h"

class MapBase : public Scene
{
private:
	SpriteFrameCache* cache;

	Sprite* shading_1_1;

public:
	MapBase();
	~MapBase();

	int RoomNumber;

	bool RoomClear;
	bool FirstEnter;
	bool isMakeDoorR;
	bool isMakeDoorL;
	bool isMakeDoorT;
	bool isMakeDoorB;

	Scene* _scene;
	Vec2 _position;

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

	void CreateBaseMentRoom(Scene* scene, Vec2 position);
	void CreateNormalDoorL(Scene* scene, Vec2 position);
	void CreateNormalDoorR(Scene* scene, Vec2 position);
	void CreateNormalDoorT(Scene* scene, Vec2 position);
	void CreateNormalDoorB(Scene* scene, Vec2 position);

	void CollisionToDoor();


	virtual void tick() {};
	


};
