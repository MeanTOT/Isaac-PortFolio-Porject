#pragma once
#include "ProjectFW.h"
#include "Bullet.h"
#include "Dregs.h"
#include "MiniMap.h"

class GameStage_2 : public Scene
{
private:

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameStage_2);

	GameStage_2();
	~GameStage_2();
};