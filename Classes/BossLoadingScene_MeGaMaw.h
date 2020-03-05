#pragma once
#include "ProjectFW.h"

class BossLoadingScene_MeGaMaw : public Scene
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
	CREATE_FUNC(BossLoadingScene_MeGaMaw);

	BossLoadingScene_MeGaMaw();
	~BossLoadingScene_MeGaMaw();

	void ToNextScene();
};