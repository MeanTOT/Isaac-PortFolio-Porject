#include "LodingScreen1.h"

Scene * LodingScreen1::createScene()
{

	return LodingScreen1::create();
}

bool LodingScreen1::init()
{
	if (!Scene::init())
		return false;

	SMI->PlayTitleScreenJingle();

	loadingBackGround = LayerColor::create(Color4B::BLACK);
	this->addChild(loadingBackGround);

	loadingImage1 = Sprite::create("TitleMenu/loadimages-010.png");
	loadingImage1->setPosition(Position_50_50_);
	this->addChild(loadingImage1);

	loadingImage1->runAction(Sequence::create(DelayTime::create(3.5f),CallFunc::create(CC_CALLBACK_0(LodingScreen1::ToNextScene,this)),nullptr));


	return true;
}

void LodingScreen1::ToNextScene()
{
	auto scene = GameStage_1::createScene();
	DI->replaceScene(TransitionFade::create(1.0f, scene));
}


