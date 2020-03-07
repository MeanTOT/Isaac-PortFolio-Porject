#pragma once
#include "ProjectFW.h"
#include "GameStage_2.h"

class LoadingScreen2 : public Scene
{
private:
	LayerColor* loadingBackGround;
	Sprite* loadingImage1;
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(LoadingScreen2);

	~LoadingScreen2();

	void ToNextScene();
};