#include "Charger.h"

Charger::Charger(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 0.5f;
	maxHp = 20.0f + (4 * Player->getStageNumber());
	hp = 20.0f + (4 * Player->getStageNumber());
	mosnterBulletMoveSpeed = 250.f;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Charger/Monster_Charger.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_charger_01.png");
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

	// 좌우 이동
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_04.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 상 이동
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_05.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_06.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_07.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_08.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	// 하 이동
	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.1f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_11.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_charger_12.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();

	// 돌진 공격
	monsterAnimation4 = Animation::create();
	monsterAnimation4->setDelayPerUnit(0.1f);
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

	// 죽을때 
	monsterAnimation5 = Animation::create();
	monsterAnimation5->setDelayPerUnit(0.05f);
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_01.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_02.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_03.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_04.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_05.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_06.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_07.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_08.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_09.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_10.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_11.png"));
	monsterAnimate5 = Animate::create(monsterAnimation5);
	monsterAnimate5->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

}

void Charger::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();
	FollowPlayer();
}

void Charger::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
}

void Charger::FollowPlayer()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (chargerDirection == CHARGER_RIGHT)
		{
			monsterSprite->setPosition(monsterSprite->getPosition().x + cosf(CC_DEGREES_TO_RADIANS(0)) * monsterMoveSpeed, monsterSprite->getPosition().y);

			monsterSprite->setFlippedX(false);

			if (!monsterSprite->getNumberOfRunningActions())
			{
				monsterSprite->runAction(monsterAnimate);
			}
		}
		else if (chargerDirection == CHARGER_LEFT)
		{
			monsterSprite->setPosition(monsterSprite->getPosition().x + cosf(CC_DEGREES_TO_RADIANS(180)) * monsterMoveSpeed, monsterSprite->getPosition().y);

			monsterSprite->setFlippedX(true);

			if (!monsterSprite->getNumberOfRunningActions())
			{
				monsterSprite->runAction(monsterAnimate);
			}
		}
		else if (chargerDirection == CHARGER_UP)
		{
			monsterSprite->setPosition(monsterSprite->getPosition().x, monsterSprite->getPosition().y + sinf(CC_DEGREES_TO_RADIANS(90)) * monsterMoveSpeed);

			if (!monsterSprite->getNumberOfRunningActions())
			{
				monsterSprite->runAction(monsterAnimate2);
			}
		}
		else if (chargerDirection == CHARGER_DOWN)
		{
			monsterSprite->setPosition(monsterSprite->getPosition().x, monsterSprite->getPosition().y + sinf(CC_DEGREES_TO_RADIANS(270)) * monsterMoveSpeed);

			if (!monsterSprite->getNumberOfRunningActions())
			{
				monsterSprite->runAction(monsterAnimate3);
			}
		}

		// 왼쪽으로 돌진
		if (Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y + 15 &&
			Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y - 15 &&
			Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x)
		{
			monsterSprite->setTag(MonsterAttack);

			monsterSprite->setFlippedX(true);

			monsterSprite->stopAllActions();
			monsterSprite->setSpriteFrame("monster_charger_14.png");

			monsterSprite->runAction(Sequence::create(MoveBy::create(1.f, Vec2(Player->getIsaacBody()->getPosition().x - monsterSprite->getPosition().x, 0)),
				CallFunc::create(CC_CALLBACK_0(Charger::ChangeTag, this)),
				CallFunc::create(CC_CALLBACK_0(Charger::MakeAttackCycleZero, this)),nullptr));
		}
		// 오른쪽으로 돌진
		else if (Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y + 15 &&
				Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y - 15 &&
				Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x)
		{
			monsterSprite->setTag(MonsterAttack);

			monsterSprite->setFlippedX(false);

			monsterSprite->stopAllActions();
			monsterSprite->setSpriteFrame("monster_charger_14.png");

			monsterSprite->runAction(Sequence::create(MoveBy::create(1.f, Vec2(Player->getIsaacBody()->getPosition().x - monsterSprite->getPosition().x, 0)),
				CallFunc::create(CC_CALLBACK_0(Charger::ChangeTag, this)),
				CallFunc::create(CC_CALLBACK_0(Charger::MakeAttackCycleZero, this)), nullptr));
		}

		// 아래쪽으로 돌진
		if (Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 15 &&
			Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 15 &&
			Player->getIsaacBody()->getPosition().y < monsterSprite->getPosition().y)
		{
			monsterSprite->setTag(MonsterAttack);

			monsterSprite->stopAllActions();
			monsterSprite->setSpriteFrame("monster_charger_13.png");

			monsterSprite->runAction(Sequence::create(MoveBy::create(1.f, Vec2(0, Player->getIsaacBody()->getPosition().y - monsterSprite->getPosition().y)),
				CallFunc::create(CC_CALLBACK_0(Charger::ChangeTag, this)),
				CallFunc::create(CC_CALLBACK_0(Charger::MakeAttackCycleZero, this)), nullptr));
		}
		// 위쪽으로 돌진
		else if (Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 15 &&
			Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 15 &&
			Player->getIsaacBody()->getPosition().y > monsterSprite->getPosition().y)
		{
			monsterSprite->setTag(MonsterAttack);

			monsterSprite->stopAllActions();
			monsterSprite->setSpriteFrame("monster_charger_15.png");

			monsterSprite->runAction(Sequence::create(MoveBy::create(1.f, Vec2(0, Player->getIsaacBody()->getPosition().y - monsterSprite->getPosition().y)),
				CallFunc::create(CC_CALLBACK_0(Charger::ChangeTag, this)),
				CallFunc::create(CC_CALLBACK_0(Charger::MakeAttackCycleZero, this)), nullptr));
		}
	}

}

void Charger::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Charger::MakeAttackCycleZero()
{
	AttackCycle = 0;
}

void Charger::MonsterSetTag()
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
		monsterSprite->runAction(Sequence::create(monsterAnimate5, CallFunc::create(CC_CALLBACK_0(Charger::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void Charger::MonsterEraseCall()
{

}

void Charger::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		AttackCycle--;
	}

	if (AttackCycle <= 0)
	{
		AttackCycle = 100;

		auto randomDirection = RGI->getRandomNumberWithRange(1, 4);

		switch (randomDirection)
		{
		case 1:
		{
			chargerDirection = CHARGER_LEFT;
		}
		break;
		case 2:
		{
			chargerDirection = CHARGER_RIGHT;
		}
		break;
		case 3:
		{
			chargerDirection = CHARGER_UP;
		}
		break;
		case 4:
		{
			chargerDirection = CHARGER_DOWN;
		}
		break;
		default:
			break;
		}

		monsterSprite->stopAllActions();
	}
}

void Charger::CreateBullet()
{
}
