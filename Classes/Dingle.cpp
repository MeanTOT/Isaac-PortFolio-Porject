#include "Dingle.h"
#include "EffectPoof.h"

Dingle::Dingle(Scene * scene, Vec2 position)
{
	monsterHeight = 20.0f;
	monsterMoveSpeed = 4000.0f;
	mosnterBulletMoveSpeed = 200.0f;
	maxHp = 3.0f; // 원래 330
	hp = 3.0f; // 원래 330

	AttackCycle = 200;

	dingleInfo = DingleLeft;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Dingle/Boss_Dingle.plist");
	cache->addSpriteFramesWithFile("Bullet/Effect_ShitPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("boss_dingle_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 6, PhysicsMaterial(0.05f, 1.f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(0.5f);
	//monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	bossHpBar = ProgressTimer::create(Sprite::create("UI/ui_bosshealthbar_01.png"));
	bossHpBar->setType(ProgressTimer::Type::BAR);
	bossHpBar->setPosition(position.x, position.y + 100);
	bossHpBar->setMidpoint({ 0,0 });
	bossHpBar->setBarChangeRate({ 1,0 });
	scene->addChild(bossHpBar, 10000);

	bossHpBackBar = Sprite::create("UI/ui_bosshealthbar_02.png");
	bossHpBackBar->setPosition(position.x, position.y + 100);
	scene->addChild(bossHpBackBar, bossHpBar->getLocalZOrder() - 1);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.2f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - 10);
	monsterSprite->addChild(monsterShadowSprite, -1);

	// 기본상태
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_03.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();
	monsterAnimate->setTag(1);

	// 총알발사스킬
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_04.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_05.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_16.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	// 돌진공격
	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.06f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_23.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_24.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_11.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_12.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_13.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_14.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_11.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_12.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_13.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_14.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_17.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_18.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_19.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();

	// 돌진공격이후 휴식
	monsterAnimation4 = Animation::create();
	monsterAnimation4->setDelayPerUnit(0.1f);
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_28.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_29.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_28.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_29.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_28.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_29.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_28.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_29.png"));
	monsterAnimate4 = Animate::create(monsterAnimation4);
	monsterAnimate4->retain();

	// 휘파람 Dip 소환 스킬
	monsterAnimation5 = Animation::create();
	monsterAnimation5->setDelayPerUnit(0.1f);
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_04.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_05.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_06.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_20.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_21.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_21.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_21.png"));
	monsterAnimate5 = Animate::create(monsterAnimation5);
	monsterAnimate5->retain();

	// 총알 발사 전 기모으기
	monsterAnimation6 = Animation::create();
	monsterAnimation6->setDelayPerUnit(0.1f);
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_31.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_32.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_33.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_34.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_35.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_36.png"));
	monsterAnimate6 = Animate::create(monsterAnimation6);
	monsterAnimate6->retain();

	// 죽을때
	monsterAnimation7 = Animation::create();
	monsterAnimation7->setDelayPerUnit(0.1f);
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_38.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_39.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_40.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_41.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_42.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_43.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_44.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_45.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_46.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_47.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_48.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_49.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_50.png"));
	monsterAnimation7->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_51.png"));
	monsterAnimate7 = Animate::create(monsterAnimation7);
	monsterAnimate7->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

}

void Dingle::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();

	/*if (!monsterSprite->getNumberOfRunningActions())
		monsterSprite->runAction(monsterAnimate);*/

	if (Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x)
	{
		dingleInfo = DingleRight;
	}
	if (Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x)
	{
		dingleInfo = DingleLeft;
	}
	if (Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y)
	{
		dingleInfo = DingleBottom;
	}
	if (Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y)
	{
		dingleInfo = DingleTop;
	}

	bossHpBar->setPercentage((hp / maxHp) * 100);
}

void Dingle::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
}

void Dingle::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Dingle::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate);
	}

	if (monsterSprite->getTag() == MonsterColiisionBullet)
	{
		hp -= Player->getEffectiveDmg();
		monsterSprite->setTag(MonsterIdle);

		if (hp <= 0)
			return;

		this->HitEffect();
	}

	if (hp <= 30 && monsterSprite->getTag() != MonsterErase)
	{
		_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectPoop, monsterSprite->getLocalZOrder());

		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate7, CallFunc::create(CC_CALLBACK_0(Dingle::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
		monsterSprite->setTag(MonsterErase);

		auto randomindex = RGI->getRandomNumberWithRange(1, 5);

		switch (randomindex)
		{
		case 1:
			SMI->PlayMeatyDeaths1();
			break;
		case 2:
			SMI->PlayMeatyDeaths2();
			break;
		case 3:
			SMI->PlayMeatyDeaths3();
			break;
		case 4:
			SMI->PlayMeatyDeaths4();
			break;
		case 5:
			SMI->PlayMeatyDeaths5();
			break;
		default:
			break;
		}

		bossHpBar->setVisible(false);
		bossHpBackBar->setVisible(false);
	}
}

void Dingle::MonsterEraseCall()
{

}

