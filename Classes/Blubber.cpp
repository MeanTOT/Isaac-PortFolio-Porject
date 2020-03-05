#include "Blubber.h"

Blubber::Blubber(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 0.5f;
	maxHp = 16.0f + (4 * Player->getStageNumber());
	hp = 16.0f + (4 * Player->getStageNumber());
	mosnterBulletMoveSpeed = 200.f;

	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	monsterAngle = randomAngle;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;

	auto randomCycle2 = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle2 = randomCycle2;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Blubber/Monster_Blubber.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_blubber_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0, 0.f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1.f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);
	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.15f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, -1);

	// 좌우이동
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_04.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_05.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_06.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_07.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_08.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_09.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_10.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_11.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_12.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 상하이동
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_14.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_17.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_18.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_19.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_20.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_21.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_22.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_23.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_24.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_blubber_25.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

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

void Blubber::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();
	FollowPlayer();
}

void Blubber::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
}

void Blubber::FollowPlayer()
{

	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (monsterAngle >= 90 && monsterAngle <= 270)
		{
			monsterSprite->setFlippedX(true);
		}
		else
		{
			monsterSprite->setFlippedX(false);
		}

		if (monsterAngle >= 45 && monsterAngle <= 135) // 위를 본다
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate2);

		}
		else if (monsterAngle > 135 && monsterAngle < 225) // 왼쪽
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate);

		}
		else if (monsterAngle > 225 && monsterAngle < 315) // 아래
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate2);

		}
		else // 오른쪽
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate);

		}

		monsterSprite->setPosition(monsterSprite->getPosition().x + cosf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed,
			monsterSprite->getPosition().y + sinf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed);
	}


}

void Blubber::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Blubber::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{

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

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate4, CallFunc::create(CC_CALLBACK_0(Blubber::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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
	}
}

void Blubber::MonsterEraseCall()
{

}

void Blubber::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		AttackCycle--;
	}

	AttackCycle2--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 100;

		auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

		monsterAngle = randomAngle;

		monsterSprite->stopAllActions();
	}

	if (AttackCycle2 <= 0)
	{
		AttackCycle2 = 150;

		monsterSprite->stopAllActions();

		auto _monsterBullet1 = new MonsterBullet;
		auto _monsterBullet2 = new MonsterBullet;
		auto _monsterBullet3 = new MonsterBullet;
		auto _monsterBullet4 = new MonsterBullet;
		auto _monsterBullet5 = new MonsterBullet;

		auto randomAngle1 = RGI->getRandomNumberWithRange(0, 360);
		auto randomAngle2 = RGI->getRandomNumberWithRange(0, 360);
		auto randomAngle3 = RGI->getRandomNumberWithRange(0, 360);
		auto randomAngle4 = RGI->getRandomNumberWithRange(0, 360);
		auto randomAngle5 = RGI->getRandomNumberWithRange(0, 360);

		auto randomHeight1 = RGI->getRandomNumberWithRange(10, 30);
		auto randomHeight2 = RGI->getRandomNumberWithRange(10, 30);
		auto randomHeight3 = RGI->getRandomNumberWithRange(10, 30);
		auto randomHeight4 = RGI->getRandomNumberWithRange(10, 30);
		auto randomHeight5 = RGI->getRandomNumberWithRange(10, 30);

		_monsterBullet1->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y), mosnterBulletMoveSpeed, randomAngle1, randomHeight1);
		_monsterBullet2->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y), mosnterBulletMoveSpeed, randomAngle2, randomHeight2);
		_monsterBullet3->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y), mosnterBulletMoveSpeed, randomAngle3, randomHeight3);
		_monsterBullet4->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y), mosnterBulletMoveSpeed, randomAngle4, randomHeight4);
		_monsterBullet5->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y), mosnterBulletMoveSpeed, randomAngle5, randomHeight5);
	}

}

void Blubber::CreateBullet()
{
}
