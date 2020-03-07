#include "Boney.h"

Boney::Boney(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 0.5f;
	maxHp = 8.0f + (4 * Player->getStageNumber());
	hp = 8.0f + (4 * Player->getStageNumber());
	mosnterBulletMoveSpeed = 400.f;

	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	monsterAngle = randomAngle;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;
	AttackCycle2 = 30;


	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Bodies/Monster_Boney_Body.plist");
	cache->addSpriteFramesWithFile("Monster/Boney/Monster_Boney_Head.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_boney-body_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0, 0.f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1.f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);
	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterSubSprite = Sprite::createWithSpriteFrameName("monster_boney-head_02.png");
	monsterSubSprite->setPosition(position.x, position.y);
	scene->addChild(monsterSubSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.15f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, -1);

	// 상하이동
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_04.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_05.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_06.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_07.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_08.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_09.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_10.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 좌우이동
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_12.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_13.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_14.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_17.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_18.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_19.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_20.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_boney-body_21.png"));
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

void Boney::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();
	FollowPlayer();

	monsterSubSprite->setPosition(monsterSprite->getPosition().x, monsterSprite->getPosition().y + 10);
}

void Boney::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
	monsterSubSprite->setLocalZOrder(monsterSprite->getLocalZOrder() + 1);
}

void Boney::FollowPlayer()
{

	if (monsterSprite->getTag() == MonsterIdle)
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

			monsterSubSprite->setSpriteFrame("monster_boney-head_03.png");
		}
		else if (monsterAngle > 135 && monsterAngle < 225) // 왼쪽
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate2);

			monsterSubSprite->setSpriteFrame("monster_boney-head_02.png");
		}
		else if (monsterAngle > 225 && monsterAngle < 315) // 아래
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate);

			monsterSubSprite->setSpriteFrame("monster_boney-head_01.png");
		}
		else // 오른쪽
		{
			if (!monsterSprite->getNumberOfRunningActions())
				monsterSprite->runAction(monsterAnimate2);

			monsterSubSprite->setSpriteFrame("monster_boney-head_02.png");
		}

		monsterSprite->setPosition(monsterSprite->getPosition().x + cosf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed,
			monsterSprite->getPosition().y + sinf(CC_DEGREES_TO_RADIANS(monsterAngle)) * monsterMoveSpeed);
	}

	
}

void Boney::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Boney::MonsterSetTag()
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
		monsterSprite->runAction(Sequence::create(monsterAnimate4, CallFunc::create(CC_CALLBACK_0(Boney::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void Boney::MonsterEraseCall()
{

}

void Boney::DoAttack()
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
		AttackCycle2 = 30;

		if (monsterSprite->getPosition().x - 30 < Player->getIsaacBody()->getPosition().x && monsterSprite->getPosition().x + 30 > Player->getIsaacBody()->getPosition().x)
		{
			monsterSprite->stopAllActions();
			monsterSubSprite->setSpriteFrame("monster_boney-head_01.png");
			monsterSprite->setSpriteFrame("monster_boney-body_01.png");

			monsterSprite->setTag(MonsterAttack);

			auto _monsterBullet = new Bone;
			_monsterBullet->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, this->GetAngleToPlayer());

		}
		else if (monsterSprite->getPosition().y - 30 < Player->getIsaacBody()->getPosition().y && monsterSprite->getPosition().y + 30 > Player->getIsaacBody()->getPosition().y)
		{
			monsterSprite->stopAllActions();
			monsterSubSprite->setSpriteFrame("monster_boney-head_01.png");
			monsterSprite->setSpriteFrame("monster_boney-body_01.png");

			monsterSprite->setTag(MonsterAttack);

			auto _monsterBullet = new Bone;
			_monsterBullet->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, this->GetAngleToPlayer());

		}
		else
		{
			monsterSprite->setTag(MonsterIdle);
		}
	}
	
}

void Boney::CreateBullet()
{
}
