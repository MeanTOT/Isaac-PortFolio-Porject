#include "Nest.h"

Nest::Nest(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 0.5f;
	maxHp = 20.0f + (4 * Player->getStageNumber());
	hp = 20.0f + (4 * Player->getStageNumber());

	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	monsterAngle = randomAngle;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;


	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Bodies/Monster_Bodies.plist");
	cache->addSpriteFramesWithFile("Monster/Nest/Monster_Nest.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_bodies_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0, 0.f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1.f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);
	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterSubSprite = Sprite::createWithSpriteFrameName("monster_nest_01.png");
	monsterSubSprite->setPosition(position.x, position.y + 15);
	scene->addChild(monsterSubSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.15f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, -1);

	// 상하이동
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_04.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_05.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_06.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_07.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_08.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_10.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_11.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_12.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_13.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_14.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_15.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_16.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_17.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_18.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_19.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 좌우이동
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_20.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_21.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_22.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_23.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_24.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_25.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_26.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_27.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_28.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_29.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_30.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_31.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_32.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_33.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_34.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_35.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_36.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_bodies_37.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	// 머리 애니메이션
	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.15f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_nest_01.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_nest_02.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_nest_03.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();

	monsterAnimation4 = Animation::create();
	monsterAnimation4->setDelayPerUnit(0.05f);
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_01.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_02.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_03.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_04.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_05.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_06.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_07.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_08.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_09.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_10.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_11.png"));
	monsterAnimate4 = Animate::create(monsterAnimation4);
	monsterAnimate4->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

}

void Nest::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();
	FollowPlayer();

	monsterSubSprite->setPosition(monsterSprite->getPosition().x, monsterSprite->getPosition().y + 15);
}

void Nest::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
	monsterSubSprite->setLocalZOrder(monsterSprite->getLocalZOrder() + 1);
}

void Nest::FollowPlayer()
{

	if (monsterAngle >= 90 && monsterAngle <= 270)
	{
		monsterSprite->setFlippedX(true);
		monsterSubSprite->setFlippedX(true);
	}
	else
	{
		monsterSprite->setFlippedX(false);
		monsterSubSprite->setFlippedX(false);
	}
	
	if (monsterAngle >= 45 && monsterAngle <= 135) // 위를 본다
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate);
	}
	else if (monsterAngle > 135 && monsterAngle < 225) // 왼쪽
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate2);
	}
	else if (monsterAngle > 225 && monsterAngle < 315) // 아래
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate);
	}
	else // 오른쪽
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate2);
	}

	monsterSprite->setPosition(monsterSprite->getPosition().x + cosf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed,
		monsterSprite->getPosition().y + sinf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed);

	log("%f", monsterAngle);
}

void Nest::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Nest::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (!monsterSubSprite->getNumberOfRunningActions())
			monsterSubSprite->runAction(monsterAnimate3);
	}

	if (monsterSprite->getTag() == MonsterColiisionBullet)
	{
		hp -= Player->getEffectiveDmg();

		monsterSprite->setTag(MonsterIdle);

		if (hp <= 0)
			return;

		this->HitEffect();
	}

	if (hp <= 0 && monsterSprite->getTag() != MonsterErase)
	{
		_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectMonster, monsterSprite->getLocalZOrder());
		effectBlood = new EffectBlood(_scene, monsterSprite->getPosition(), MonsterKind_Horf);

		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

		FlyMaker[0] = new Fly(_scene, monsterSprite->getPosition());
		FlyMaker[1] = new Fly(_scene, monsterSprite->getPosition());

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate4, CallFunc::create(CC_CALLBACK_0(Nest::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
		monsterSprite->setTag(MonsterErase);
		monsterSubSprite->setVisible(false);
		monsterSubSprite->runAction(Sequence::createWithTwoActions(DelayTime::create(3), RemoveSelf::create()));

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
	}
}

void Nest::MonsterEraseCall()
{

}

void Nest::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
		AttackCycle--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 100;


		auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

		monsterAngle = randomAngle;

		if (RGI->getPercentage(0.3f))
		{
			SMI->PlayScaredWhimper2();
		}

		monsterSprite->stopAllActions();

	}
}

void Nest::CreateBullet()
{
}
