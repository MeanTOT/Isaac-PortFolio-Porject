#include "Isaac.h"
#include "ObjectBase.h"
#include "Bullet.h"
#include "IsaacBoom.h"

Isaac* Isaac::instance = nullptr;

Isaac::Isaac()
{

	// ------- Plist ------- //

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Player/IsaacHead_Base.plist");
	cache->addSpriteFramesWithFile("Player/IsaacWalk_Base.plist");
	cache->addSpriteFramesWithFile("Player/IsaacInfo.plist");
	cache->addSpriteFramesWithFile("Player/GetItemAction.plist");
	cache->addSpriteFramesWithFile("MapImage/Door/TreasureDoor_KeyAnimation.plist");
	


	// ------- Int ------- //

	// [index] //
	mainMenuIndex = 1;
	charSelectIndex = 0;
	difficultySelectIndex = 0;
	OptionIndex = 0;
	OptionSfxIndex = 2;
	OptionBgmIndex = 2;

	// [Isaac Info] //
	BombCount = 1;
	coinCount = 0;
	keyCount = 0;
	MaxHp = 6;
	Hp = 6;
	stageNumber = 1;
	godModeCount1 = 15;
	godModeCount2 = 10;
	getItemCount1 = 100;
	

	// ------- Float ------- //

	// [Isaac Info] //
	MoveSpeed = 25.0f;
	BulletFireCycle = 0.15f;
	bulletRange = 450.0f;
	bulletMoveSpeed = 3000.0f;
	basicHeight = 15.0f;
	maxHeight = 15.0f;
	BaseDmg = 3.5f;
	totalDmgUps = 0.0f;
	effectiveDmg = BaseDmg * sqrt(totalDmgUps * 1.2 + 1);
	totalLuck = 1.0f;
	BaseLuck = 10.0f;
	itemInvLuck = totalLuck / BaseLuck;



	// ------- Bool ------- //

	ControlAtivation = true;
	SceneChange = false;

	MoveR = false;
	MoveL = false;
	MoveU = false;
	MoveD = false;

	BulletFireR = false;
	BulletFireL = false;
	BulletFireU = false;
	BulletFireD = false;

	BombActivation = false;

	GodMode = false;

	isIsaacGetItem = false;

	isShowDebug = false;

	isLoadingScene = false;

	// ------- First Scene ------- //

	nowScene = PressStartScene;


	// ------- Animation ------- //

	BulletFireAnimatioR = Animation::create();
	BulletFireAnimatioR->setDelayPerUnit(BulletFireCycle);
	BulletFireAnimatioR->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead4.png"));
	BulletFireAnimatioR->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead3.png"));
	BulletFireAnimateR = Animate::create(BulletFireAnimatioR);
	BulletFireAnimateR->setTag(BulletVectorR);
	BulletFireAnimateR->retain();

	BulletFireAnimatioL = Animation::create();
	BulletFireAnimatioL->setDelayPerUnit(BulletFireCycle);
	BulletFireAnimatioL->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead4.png"));
	BulletFireAnimatioL->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead3.png"));
	BulletFireAnimateL = Animate::create(BulletFireAnimatioL);
	BulletFireAnimateL->setTag(BulletVectorL);
	BulletFireAnimateL->retain();

	BulletFireAnimatioU = Animation::create();
	BulletFireAnimatioU->setDelayPerUnit(BulletFireCycle);
	BulletFireAnimatioU->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead6.png"));
	BulletFireAnimatioU->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead5.png"));
	BulletFireAnimateU = Animate::create(BulletFireAnimatioU);
	BulletFireAnimateU->setTag(BulletVectorU);
	BulletFireAnimateU->retain();

	BulletFireAnimatioD = Animation::create();
	BulletFireAnimatioD->setDelayPerUnit(BulletFireCycle);
	BulletFireAnimatioD->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead2.png"));
	BulletFireAnimatioD->addSpriteFrame(cache->getSpriteFrameByName("IsaacHead1.png"));
	BulletFireAnimateD = Animate::create(BulletFireAnimatioD);
	BulletFireAnimateD->setTag(BulletVectorD);
	BulletFireAnimateD->retain();

	IsaacWalkAnimationRL = Animation::create();
	IsaacWalkAnimationRL->setDelayPerUnit(0.05f);
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (1).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (2).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (3).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (4).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (5).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (6).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (7).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (8).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (9).png"));
	IsaacWalkAnimationRL->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_RL (10).png"));
	IsaacWalkAnimateRL = Animate::create(IsaacWalkAnimationRL);
	IsaacWalkAnimateRL->setTag(WalkRightLeft);
	IsaacWalkAnimateRL->retain();

	IsaacWalkAnimationUD = Animation::create();
	IsaacWalkAnimationUD->setDelayPerUnit(0.05f);
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (1).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (2).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (3).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (4).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (5).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (6).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (7).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (8).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (9).png"));
	IsaacWalkAnimationUD->addSpriteFrame(cache->getSpriteFrameByName("IsaacWalk_UD (10).png"));
	IsaacWalkAnimateUD = Animate::create(IsaacWalkAnimationUD);
	IsaacWalkAnimateUD->setTag(WalkUpDown);
	IsaacWalkAnimateUD->retain();

	DoorOpenkeyAnimation = Animation::create();
	DoorOpenkeyAnimation->setDelayPerUnit(0.1f);
	DoorOpenkeyAnimation->addSpriteFrame(cache->getSpriteFrameByName("treasureroomdoor_keyanimation_01.png"));
	DoorOpenkeyAnimation->addSpriteFrame(cache->getSpriteFrameByName("treasureroomdoor_keyanimation_02.png"));
	DoorOpenkeyAnimation->addSpriteFrame(cache->getSpriteFrameByName("treasureroomdoor_keyanimation_03.png"));
	DoorOpenkeyAnimation->addSpriteFrame(cache->getSpriteFrameByName("treasureroomdoor_keyanimation_04.png"));
	DoorOpenkeyAnimate = Animate::create(DoorOpenkeyAnimation);
	DoorOpenkeyAnimate->retain();

	GetItemAnimation = Animation::create();
	GetItemAnimation->setDelayPerUnit(0.05f);
	GetItemAnimation->addSpriteFrame(cache->getSpriteFrameByName("character_isaac_1.png"));
	GetItemAnimation->addSpriteFrame(cache->getSpriteFrameByName("character_isaac_2.png"));
	GetItemAnimation->addSpriteFrame(cache->getSpriteFrameByName("character_isaac_3.png"));
	GetItemAnimate = Animate::create(GetItemAnimation);
	GetItemAnimate->retain();
}

