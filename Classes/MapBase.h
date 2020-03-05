#pragma once
#include "ProjectFW.h"
#include "ObjectBase.h"
#include "MonsterBase.h"
#include "Rocks.h"
#include "Rocks_Cave.h"
#include "Poop.h"
#include "altar.h"
#include "Pit.h"
#include "Fire.h"
#include "Fly.h"
#include "EffectPoof.h"
#include "MushRoom.h"

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
	int clearOnDidFinishCount;
	DoorName _doorname;

	bool RoomClear;
	bool FirstEnter;
	bool isMakeDoorR;
	bool isMakeDoorL;
	bool isMakeDoorT;
	bool isMakeDoorB;
	bool clearOnDidFinish;

	Scene* _scene;
	Vec2 _position;

	Rect mapRect;
	
	Animation* DoorOpenkeyAnimation;
	Animate* DoorOpenkeyAnimate;

	Sprite* DoorOpenKey;

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

	Sprite* BossDoorLightR;
	Sprite* BossDoorLightL;
	Sprite* BossDoorLightT;
	Sprite* BossDoorLightB;


	void CreateBaseMentRoom(Scene* scene, Vec2 position);
	void CreateBaseMentBossRoom(Scene* scene, Vec2 position);
	void CreateCavesRoom(Scene* scene, Vec2 position);
	void CreateDoorL(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorR(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorT(Scene* scene, Vec2 position, DoorName doorname);
	void CreateDoorB(Scene* scene, Vec2 position, DoorName doorname);

	void CollisionToDoor();
	void ClearCheck();
	void SetRoomNumber();

	void ChangeDoorRTag();
	void ChangeDoorLTag();
	void ChangeDoorTTag();
	void ChangeDoorBTag();
	void PlayUnlockSound();

	void ClearOnDidFinishCount();


	virtual void tick() {};
	virtual void ClearOnDidFinish() {};
	


};
