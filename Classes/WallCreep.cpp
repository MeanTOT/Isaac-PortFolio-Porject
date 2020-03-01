#include "WallCreep.h"

WallCreep::WallCreep(Scene* scene, Vec2 position)
{
	monsterHeight = 15.0f;
	monsterMoveSpeed = 100.f;
	maxHp = 10.f * Player->getStageNumber();
	hp = 10.f * Player->getStageNumber();
	mosnterBulletMoveSpeed = 200.f;
	AttackCycle = 50;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/WallCreep/Monster_WallCreep.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_wallcreep_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setFlippedY(true);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 3, PhysicsMaterial(0.01f, 0, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1);
	//monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight / 2));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.08f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_03.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_04.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_05.png"));
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

	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.05f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_06.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_06.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_07.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_07.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("monster_wallcreep_08.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();
	monsterAnimate3->setTag(3);

	monsterSprite->runAction(monsterAnimate);
	
	_scene = scene;
	_position = position;

	Player->monsterVec.push_back(this);
}

void WallCreep::tick()
{
	SetZorder();
	FollowPlayer();
	MonsterSetTag();
	DoAttack();
}

void WallCreep::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1 + monsterHeight);
}

void WallCreep::FollowPlayer()
{
	if (monsterSprite->getTag() == MonsterIdle && !monsterSprite->getNumberOfRunningActionsByTag(3))
	{
		auto randomMoveVector = RGI->getRandomNumberWithRange(1, 2);

		switch (randomMoveVector)
		{
		case 1:
		{
			monsterPhysics->applyImpulse(Vec2(monsterMoveSpeed, 0));
		}
			break;
		case 2:
		{
			monsterPhysics->applyImpulse(Vec2(-monsterMoveSpeed, 0));
		}
			break;
		default:
			break;
		}

		if (Player->getIsaacBody()->getPosition().x > monsterSprite->getPosition().x - 30 && Player->getIsaacBody()->getPosition().x < monsterSprite->getPosition().x + 30 &&
			AttackCycle == 50)
		{
			AttackCycle = 49;
			monsterPhysics->setVelocity(Vec2(0,0));
			monsterSprite->setTag(MonsterAttack);
			monsterSprite->runAction(Sequence::create(monsterAnimate3, CallFunc::create(CC_CALLBACK_0(WallCreep::CreateBullet, this)), 
				monsterAnimate3, CallFunc::create(CC_CALLBACK_0(WallCreep::CreateBullet, this)),
				monsterAnimate3, CallFunc::create(CC_CALLBACK_0(WallCreep::CreateBullet, this)),
				CallFunc::create(CC_CALLBACK_0(WallCreep::ChangeTag, this)), nullptr));
		}
	}
}

void WallCreep::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
		if(!monsterSprite->getNumberOfRunningActions())
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

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(WallCreep::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void WallCreep::MonsterEraseCall()
{

}

void WallCreep::DoAttack()
{
	if (monsterSprite->getTag() == MonsterIdle)
		AttackCycle--;

	if (AttackCycle <= 0)
	{
		AttackCycle = 50;
	}
}

void WallCreep::CreateBullet()
{
	auto _monsterBullet1 = new MonsterBullet;
	_monsterBullet1->CreateIsaacBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, 90);
}

void WallCreep::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}
