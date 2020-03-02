#include "BoomFly.h"

BoomFly::BoomFly(Scene* scene, Vec2 position)
{
	monsterHeight = 20.0f;
	monsterMoveSpeed = 15000.0f;
	maxHp = 20.f + (4 * Player->getStageNumber());
	hp = 20.f + (4 * Player->getStageNumber());

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/BoomFly/Monster_BoomFly.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_boomfly_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(1.f, 1.f, 0));
	monsterPhysics->setCollisionBitmask(3);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * (monsterHeight / 2)));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.1f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite);

	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.03f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boomfly_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_boomfly_02.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.05f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_01.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_02.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_03.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_04.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_05.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_06.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_07.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_09.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_10.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_11.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

	FollowPlayer();
}

void BoomFly::tick()
{
	SetZorder();
	MonsterSetTag();

	if (hp > 0)
	{
		SMI->PlayInsectSwarm();
	}

	if (monsterSprite->getTag() == MonsterColiisionExplosion)
	{
		hp -= Player->getBombDmg();

		log("ÆøÆÈ°úÃæµ¹");

		monsterSprite->setTag(MonsterIdle);
	}
}

void BoomFly::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1 + monsterHeight);
}

void BoomFly::FollowPlayer()
{
	auto randomCase = RGI->getRandomNumberWithRange(1, 4);

	switch (randomCase)
	{
	case 1:
		monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed, monsterMoveSpeed));
		break;
	case 2:
		monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed, -monsterMoveSpeed));
		break;
	case 3:
		monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed, monsterMoveSpeed));
		break;
	case 4:
		monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed, -monsterMoveSpeed));
		break;
	default:
		break;
	}
}

void BoomFly::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (!monsterSprite->getNumberOfRunningActions())
			monsterSprite->runAction(monsterAnimate);
	}

	if (monsterSprite->getTag() == MonsterColiisionBullet)
	{
		hp -= Player->getEffectiveDmg();

		this->HitEffect();
		monsterSprite->setTag(MonsterIdle);
	}

	if (hp <= 0 && monsterSprite->getTag() != MonsterErase)
	{
		SMI->StopInsectSwarm();

		explosionMaker = new Explosion(_scene, monsterSprite->getPosition(), BaseMentBomb);

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(BoomFly::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
		monsterSprite->setTag(MonsterErase);

		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

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

void BoomFly::MonsterEraseCall()
{

}