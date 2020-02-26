#include "BossLoadingScene_Dingle.h"

Scene * BossLoadingScene_Dingle::createScene()
{
	return BossLoadingScene_Dingle::create();
}

bool BossLoadingScene_Dingle::init()
{
	if (!Scene::init())
		return false;

	SMI->PlayCastlePortCullis();
	SMI->PlayBossFightIntroJingle();

	loadingBackGround = LayerColor::create(Color4B::BLACK);
	this->addChild(loadingBackGround, - 50);

	playerPortrait = Sprite::create("BossLoading/playerportrait_01_isaac.png");
	playerPortrait->setPosition(Position_50_50_.x - 240, Position_50_50_.y - 50);
	this->addChild(playerPortrait);

	bossPortrait = Sprite::create("BossLoading/portrait_261.0_dingle.png");
	bossPortrait->setPosition(Position_50_50_.x + 240, Position_50_50_.y - 45);
	this->addChild(bossPortrait);

	playerSpot = Sprite::create("BossLoading/playerspot_01_basement.png");
	playerSpot->setPosition(playerPortrait->getContentSize().width / 2, 10);
	playerPortrait->addChild(playerSpot , playerPortrait->getLocalZOrder() - 1);

	bossSpot = Sprite::create("BossLoading/bossspot_01_basement.png");
	bossSpot->setPosition(bossPortrait->getContentSize().width / 2, 55);
	bossPortrait->addChild(bossSpot, bossPortrait->getLocalZOrder() - 1);

	vsnames = Sprite::create("BossLoading/vsnames.png");
	vsnames->setPosition(Position_50_50_.x, Position_50_50_.y + 100);
	vsnames->setOpacity(0);
	vsnames->setScale(2.0f);
	this->addChild(vsnames);

	vsnamasIsaac = Sprite::create("BossLoading/vsnames_01.png");
	vsnamasIsaac->setPosition(Position_50_50_.x - 240, Position_50_50_.y + 100);
	this->addChild(vsnamasIsaac);

	vsnamesDingle = Sprite::create("BossLoading/vsnames_01.png");
	vsnamesDingle->setPosition(Position_50_50_.x + 240, Position_50_50_.y + 100);
	this->addChild(vsnamesDingle);



	playerPortrait->runAction(Sequence::create(EaseOut::create(MoveBy::create(0.5f, Vec2(100, 0)), 1), MoveBy::create(2.5f, Vec2(15, 0)),
		CallFunc::create(CC_CALLBACK_0(BossLoadingScene_Dingle::ToNextScene,this)),nullptr));
	bossPortrait->runAction(Sequence::create(EaseOut::create(MoveBy::create(0.5f, Vec2(-100, 0)), 1), MoveBy::create(2.5f, Vec2(-15, 0)), nullptr));
	vsnamasIsaac->runAction(Sequence::create(EaseOut::create(MoveBy::create(0.5f, Vec2(100, 0)), 1), MoveBy::create(2.5f, Vec2(15, 0)), nullptr));
	vsnamesDingle->runAction(Sequence::create(EaseOut::create(MoveBy::create(0.5f, Vec2(-100, 0)), 1), MoveBy::create(2.5f, Vec2(-15, 0)), nullptr));
	vsnames->runAction(Spawn::create(RotateBy::create(0.5f, Vec3(0, 0, 360)), FadeIn::create(0.5f), ScaleTo::create(0.5f, 1.0f), nullptr));

	return true;
}

BossLoadingScene_Dingle::BossLoadingScene_Dingle()
{

}

BossLoadingScene_Dingle::~BossLoadingScene_Dingle()
{
}

void BossLoadingScene_Dingle::ToNextScene()
{
	Player->setIsLoadingScene(false);
	Player->setMoveD(false);
	Player->setMoveR(false);
	Player->setMoveU(false);
	Player->setMoveD(false);
	AudioEngine::stopAll();
	SMI->PlayBasicBossFight();
	DI->popScene();
}


