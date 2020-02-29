#include "MapCase_11.h"

MapCase_11::MapCase_11(Scene* scene, Vec2 position)
{
	this->CreateBaseMentRoom(scene, position);
	this->CreateDoorL(scene, position, NormalDoor);
	this->CreateDoorT(scene, position, NormalDoor);
	this->CreateDoorB(scene, position, NormalDoor);

	StageNameBackGround = Sprite::create("ITEMS/effect_024_streak.png");
	StageNameBackGround->setPosition(CI->camera->getPosition().x, CI->camera->getPosition().y + 90);
	StageNameBackGround->setVisible(false);
	StageNameBackGround->setScaleX(0.001f);
	scene->addChild(StageNameBackGround, 100000);

	_scene = scene;
	_position = position;
	RoomNumber = 11;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_11::~MapCase_11()
{
}

void MapCase_11::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

		StageNameBackGround->setVisible(true);
		StageNameBackGround->runAction(Sequence::create(DelayTime::create(1.0f), ScaleTo::create(0.2f, 1.f),
			CallFunc::create(CC_CALLBACK_0(MapCase_11::ShowStageNameText, this)),
			DelayTime::create(2.0f), ScaleTo::create(0.2f, 0.01f), RemoveSelf::create(), nullptr));

		log("11번방 첫입장");
	}

	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();
}

void MapCase_11::ShowStageNameText()
{
	StageNameText = Label::createWithTTF("CAVES I", "Fonts/upheavtt.ttf", 20);
	StageNameText->setColor(Color3B::WHITE);
	StageNameText->setVisible(true);
	StageNameText->setPosition(StageNameBackGround->getContentSize().width / 2 + 10, StageNameBackGround->getContentSize().height / 2 + 5);
	StageNameText->setAnchorPoint({ 0.5,0.5 });
	StageNameText->enableOutline(Color4B::BLACK, 1);
	StageNameBackGround->addChild(StageNameText, 5000);
}
