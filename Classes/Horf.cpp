#include "Horf.h"

Horf::Horf(Scene* scene, Vec2 position)
{
	monsterHeight = 20.0f;
	monsterMoveSpeed = 0.0f;
	maxHp = 10.f * Player->getStageNumber();
	hp = 10.f * Player->getStageNumber();
	mosnterBulletMoveSpeed = 600.0f;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/Horf/Monster_Horf.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("monster_horf_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 3, PhysicsMaterial(0.01f, 0, 0));
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1);
	//monsterPhysics->setPositionOffset(Vec2(0, -1 * monsterHeight / 2));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.15f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getContentSize().width / 2, (monsterSprite->getContentSize().height / 2) - monsterHeight);
	monsterSprite->addChild(monsterShadowSprite, monsterSprite->getLocalZOrder() - 1);

	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.08f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_horf_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_horf_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("monster_horf_03.png"));
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

	auto act1 = MoveBy::create(0.05f, Vec2(5, 0));
	auto act2 = MoveBy::create(0.05f, Vec2(-5, 0));
	auto act3 = DelayTime::create(2.f);
	auto act4 = monsterAnimate;

	monsterSprite->runAction(monsterAnimate);
	monsterSprite->runAction(RepeatForever::create(Sequence::create(act1,act2,nullptr)));
	monsterSprite->runAction(RepeatForever::create(Sequence::create(act3, Spawn::createWithTwoActions(monsterAnimate,CallFunc::create(CC_CALLBACK_0(Horf::CreateBullet,this))), nullptr)));

	_scene = scene;
	_position = position;

	Player->monsterVec.push_back(this);
}

void Horf::tick()
{
	SetZorder();
	FollowPlayer();
	MonsterSetTag();
}

void Horf::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1 + monsterHeight);
}

void Horf::FollowPlayer()
{

}

void Horf::MonsterSetTag()
{
	if (monsterSprite->getTag() == MonsterIdle)
	{
	
			
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
		monsterSprite->runAction(Sequence::create(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(Horf::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void Horf::MonsterEraseCall()
{

}

void Horf::DoAttack()
{

}

void Horf::CreateBullet()
{
	if (monsterSprite->getPosition().x - 60 < Player->getIsaacBody()->getPosition().x && monsterSprite->getPosition().x + 60 > Player->getIsaacBody()->getPosition().x)
	{
		auto _monsterBullet = new MonsterBullet;
		_monsterBullet->CreateBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, this->GetAngleToPlayer(), monsterHeight);

		SMI->PlayShakeyKidRoar();
	}
	else if (monsterSprite->getPosition().y - 60 < Player->getIsaacBody()->getPosition().y && monsterSprite->getPosition().y + 60 > Player->getIsaacBody()->getPosition().y)
	{
		auto _monsterBullet = new MonsterBullet;
		_monsterBullet->CreateBullet(_scene, monsterSprite->getPosition(), mosnterBulletMoveSpeed, this->GetAngleToPlayer(), monsterHeight);

		SMI->PlayShakeyKidRoar();
	}
}
