#include "LoadingScreen2.h"

Scene * LoadingScreen2::createScene()
{

	return LoadingScreen2::create();
}

bool LoadingScreen2::init()
{
	if (!Scene::init())
		return false;

	SMI->PlayTitleScreenJingle();

	loadingBackGround = LayerColor::create(Color4B::BLACK);
	this->addChild(loadingBackGround);

	loadingImage1 = Sprite::create("LoadingImages/loadimages-001.png");
	loadingImage1->setPosition(Position_50_50_);
	this->addChild(loadingImage1);

	loadingImage1->runAction(Sequence::create(DelayTime::create(3.5f), CallFunc::create(CC_CALLBACK_0(LoadingScreen2::ToNextScene, this)), nullptr));


	return true;
}

LoadingScreen2::~LoadingScreen2()
{
}

void LoadingScreen2::ToNextScene()
{
	auto scene = GameStage_2::createScene();
	DI->replaceScene(TransitionFade::create(1.0f, scene));
}


