#pragma once
#include "ProjectFW.h"
#include "GameStage_1.h"
#include "GameStage_2.h"

class LodingScreen1 : public Scene
{
private:
	LayerColor* loadingBackGround;
	Sprite* loadingImage1;
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LodingScreen1);

	~LodingScreen1();

	void ToNextScene();
};