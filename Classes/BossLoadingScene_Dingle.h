#pragma once
#include "ProjectFW.h"

class BossLoadingScene_Dingle : public Scene
{
private:
	LayerColor* loadingBackGround;
	Sprite* playerPortrait;
	Sprite* bossPortrait;
	Sprite* bossSpot;
	Sprite* playerSpot;
	Sprite* vsnames;
	Sprite* vsnamasIsaac;
	Sprite* vsnamesDingle;

public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(BossLoadingScene_Dingle);

	BossLoadingScene_Dingle();
	~BossLoadingScene_Dingle();

	void ToNextScene();
};