#pragma once
#include "ProjectFW.h"
#include "MapCase_1.h"
#include "MapCase_2.h"
#include "MapCase_3.h"
#include "MapCase_4.h"
#include "MapCase_5.h"
#include "Bullet.h"

class GameStage_1 : public Scene
{
private:
	PhysicsWorld* sceneWorld;

	MapCase_1* mapCase_1;
	MapCase_2* mapCase_2;
	MapCase_3* mapCase_3;
	MapCase_4* mapCase_4;
	MapCase_5* mapCase_5;

	PhysicsBody* edgeSegment[8];
	Node* edgeNode[8];

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameStage_1);

	void SetPhysicsWorld(PhysicsWorld* world) { sceneWorld = world; }
	void tick(float delta);

	void onEnterTransitionDidFinish();
};