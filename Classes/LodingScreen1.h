#pragma once
#include "ProjectFW.h"
#include "GameStage_1.h"

class LodingScreen1 : public Scene
{
private:
	LayerColor* loadingBackGround;
	Sprite* loadingImage1;
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LodingScreen1);

	void ToNextScene();
};