Isaac * Isaac::getInstance()
{
	if (!instance)
		instance = new Isaac;

	return instance;
}

void Isaac::releaseInstance()
{
	if (instance)
		delete instance;
}

void Isaac::CreateIsaac(Scene* scene)
{
	_scene = scene;

	DoorOpenKey = Sprite::createWithSpriteFrameName("treasureroomdoor_key.png");
	DoorOpenKey->setPosition(Position_50_50_);
	DoorOpenKey->setVisible(false);
	scene->addChild(DoorOpenKey);

	// 몸통 //
	isaacBody_Base = Sprite::createWithSpriteFrameName("IsaacWalk_UD (4).png");
	isaacBody_Base->setPosition(Position_50_50_);

	isaacPhysicBody = PhysicsBody::createCircle(isaacBody_Base->getContentSize().width / 4, PhysicsMaterial(0, 0, 0));
	isaacPhysicBody->setLinearDamping(5.0f);
	isaacPhysicBody->setContactTestBitmask(true);
	isaacBody_Base->addComponent(isaacPhysicBody);

	scene->addChild(isaacBody_Base, 100000);

	// 머리 //
	isaacHead_Base = Sprite::createWithSpriteFrameName("IsaacHead1.png");
	isaacHead_Base->setPosition(isaacBody_Base->getContentSize().width / 2, isaacBody_Base->getContentSize().height / 2 + 12);
	isaacBody_Base->addChild(isaacHead_Base);


	// 그림자 //
	isaacShadow = Sprite::create("Player/shadow.png");
	isaacShadow->setOpacity(100);
	isaacShadow->setScale(0.15f);
	isaacShadow->setPosition(isaacBody_Base->getContentSize().width / 2, isaacBody_Base->getContentSize().height / 2 - 7);
	isaacBody_Base->addChild(isaacShadow, -2);

	// 아이템 먹었을때 아이콘
	getItemSprite = Sprite::create("ITEMS/collectibles_138_stigmata.png");
	getItemSprite->setPosition(isaacBody_Base->getContentSize().width / 2, isaacBody_Base->getContentSize().height / 2 + 15);
	getItemSprite->setVisible(false);
	isaacBody_Base->addChild(getItemSprite);

	getItemBackGround = Sprite::create("ITEMS/effect_024_streak.png");
	getItemBackGround->setVisible(false);
	getItemBackGround->setScaleX(0.001f);
	scene->addChild(getItemBackGround);

	// 소비아이템 아이콘 
	coinUiIcon = Sprite::create("UI/StagePlayerUI_01.png");
	bombUiIcon = Sprite::create("UI/StagePlayerUI_04.png");
	keyUiIcon = Sprite::create("UI/StagePlayerUI_02.png");
	scene->addChild(coinUiIcon, 5000);
	scene->addChild(bombUiIcon, 5000);
	scene->addChild(keyUiIcon, 5000);

	coinUitext = Label::createWithTTF("0", "Fonts/upheavtt.ttf",12);
	coinUitext->setColor(Color3B::WHITE);
	coinUitext->setAnchorPoint({ 0,0.5 });
	coinUitext->enableOutline(Color4B::BLACK, 1);
	scene->addChild(coinUitext, 5000);
	bombUitext = Label::createWithTTF("0","Fonts/upheavtt.ttf", 12);
	bombUitext->setColor(Color3B::WHITE);
	bombUitext->setAnchorPoint({ 0,0.5 });
	bombUitext->enableOutline(Color4B::BLACK, 1);
	scene->addChild(bombUitext, 5000);
	keyUitext = Label::createWithTTF("0","Fonts/upheavtt.ttf", 12);
	keyUitext->setColor(Color3B::WHITE);
	keyUitext->setAnchorPoint({ 0,0.5 });
	keyUitext->enableOutline(Color4B::BLACK, 1);
	scene->addChild(keyUitext, 5000);

	showDebug_moveSeepd = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_moveSeepd->setColor(Color3B::WHITE);
	showDebug_moveSeepd->setAnchorPoint({ 0,0.5 });
	showDebug_moveSeepd->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_moveSeepd, 5000);
	showDebug_FireCycle = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_FireCycle->setColor(Color3B::WHITE);
	showDebug_FireCycle->setAnchorPoint({ 0,0.5 });
	showDebug_FireCycle->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_FireCycle, 5000);
	showDebug_bulletRange = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_bulletRange->setColor(Color3B::WHITE);
	showDebug_bulletRange->setAnchorPoint({ 0,0.5 });
	showDebug_bulletRange->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_bulletRange, 5000);
	showDebug_bulletMoveSpeed = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_bulletMoveSpeed->setColor(Color3B::WHITE);
	showDebug_bulletMoveSpeed->setAnchorPoint({ 0,0.5 });
	showDebug_bulletMoveSpeed->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_bulletMoveSpeed, 5000);
	showDebug_effectiveDmg = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_effectiveDmg->setColor(Color3B::WHITE);
	showDebug_effectiveDmg->setAnchorPoint({ 0,0.5 });
	showDebug_effectiveDmg->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_effectiveDmg, 5000);
	showDebug_ItemInvLuck = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 12);
	showDebug_ItemInvLuck->setColor(Color3B::WHITE);
	showDebug_ItemInvLuck->setAnchorPoint({ 0,0.5 });
	showDebug_ItemInvLuck->enableOutline(Color4B::BLACK, 1);
	scene->addChild(showDebug_ItemInvLuck, 5000);
	getItemInfoText1 = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 20);
	getItemInfoText1->setColor(Color3B::WHITE);
	getItemInfoText1->setVisible(false);
	getItemInfoText1->setAnchorPoint({ 0.5,0.5 });
	getItemInfoText1->enableOutline(Color4B::BLACK, 1);
	scene->addChild(getItemInfoText1, 5000);
	getItemInfoText2 = Label::createWithTTF("0", "Fonts/upheavtt.ttf", 14);
	getItemInfoText2->setColor(Color3B::WHITE);
	getItemInfoText2->setVisible(false);
	getItemInfoText2->setAnchorPoint({ 0.5,0.5 });
	getItemInfoText2->enableOutline(Color4B::BLACK, 1);
	scene->addChild(getItemInfoText2, 5000);

	showDebug_moveSeepd->setVisible(false);
	showDebug_FireCycle->setVisible(false);
	showDebug_bulletRange->setVisible(false);
	showDebug_bulletMoveSpeed->setVisible(false);
	showDebug_effectiveDmg->setVisible(false);
	showDebug_ItemInvLuck->setVisible(false);

	for (int i = 0; i < 10; i++)
	{
		HeartIcon[i] = Sprite::create("UI/ui_hearts_01.png");
		HeartIcon[i]->setAnchorPoint({ 0,0 });

		scene->addChild(HeartIcon[i]);
	}

	_isaacInfo = IsaacIdle;

}

