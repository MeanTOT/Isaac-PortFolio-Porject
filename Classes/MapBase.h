#pragma once
#include "ProjectFW.h"
#include "ObjectBase.h"
#include "MonsterBase.h"
#include "Rocks.h"
#include "Poop.h"
#include "Fire.h"
#include "Fly.h"
#include "EffectPoof.h"

class MapBase : public Scene
{
private:
	SpriteFrameCache* cache;

	Sprite* shading_1_1;
	Sprite* overlay_1_1;

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

	Rect mapRect;

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

	Sprite* closeDoorR;
	Sprite* closeDoorR_1;
	Sprite* closeDoorL;
	Sprite* closeDoorL_1;
	Sprite* closeDoorT;
	Sprite* closeDoorT_1;
	Sprite* closeDoorB;
	Sprite* closeDoorB_1;


	void CreateBaseMentRoom(Scene* scene, Vec2 position);
	void CreateDoorL(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorR(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorT(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorB(Scene* scene, Vec2 position, DoorName doorname);

	void CollisionToDoor();
	void ClearCheck();
	void SetRoomNumber();


	virtual void tick() {};
	


};
