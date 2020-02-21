#include "Dip.h"

Dip::Dip(Scene * scene, Vec2 position)
{
	monsterHeight = 5.0f;
	monsterMoveSpeed = 100.0f;
	maxHp = 10.f * Player->getStageNumber();
	hp = 10.f * Player->getStageNumber();
	AttackCycle = 100;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Dip/Monster_Dip.plist");
	cache->addSpriteFramesWithFile("Bullet/Effect_ShitPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_dip_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0, 1.5f, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(0.5f);
	monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.15f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, -1);

	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_03.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_04.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_05.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_04.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_dip_05.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.05f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_01.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_02.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_03.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_05.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_06.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_07.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_08.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_shitpoof_11.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();

	Player->monsterVec.push_back(this);

	_scene = scene;
	_position = position;

}

void Dip::tick()
{
	DoAttack();
	SetZorder();
	MonsterSetTag();
}

void Dip::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
}

void Dip::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Dip::MonsterSetTag()
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
		monsterSprite->stopAllActions();
		monsterPhysics->removeFromWorld();
		monsterShadowSprite->setVisible(false);
		monsterSprite->runAction(Sequence::create(monsterAnimate3, CallFunc::create(CC_CALLBACK_0(Dip::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
		_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectPoop, monsterSprite->getLocalZOrder());
		monsterSprite->setTag(MonsterErase);
	}
}

void Dip::MonsterEraseCall()
{

}

void Dip::DoAttack()
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
		monsterSprite->runAction(Sequence::createWithTwoActions(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Dip::ChangeTag, this))));
	}
}