void Isaac::tick()
{
	IsaacMoving();
	BulletFire();
	IsaacSetZoder();
	setUIPosition();
	SetGodMode();

	if (isIsaacGetItem)
	{
		getItemCount1--;


		if (getItemCount1 <= 0)
		{
			IsaacChangeInfo1();
			getItemCount1 = 100;
		}
	}

	effectiveDmg = BaseDmg * sqrt(totalDmgUps * 1.2 + 1);
	itemInvLuck = totalLuck / BaseLuck;

	getItemBackGround->setPosition(CI->camera->getPosition().x, CI->camera->getPosition().y + 90);
}

void Isaac::IsaacMoving()
{
	// 움직일시 아이작 머리와 몸방향 //
	if (!CI->camera->getNumberOfRunningActions())
	{
		if (MoveR)
		{
			isaacPhysicBody->applyImpulse(Vect(MoveSpeed, 0));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
				{
					isaacHead_Base->setFlippedX(false);
					isaacHead_Base->setSpriteFrame("IsaacHead3.png");
				}
			}
		}
		if (MoveL)
		{
			isaacPhysicBody->applyImpulse(Vect(-MoveSpeed, 0));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
				{
					isaacHead_Base->setFlippedX(true);
					isaacHead_Base->setSpriteFrame("IsaacHead3.png");
				}
			}
		}
		if (MoveU)
		{
			isaacPhysicBody->applyImpulse(Vect(0, MoveSpeed));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacHead_Base->setSpriteFrame("IsaacHead5.png");
			}
		}
		if (MoveD)
		{
			isaacPhysicBody->applyImpulse(Vect(0, -MoveSpeed));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacHead_Base->setSpriteFrame("IsaacHead1.png");
			}
		}

		
		if (MoveU)
		{
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacBody_Base->runAction(IsaacWalkAnimateUD);
			}
		}
		else if (MoveD)
		{
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacBody_Base->runAction(IsaacWalkAnimateUD);
			}
		}
		else if (MoveR)
		{
			isaacBody_Base->setFlippedX(false);
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacBody_Base->runAction(IsaacWalkAnimateRL);
			}
		}
		else if (MoveL)
		{
			isaacBody_Base->setFlippedX(true);
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				if (!isIsaacGetItem)
					isaacBody_Base->runAction(IsaacWalkAnimateRL);
			}
		}
		


		if (!MoveR && !MoveL && !MoveU && !MoveD)
		{
			if (!isIsaacGetItem)
			{
				isaacBody_Base->stopAllActions();
				isaacBody_Base->setSpriteFrame("IsaacWalk_UD (4).png");
			}
		}
	}
}

