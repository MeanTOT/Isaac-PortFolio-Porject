#pragma once
#include "ProjectFW.h"
#include "MapCase_11.h"
#include "MapCase_12.h"
#include "MapCase_13.h"
#include "MapCase_14.h"
#include "MapCase_15.h"
#include "MapCase_16_ItemRoom2.h"
#include "MapCase_17.h"
#include "MapCase_18.h"
#include "MapCase_19.h"
#include "MapCase_20.h"
#include "MapCase_21.h"
#include "MapCase_22.h"
#include "MapCase_23_BossRoom.h"
#include "MapCase_24_ShopRoom.h"
#include "Bullet.h"
#include "Dregs.h"
#include "MiniMap.h"
#include "Bone.h"

class GameStage_2 : public Scene
{
private:
	PhysicsWorld* sceneWorld;

	MapBase* MapCase[20];

	MiniMap* miniMap;

	PhysicsBody* edgeSegment[8];
	Node* edgeNode[8];

	bool isPlayBgm;
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameStage_2);

	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; }
	void tick(float delta);

	void onEnterTransitionDidFinish();
};