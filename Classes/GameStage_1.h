#pragma once
#include "ProjectFW.h"
#include "MapCase_1.h"
#include "MapCase_2.h"
#include "MapCase_3.h"
#include "MapCase_4.h"
#include "MapCase_5.h"
#include "MapCase_6.h"
#include "MapCase_7.h"
#include "MapCase_8.h"
#include "MapCase_ItemRoom1.h"
#include "MapCase_BossRoom.h"
#include "Bullet.h"
#include "Dregs.h"
#include "MiniMap.h"
#include "GameStage_2.h"
#include "LoadingScreen2.h"

class GameStage_1 : public Scene
{
private:
	PhysicsWorld* sceneWorld;

	MapBase* MapCase[10];

	MiniMap* miniMap;

	PhysicsBody* edgeSegment[8];
	Node* edgeNode[8];

	bool isPlayBgm;

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameStage_1);

	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; }
	void tick(float delta);

	void onEnterTransitionDidFinish();
};