void Isaac::BulletFire()
{
	// 총알 발사시 Isaac 머리 방향 //
	if (BulletFireR)
	{
		if (!isaacHead_Base->getNumberOfRunningActions()) 
		{
			isaacHead_Base->setFlippedX(false);
			isaacHead_Base->runAction(BulletFireAnimateR);

			PushBackBullet();
		}
	}
	else if (BulletFireL)
	{
		if (!isaacHead_Base->getNumberOfRunningActions())
		{
			isaacHead_Base->setFlippedX(true);
			isaacHead_Base->runAction(BulletFireAnimateL);

			PushBackBullet();
		}
	}
	else if (BulletFireU)
	{
		if (!isaacHead_Base->getNumberOfRunningActions())
		{
			isaacHead_Base->runAction(BulletFireAnimateU);

			PushBackBullet();
		}
	}
	else if (BulletFireD)
	{
		if (!isaacHead_Base->getNumberOfRunningActions())
		{
			isaacHead_Base->runAction(BulletFireAnimateD);
			
			PushBackBullet();
		}
	}

	if (!BulletFireR && !BulletFireL && !BulletFireU && !BulletFireD && !isaacBody_Base->getNumberOfRunningActions() && !isaacHead_Base->getNumberOfRunningActions())
	{
		if (!isIsaacGetItem)
			isaacHead_Base->setSpriteFrame("IsaacHead1.png");
	}
}

