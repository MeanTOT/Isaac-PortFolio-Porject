#include "Clotty.h"

Clotty::Clotty(Scene * scene, Vec2 position)
{
	monsterHeight = 20.0f;
	monsterMoveSpeed = 100.5f;
	maxHp = 16.0f + (4 * Player->getStageNumber());
	hp = 16.0f + (4 * Player->getStageNumber());
	mosnterBulletMoveSpeed = 360.f;

	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	monsterAngle = randomAngle;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;

	auto randomCycle2 = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle2 = randomCycle2;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Clotty/Monster_Clotty.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_clotty_01.png");
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

	// 이동과공격
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_04.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_05.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_06.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_07.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	// 이동과 공격
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_09.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_10.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_clotty_11.png"));
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

void Clotty::tick()
{
	SetZorder();
	MonsterSetTag();

	if (!monsterSprite->getNumberOfRunningActions())
	{
		auto randomAction = RGI->getPercentage(0.5f);

		if (randomAction)
		{
			monsterSprite->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(Clotty::FollowPlayer, this)), monsterAnimate,
				CallFunc::create(CC_CALLBACK_0(Clotty::DoAttack, this)), monsterAnimate2, nullptr));
		}
		else
		{
			monsterSprite->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(Clotty::FollowPlayer, this)), monsterAnimate, nullptr));
		}
	}
}

void Clotty::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1);
}

void Clotty::FollowPlayer()
{
	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	monsterPhysics->applyImpulse(Vec2(cosf(CC_DEGREES_TO_RADIANS(randomAngle)) * monsterMoveSpeed, sinf(CC_DEGREES_TO_RADIANS(randomAngle)) * monsterMoveSpeed));
}

void Clotty::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Clotty::MonsterSetTag()
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
		monsterSprite->runAction(Sequence::create(monsterAnimate4, CallFunc::create(CC_CALLBACK_0(Clotty::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void Clotty::MonsterEraseCall()
{

}

void Clotty::DoAttack()
{
	auto _monsterBullet1 = new MonsterBullet;
	auto _monsterBullet2 = new MonsterBullet;
	auto _monsterBullet3 = new MonsterBullet;
	auto _monsterBullet4 = new MonsterBullet;

	_monsterBullet1->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, 0);
	_monsterBullet2->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, 90);
	_monsterBullet3->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, 180);
	_monsterBullet4->CreateIsaacBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 15), mosnterBulletMoveSpeed, 270);
}

void Clotty::CreateBullet()
{
}