void Dingle::DoAttack()
{
	if (monsterSprite->getNumberOfRunningActionsByTag(1))
		AttackCycle--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 100;

		auto randomAttack = RGI->getRandomNumberWithRange(1, 2);

		if (Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y - 30 && Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y + 30 && randomAttack == 1 ||
			Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 30 && Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 30 && randomAttack == 1)
		{
			monsterSprite->stopAllActions();
			monsterSprite->setTag(MonsterAttack);
			monsterSprite->runAction(Sequence::create(monsterAnimate6,CallFunc::create(CC_CALLBACK_0(Dingle::DIngleBulletFireSound,this)),
				CallFunc::create(CC_CALLBACK_0(Dingle::CreateBullet, this)),
				monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Dingle::ChangeTag, this)), nullptr));
		}
		else
		{
			auto randomAction = RGI->getPercentage(0.5f);

			if (randomAction)
			{
				monsterSprite->stopAllActions();
				monsterSprite->setTag(MonsterAttack);
				monsterSprite->runAction(Sequence::create(monsterAnimate6, CallFunc::create(CC_CALLBACK_0(Dingle::DingleRushSound,this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::RushAttack, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::CreateTrace, this)),
					monsterAnimate3, monsterAnimate6, CallFunc::create(CC_CALLBACK_0(Dingle::DingleRushSound, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::RushAttack, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::CreateTrace, this)), monsterAnimate3,
					monsterAnimate6, CallFunc::create(CC_CALLBACK_0(Dingle::DingleRushSound, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::RushAttack, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::CreateTrace, this)), monsterAnimate3,
					CallFunc::create(CC_CALLBACK_0(Dingle::ChangeTag, this)), nullptr));
			}
			else
			{
				SMI->PlayDingleWhistle();
				monsterSprite->stopAllActions();
				monsterSprite->setTag(MonsterAttack);
				monsterSprite->runAction(Sequence::create(monsterAnimate5, CallFunc::create(CC_CALLBACK_0(Dingle::SommonsDip, this)),
					CallFunc::create(CC_CALLBACK_0(Dingle::ChangeTag, this)), nullptr));
			}
		}
	}
}

void Dingle::CreateBullet()
{

	auto _monsterBullet1 = new MonsterBullet;
	auto _monsterBullet2 = new MonsterBullet;
	auto _monsterBullet3 = new MonsterBullet;

	if (Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y - 70 && Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y + 70 &&
		Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x)
	{
		_monsterBullet1->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), mosnterBulletMoveSpeed, 0, 30);
		_monsterBullet2->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), mosnterBulletMoveSpeed, -45, 30);
		_monsterBullet3->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), mosnterBulletMoveSpeed, 45, 30);
	}
	else if (Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y - 70 && Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y + 70 &&
		Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x)
	{
		_monsterBullet1->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), -mosnterBulletMoveSpeed, 0, 30);
		_monsterBullet2->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), -mosnterBulletMoveSpeed, -45, 30);
		_monsterBullet3->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), -mosnterBulletMoveSpeed, 45, 30);
	}
	else if (Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 70 && Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 70 &&
		Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y)
	{
		_monsterBullet1->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), 0  , mosnterBulletMoveSpeed ,30);
		_monsterBullet2->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), -45, mosnterBulletMoveSpeed ,30);
		_monsterBullet3->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), 45, mosnterBulletMoveSpeed ,30);
	}
	else if (Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 70 && Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 70 &&
		Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y)
	{
		_monsterBullet1->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), 0,-mosnterBulletMoveSpeed, 30);
		_monsterBullet2->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), -45,-mosnterBulletMoveSpeed, 30);
		_monsterBullet3->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 20), 45,-mosnterBulletMoveSpeed, 30);
	}
}

void Dingle::RushAttack()
{
	if (monsterSprite->getPositionX() > Player->getIsaacBody()->getPositionX())
		monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed, 0));
	else if (monsterSprite->getPositionX() < Player->getIsaacBody()->getPositionX())
		monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed, 0));

	if (monsterSprite->getPositionY() > Player->getIsaacBody()->getPositionY())
		monsterPhysics->applyImpulse(Vec2(0, -monsterMoveSpeed));
	else if (monsterSprite->getPositionY() < Player->getIsaacBody()->getPositionY())
		monsterPhysics->applyImpulse(Vec2(0, monsterMoveSpeed));
}

void Dingle::SommonsDip()
{
	auto HorfMaker1 = new EffectPoof(_scene, Vec2(monsterSprite->getPosition().x - 32, monsterSprite->getPosition().y), MonsterKind_Dip);
}

void Dingle::CreateTrace()
{
	auto randomTraceIndex = RGI->getRandomNumberWithRange(1, 6);

	switch (randomTraceIndex)
	{
	case 1:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_53.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	case 2:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_54.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	case 3:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_55.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	case 4:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_56.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	case 5:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_57.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	case 6:
	{
		auto dingleTrace = Sprite::createWithSpriteFrameName("boss_dingle_58.png");
		dingleTrace->setPosition(monsterSprite->getPosition());
		_scene->addChild(dingleTrace, -5000);
	}
	break;
	default:
		break;
	}
}

void Dingle::DingleRushSound()
{
	SMI->PlayDingleRush();
}

void Dingle::DIngleBulletFireSound()
{
	SMI->PlayDingleBulletFire();
}