void Isaac::PushBackBullet()
{
	Bullet* isaacBullet = new Bullet;
	isaacBullet->CreateIsaacBullet(_scene, isaacBody_Base->getPosition());
	isaacBulletVec.push_back(isaacBullet);

	bool randomsound = RGI->getPercentage(0.5f);

	if (randomsound)
		SMI->PlayTearFire4();
	if (!randomsound)
		SMI->PlayTearFire5();

}

void Isaac::IsaacSetZoder()
{
	isaacBody_Base->setLocalZOrder(isaacBody_Base->getPositionY() * -1);
}

void Isaac::CreateBomb()
{
	if (!BombActivation && BombCount > 0)
	{
		isaacBoom = new IsaacBoom(_scene, Player->getIsaacBody()->getPosition());
		BombActivation = true;
		BombCount -= 1;
	}
}

void Isaac::setUIPosition()
{
	coinUiIcon->setPosition(CI->camera->getPosition().x - 220, CI->camera->getPosition().y + 88);
	bombUiIcon->setPosition(CI->camera->getPosition().x - 220, CI->camera->getPosition().y + 74);
	keyUiIcon->setPosition(CI->camera->getPosition().x - 220, CI->camera->getPosition().y + 60);

	coinUitext->setPosition(CI->camera->getPosition().x - 210, CI->camera->getPosition().y + 88);
	bombUitext->setPosition(CI->camera->getPosition().x - 210, CI->camera->getPosition().y + 74);
	keyUitext->setPosition(CI->camera->getPosition().x - 210, CI->camera->getPosition().y + 60);

	bombUitext->setString(String::createWithFormat("%02d", BombCount)->_string.c_str());
	coinUitext->setString(String::createWithFormat("%02d", coinCount)->_string.c_str());
	keyUitext->setString(String::createWithFormat("%02d", keyCount)->_string.c_str());

	showDebug_moveSeepd->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y + 30);
	showDebug_FireCycle->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y + 16);
	showDebug_bulletRange->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y + 2);
	showDebug_bulletMoveSpeed->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y - 12);
	showDebug_effectiveDmg->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y - 26);
	showDebug_ItemInvLuck->setPosition(CI->camera->getPosition().x - 230, CI->camera->getPosition().y - 40);

	showDebug_moveSeepd->setString(String::createWithFormat("MoveSpeed : %.2f", MoveSpeed)->_string.c_str());
	showDebug_FireCycle->setString(String::createWithFormat("FireCycle : %.2f", BulletFireCycle)->_string.c_str());
	showDebug_bulletRange->setString(String::createWithFormat("BulletRange : %.2f", bulletRange)->_string.c_str());
	showDebug_bulletMoveSpeed->setString(String::createWithFormat("BulletMoveSpeed : %.2f", bulletMoveSpeed)->_string.c_str());
	showDebug_effectiveDmg->setString(String::createWithFormat("EffectiveDmg : %.2f", effectiveDmg)->_string.c_str());
	showDebug_ItemInvLuck->setString(String::createWithFormat("ItemInvLuck : %.2f", itemInvLuck)->_string.c_str());

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			HeartIcon[i]->setPosition(CI->camera->getPosition().x - 130, CI->camera->getPosition().y + 110);
		}
		else
		{
			HeartIcon[i]->setPosition(HeartIcon[i - 1]->getBoundingBox().getMaxX(), HeartIcon[i - 1]->getBoundingBox().getMinY());
		}

		if (i < MaxHp / 2)
		{
			HeartIcon[i]->setVisible(true);

			if (i < Hp / 2)
			{
				HeartIcon[i]->setTexture("UI/ui_hearts_01.png");
			}
			else if (i == Hp / 2 && Hp % 2 == 1)
				HeartIcon[i]->setTexture("UI/ui_hearts_02.png");
			else 
				HeartIcon[i]->setTexture("UI/ui_hearts_03.png");
		
		}
		else
		{
			HeartIcon[i]->setVisible(false);

		}
	}
}

