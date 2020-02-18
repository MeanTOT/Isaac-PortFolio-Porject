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
	

	// ------- Float ------- //

	// [Isaac Info] //
	MoveSpeed = 25.0f;
	BulletFireCycle = 0.15f;
	bulletRange = 450.0f;
	bulletMoveSpeed = 3000.0f;
	basicHeight = 15.0f;
	maxHeight = 15.0f;




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

	for (int i = 0; i < 10; i++)
	{
		HeartIcon[i] = Sprite::create("UI/ui_hearts_01.png");
		HeartIcon[i]->setAnchorPoint({ 0,0 });

		scene->addChild(HeartIcon[i]);
	}

}

void Isaac::tick()
{
	IsaacMoving();
	BulletFire();
	IsaacSetZoder();
	setUIPosition();

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
				isaacHead_Base->setFlippedX(false);
				isaacHead_Base->setSpriteFrame("IsaacHead3.png");
			}
		}
		if (MoveL)
		{
			isaacPhysicBody->applyImpulse(Vect(-MoveSpeed, 0));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				isaacHead_Base->setFlippedX(true);
				isaacHead_Base->setSpriteFrame("IsaacHead3.png");
			}
		}
		if (MoveU)
		{
			isaacPhysicBody->applyImpulse(Vect(0, MoveSpeed));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				isaacHead_Base->setSpriteFrame("IsaacHead5.png");
			}
		}
		if (MoveD)
		{
			isaacPhysicBody->applyImpulse(Vect(0, -MoveSpeed));

			if (!isaacHead_Base->getNumberOfRunningActions())
			{
				isaacHead_Base->setSpriteFrame("IsaacHead1.png");
			}
		}



		if (MoveU)
		{
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				isaacBody_Base->runAction(IsaacWalkAnimateUD);
			}
		}
		else if (MoveD)
		{
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				isaacBody_Base->runAction(IsaacWalkAnimateUD);
			}
		}
		else if (MoveR)
		{
			isaacBody_Base->setFlippedX(false);
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				isaacBody_Base->runAction(IsaacWalkAnimateRL);
			}
		}
		else if (MoveL)
		{
			isaacBody_Base->setFlippedX(true);
			if (!isaacBody_Base->getNumberOfRunningActions())
			{
				isaacBody_Base->runAction(IsaacWalkAnimateRL);
			}
		}

		if (!MoveR && !MoveL && !MoveU && !MoveD)
		{
			isaacBody_Base->stopAllActions();
			isaacBody_Base->setSpriteFrame("IsaacWalk_UD (4).png");
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
	coinUiIcon->setPosition(CI->camera->getPosition().x - 200, CI->camera->getPosition().y + 88);
	bombUiIcon->setPosition(CI->camera->getPosition().x - 200, CI->camera->getPosition().y + 74);
	keyUiIcon->setPosition(CI->camera->getPosition().x - 200, CI->camera->getPosition().y + 60);

	coinUitext->setPosition(CI->camera->getPosition().x - 190, CI->camera->getPosition().y + 88);
	bombUitext->setPosition(CI->camera->getPosition().x - 190, CI->camera->getPosition().y + 74);
	keyUitext->setPosition(CI->camera->getPosition().x - 190, CI->camera->getPosition().y + 60);

	bombUitext->setString(String::createWithFormat("%02d", BombCount)->_string.c_str());
	coinUitext->setString(String::createWithFormat("%02d", coinCount)->_string.c_str());
	keyUitext->setString(String::createWithFormat("%02d", keyCount)->_string.c_str());

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			HeartIcon[i]->setPosition(CI->camera->getPosition().x - 150, CI->camera->getPosition().y + 110);
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

 