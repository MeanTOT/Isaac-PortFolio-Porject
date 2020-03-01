#pragma once
#include "ProjectFW.h"
#include "MapCase_11.h"
#include "MapCase_12.h"
#include "MapCase_13.h"
#include "MapCase_14.h"
#include "Bullet.h"
#include "Dregs.h"
#include "MiniMap.h"

class GameStage_2 : public Scene
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
	CREATE_FUNC(GameStage_2);

	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; }
	void tick(float delta);

	void onEnterTransitionDidFinish();
};