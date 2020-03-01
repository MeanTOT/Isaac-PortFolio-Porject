#include "Tumor.h"

Tumor::Tumor(Scene * scene, Vec2 position)
{
	monsterHeight = 20.0f;
	monsterMoveSpeed = 1.5f;
	maxHp = 20.f + (4 * Player->getStageNumber());
	hp = 20.f + (4 * Player->getStageNumber());
	mosnterBulletMoveSpeed = 300.f;

	auto randomCycle = RGI->getRandomNumberWithRange(70, 130);

	AttackCycle = randomCycle;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Tumor/Tumor.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_tumor_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(0.01f, 0, 0));
	monsterPhysics->setCollisionBitmask(3);
	monsterPhysics->setLinearDamping(1);
	monsterPhysics->setPositionOffset(Vec2(0, -monsterHeight / 2));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.2f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, monsterSprite->getLocalZOrder() - 1);

	// 기본 모션
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.2f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_03.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();
	monsterAnimate->setTag(1);

	// 공격 모션
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.05f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_07.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_07.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("monster_tumor_07.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();
	monsterAnimate2->setTag(2);

	// 죽는 모션
	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.05f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_01.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_02.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_03.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_05.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_06.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_07.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_08.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_09.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_10.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_11.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();
	monsterAnimate3->setTag(3);

	Player->monsterVec.push_back(this);

	monsterSprite->runAction(monsterAnimate);

	_scene = scene;
	_position = position;
}

void Tumor::tick()
{
	DoAttack();
	SetZorder();
	FollowPlayer();
	MonsterSetTag();
}

void Tumor::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1 + monsterHeight);
}

void Tumor::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void Tumor::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if (!monsterSprite->getNumberOfRunningActionsByTag(1) && !monsterSprite->getNumberOfRunningActionsByTag(2))
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
		effectBlood = new EffectBlood(_scene, monsterSprite->getPosition(), MonsterKind_Horf);
		_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectMonster, monsterSprite->getLocalZOrder());

		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate3, RemoveSelf::create(), nullptr));
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

void Tumor::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
		AttackCycle--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 60;

		monsterSprite->stopAllActions();
		monsterSprite->setTag(MonsterAttack);
		monsterSprite->runAction(Sequence::createWithTwoActions(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Tumor::ChangeTag, this))));
		CreateBullet();
	}
}

void Tumor::CreateBullet()
{
	auto _monsterBullet1 = new MonsterBullet;
	auto _monsterBullet2 = new MonsterBullet;
	auto _monsterBullet3 = new MonsterBullet;
	auto _monsterBullet4 = new MonsterBullet;
	auto _monsterBullet5 = new MonsterBullet;
	auto _monsterBullet6 = new MonsterBullet;

	auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

	_monsterBullet1->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 0);
	_monsterBullet2->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 60);
	_monsterBullet3->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 120);
	_monsterBullet4->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 180);
	_monsterBullet5->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 240);
	_monsterBullet6->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, randomAngle + 300);
}

void Tumor::FollowPlayer()
{
	auto randomVector = RGI->getRandomNumberWithRange(1, 4);

	switch (randomVector)
	{
	case 1:
	{
		monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed * 10, 0));
	}
	break;
	case 2:
	{
		monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed * 10, 0));
	}
	break;
	case 3:
	{
		monsterPhysics->applyImpulse(Vec2(0, -monsterMoveSpeed * 10));
	}
	break;
	case 4:
	{
		monsterPhysics->applyImpulse(Vec2(0, monsterMoveSpeed * 10));
	}
	break;
	default:
		break;
	}
}
