#include "MapCase_1.h"

MapCase_1::MapCase_1(Scene* scene, Vec2 position)
{

	controlsImage = Sprite::create("MapImage/controls.png");
	controlsImage->setPosition(position);
	scene->addChild(controlsImage, BackGroundZoder + 1);

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
	RoomNumber = 1;
	RoomClear = true;
	FirstEnter = false;
}

MapCase_1::~MapCase_1()
{
}

void MapCase_1::tick()
{
	if (!FirstEnter && Player->getRoomNumber() == RoomNumber)
	{
		FirstEnter = true;

	
		StageNameBackGround->setVisible(true);
		StageNameBackGround->runAction(Sequence::create(ScaleTo::create(0.2f, 1.f), CallFunc::create(CC_CALLBACK_0(MapCase_1::ShowStageNameText,this)),
			DelayTime::create(2.0f), ScaleTo::create(0.2f, 0.01f), RemoveSelf::create(),nullptr));

		log("1번방 첫입장");
	}

	
	this->CollisionToDoor();
	this->ClearCheck();
	this->SetRoomNumber();	
}

void MapCase_1::ShowStageNameText()
{
	StageNameText = Label::createWithTTF("BASEMENT I", "Fonts/upheavtt.ttf", 20);
	StageNameText->setColor(Color3B::WHITE);
	StageNameText->setVisible(true);
	StageNameText->setPosition(StageNameBackGround->getContentSize().width / 2 + 10, StageNameBackGround->getContentSize().height / 2 + 5);
	StageNameText->setAnchorPoint({ 0.5,0.5 });
	StageNameText->enableOutline(Color4B::BLACK, 1);
	StageNameBackGround->addChild(StageNameText, 5000);
}
