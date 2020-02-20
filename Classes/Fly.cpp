#include "Fly.h"

Fly::Fly(Scene* scene, Vec2 position)
{
	monsterHeight = 10.0f;
	monsterMoveSpeed = 4.0f;
	maxHp = 10.f * Player->getStageNumber();
	hp = 10.f * Player->getStageNumber();

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Fly/Monster_Fly.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_fly_07.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 6, PhysicsMaterial(0, 0, 0));
	monsterPhysics->setCollisionBitmask(3);
	monsterPhysics->setLinearDamping(1.0f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.1f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2,(monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite);

	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.03f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_07.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_08.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.05f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_12.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_13.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_14.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_15.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_16.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_17.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_18.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_19.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_20.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_21.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_fly_22.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;
}

void Fly::tick()
{
	SetZorder();
	FollowPlayer();
	MonsterSetTag();

	if (hp > 0)
	{
		SMI->PlayInsectSwarm();
	}
}

void Fly::SetZorder()
{

	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);

}

void Fly::FollowPlayer()
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

void Fly::MonsterSetTag()
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
		effectBlood = new EffectBlood(_scene, monsterSprite->getPosition(), MonsterKind_Fly);
		monsterSprite->stopAllActions();
		monsterPhysics->removeFromWorld();
		monsterShadowSprite->setVisible(false);
		monsterSprite->runAction(Sequence::create(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Fly::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
		monsterSprite->setTag(MonsterErase);

	}
}

void Fly::MonsterEraseCall()
{
	
}