void Isaac::SetGodMode()
{
	if (_isaacInfo == IsaacTakeDamage)
	{
		if (!GodMode)
		{
			Hp -= 1;

			GodMode = true;

			auto randomindex = RGI->getRandomNumberWithRange(1, 3);

			switch (randomindex)
			{
			case 1:
				SMI->PlayHurtGrunt1();
				break;
			case 2:
				SMI->PlayHurtGrunt2();
				break;
			case 3:
				SMI->PlayHurtGrunt3();
				break;
			default:
				break;
			}
		}

		godModeCount1--;

		if (godModeCount1 > 7)
		{
			isaacBody_Base->setVisible(false);
		}
		else
		{
			isaacBody_Base->setVisible(true);
		}

		if (godModeCount1 <= 0)
		{
			godModeCount1 = 15;
			godModeCount2--;
		}

		if (godModeCount2 <= 0)
		{
			isaacBody_Base->setVisible(true);
			_isaacInfo = IsaacIdle;
			godModeCount1 = 15;
			godModeCount2 = 10;
			GodMode = false;
		}
	}
}

// 아이템먹었을때 액션
void Isaac::doGetItemAction(ItemKind itemkind)
{
	//_isaacInfo = IsaacGetItem;
	isIsaacGetItem = true;

	switch (itemkind)
	{
	case StigmataITEM:
	{
		MaxHp = MaxHp + 2;
		Hp = Hp + 2;

		totalDmgUps = totalDmgUps + 0.3f;

		getItemSprite->setTexture("ITEMS/collectibles_138_stigmata.png");

		getItemInfoText1->setString("STIGMATA");
		getItemInfoText2->setString("DMG + HP up");
	}
		break;
	case TheSadOnionITEM:
	{
		BulletFireCycle -= 0.03f;

		BulletFireAnimateR->setDuration(BulletFireCycle * 2);
		BulletFireAnimateL->setDuration(BulletFireCycle * 2);
		BulletFireAnimateU->setDuration(BulletFireCycle * 2);
		BulletFireAnimateD->setDuration(BulletFireCycle * 2);

		getItemSprite->setTexture("ITEMS/collectibles_001_thesadonion.png");

		getItemInfoText1->setString("THE SAD ONION");
		getItemInfoText2->setString("Ters up");
	}
		break;
	default:
		break;
	}

	getItemInfoText1->setVisible(true);
	getItemInfoText2->setVisible(true);
	getItemInfoText1->setPosition(CI->camera->getPosition().x, CI->camera->getPosition().y + 95);
	getItemInfoText2->setPosition(CI->camera->getPosition().x, CI->camera->getPosition().y + 75);

	isaacBody_Base->stopAllActions();
	isaacBody_Base->runAction(GetItemAnimate);
	isaacHead_Base->setVisible(false);

	getItemSprite->setVisible(true);

	getItemBackGround->setVisible(true);
	getItemBackGround->runAction(ScaleTo::create(0.2f, 1.f));

	SMI->PlayPowerUp1();

}

void Isaac::IsaacChangeInfo1()
{
	isaacHead_Base->setVisible(true);
	isIsaacGetItem = false;
	getItemSprite->setVisible(false);
	getItemBackGround->runAction(ScaleTo::create(0.2f, 0.01f));
	getItemInfoText1->setVisible(false);
	getItemInfoText2->setVisible(false);
}

void Isaac::showDebugInfo()
{
	if (!isShowDebug)
	{
		isShowDebug = true;
		showDebug_moveSeepd->setVisible(true);
		showDebug_FireCycle->setVisible(true);
		showDebug_bulletRange->setVisible(true);
		showDebug_bulletMoveSpeed->setVisible(true);
		showDebug_effectiveDmg->setVisible(true);
		showDebug_ItemInvLuck->setVisible(true);
	}
	else
	{
		isShowDebug = false;
		showDebug_moveSeepd->setVisible(false);
		showDebug_FireCycle->setVisible(false);
		showDebug_bulletRange->setVisible(false);
		showDebug_bulletMoveSpeed->setVisible(false);
		showDebug_effectiveDmg->setVisible(false);
		showDebug_ItemInvLuck->setVisible(false);
	}
}
 
