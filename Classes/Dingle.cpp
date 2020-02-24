#include "Dingle.h"

Dingle::Dingle(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 100.0f;
	maxHp = 300.0f;
	hp = 300.0f;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Dingle/Boss_Dingle.plist");
	cache->addSpriteFramesWithFile("Bullet/Effect_ShitPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("boss_dingle_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0.5f, 1.5f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(0.5f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.2f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, -1);

	// 기본상태
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.08f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_03.png"));
	//monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_04.png"));
	//monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_05.png"));
	//monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_06.png"));
	//monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_07.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 참는 얼굴
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.05f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_23.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_24.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	// 돌진공격
	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.05f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_11.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_12.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_13.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_14.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_18.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_19.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_18.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_19.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_18.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_dingle_19.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();



	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

}

void Dingle::tick()
{
	/*DoAttack();
	SetZorder();
	MonsterSetTag();*/

	if (!monsterSprite->getNumberOfRunningActions())
		monsterSprite->runAction(monsterAnimate);
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

	if (hp <= 0 && monsterSprite->getTag() != MonsterErase)
	{
		_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectPoop, monsterSprite->getLocalZOrder());

		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate3, CallFunc::create(CC_CALLBACK_0(Dingle::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void Dingle::MonsterEraseCall()
{

}

void Dingle::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
		AttackCycle--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 100;

		if (Rect(monsterSprite->getPosition().x - 150, monsterSprite->getPosition().y - 150, 300, 300).containsPoint(Player->getIsaacBody()->getPosition()))
		{
			if (monsterSprite->getPositionX() > Player->getIsaacBody()->getPositionX())
				monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed, 0));
			else if (monsterSprite->getPositionX() < Player->getIsaacBody()->getPositionX())
				monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed, 0));

			if (monsterSprite->getPositionY() > Player->getIsaacBody()->getPositionY())
				monsterPhysics->applyImpulse(Vec2(0, -monsterMoveSpeed));
			else if (monsterSprite->getPositionY() < Player->getIsaacBody()->getPositionY())
				monsterPhysics->applyImpulse(Vec2(0, monsterMoveSpeed));

			//monsterPhysics->applyImpulse(Vec2(Vec2(monsterSprite->getPosition() - Player->getIsaacBody()->getPosition()).x * -2, Vec2(monsterSprite->getPosition() - Player->getIsaacBody()->getPosition()).y * -2));

		}
		else
		{

			auto randomindex = RGI->getPercentage(0.5f);
			auto randomImpuseX = 0;
			auto randomImpuseY = 0;


			if (randomindex)
				randomImpuseX = monsterMoveSpeed;
			else
				randomImpuseX = -monsterMoveSpeed;

			auto randomindey = RGI->getPercentage(0.5f);

			if (randomindey)
				randomImpuseY = monsterMoveSpeed;
			else
				randomImpuseY = -monsterMoveSpeed;

			monsterPhysics->applyImpulse(Vec2(randomImpuseX, randomImpuseY));
		}

		monsterSprite->stopAllActions();
		monsterSprite->setTag(MonsterAttack);
		monsterSprite->runAction(Sequence::createWithTwoActions(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Dingle::ChangeTag, this))));
	}
}
