#include "MegaMaw.h"

MegaMaw::MegaMaw(Scene* scene, Vec2 position)
{
	monsterHeight = 40.0f;
	monsterMoveSpeed = 0.0f;
	maxHp = 350;
	hp = 350;
	mosnterBulletMoveSpeed = 200.0f;

	AttackCycle = 100;

	cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("Monster/MegaMaw/Monster_Monstro1.plist");
	cache->addSpriteFramesWithFile("Monster/Poof/Effect_BloodPoof_Large2.plist");

	monsterSprite = Sprite::createWithSpriteFrameName("boss_monstro_01.png");
	monsterSprite->setPosition(position);
	monsterSprite->setTag(MonsterIdle);

	//monsterPhysics = PhysicsBody::createCircle(monsterSprite->getContentSize().width / 4, PhysicsMaterial(1.0f, 0, 0));
	monsterPhysics = PhysicsBody::createEdgeBox(Size(monsterSprite->getContentSize().width - 20, monsterSprite->getContentSize().height / 6), PhysicsMaterial(0, 1, 0), 3);
	monsterPhysics->setCollisionBitmask(4);
	monsterPhysics->setLinearDamping(1);
	monsterPhysics->setPositionOffset(Vec2(0, -25));
	monsterPhysics->setContactTestBitmask(true);

	monsterSprite->setPhysicsBody(monsterPhysics);

	scene->addChild(monsterSprite);

	bossHpBar = ProgressTimer::create(Sprite::create("UI/ui_bosshealthbar_01.png"));
	bossHpBar->setType(ProgressTimer::Type::BAR);
	bossHpBar->setPosition(position.x, position.y + 125);
	bossHpBar->setMidpoint({ 0,0 });
	bossHpBar->setBarChangeRate({ 1,0 });
	scene->addChild(bossHpBar, 10000);

	bossHpBackBar = Sprite::create("UI/ui_bosshealthbar_02.png");
	bossHpBackBar->setPosition(position.x, position.y + 125);
	scene->addChild(bossHpBackBar, bossHpBar->getLocalZOrder() - 1);

	monsterShadowSprite = Sprite::create("Player/shadow.png");
	monsterShadowSprite->setScale(0.5f);
	monsterShadowSprite->setOpacity(100.f);
	monsterShadowSprite->setPosition(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 30);
	scene->addChild(monsterShadowSprite, monsterSprite->getLocalZOrder() - 1);

	// 총알 발사 공격
	monsterAnimation = Animation::create();
	monsterAnimation->setDelayPerUnit(0.1f);
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_01.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_02.png"));
	monsterAnimation->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_03.png"));
	monsterAnimate = Animate::create(monsterAnimation);
	monsterAnimate->retain();

	monsterAnimation3 = Animation::create();
	monsterAnimation3->setDelayPerUnit(0.1f);
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimation3->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_04.png"));
	monsterAnimate3 = Animate::create(monsterAnimation3);
	monsterAnimate3->retain();

	// 점프이동
	monsterAnimation2 = Animation::create();
	monsterAnimation2->setDelayPerUnit(0.1f);
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_07.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_08.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_05.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_09.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation2->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimate2 = Animate::create(monsterAnimation2);
	monsterAnimate2->retain();

	// 높은 점프 이동
	monsterAnimation4 = Animation::create();
	monsterAnimation4->setDelayPerUnit(0.1f);
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_03.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation4->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_07.png"));
	monsterAnimate4 = Animate::create(monsterAnimation4);
	monsterAnimate4->retain();

	// 높은 점프 내려올때
	monsterAnimation6 = Animation::create();
	monsterAnimation6->setDelayPerUnit(0.1f);
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_05.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_05.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_06.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_09.png"));
	monsterAnimation6->addSpriteFrame(cache->getSpriteFrameByName("boss_monstro_09.png"));
	monsterAnimate6 = Animate::create(monsterAnimation6);
	monsterAnimate6->retain();

	// 죽을때 애니메이션
	monsterAnimation5 = Animation::create();
	monsterAnimation5->setDelayPerUnit(0.05f);
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_01.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_02.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_03.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_04.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_05.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_06.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_07.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_08.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_09.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_10.png"));
	monsterAnimation5->addSpriteFrame(cache->getSpriteFrameByName("effect_bloodpoof_large2_11.png"));
	monsterAnimate5 = Animate::create(monsterAnimation5);
	monsterAnimate5->retain();

	act1 = Sequence::create(ScaleTo::create(0.25f, 0.99f), ScaleTo::create(0.25f, 1.01f), nullptr);
	act1->retain();

	act2 = Sequence::create(MoveBy::create(0.05f, Vec2(3, 0)), MoveBy::create(0.05f, Vec2(-3, 0)), nullptr);
	act2->retain();

	act3 = Sequence::create(ScaleTo::create(0.01f, 0.7f), ScaleTo::create(0.01f,1.0f), nullptr);
	act3->retain();

	_scene = scene;
	_position = position;

	Player->monsterVec.push_back(this);
}

void MegaMaw::tick()
{
	SetZorder();
	FollowPlayer();
	MonsterSetTag();
	DoAttack();

	bossHpBar->setPercentage((hp / maxHp) * 100);
	AttackCycle--;

	monsterShadowSprite->setLocalZOrder(monsterSprite->getLocalZOrder() - 1);
}

void MegaMaw::SetZorder()
{
	monsterSprite->setLocalZOrder(monsterSprite->getPositionY() * -1 + monsterHeight);
}

void MegaMaw::FollowPlayer()
{

}

void MegaMaw::MonsterSetTag()
{
	if (AttackCycle > 0)
	{
		if (!monsterSprite->getNumberOfRunningActions())
		{
			monsterSprite->setSpriteFrame("boss_monstro_01.png");
			monsterSprite->runAction(act1);
		}
	}

	if (monsterSprite->getTag() == MonsterColiisionBullet)
	{
		hp -= Player->getEffectiveDmg();

		if (hp > 30)
			this->HitEffect();

		monsterSprite->setTag(MonsterIdle);
	}

	if (hp <= 30 && monsterSprite->getTag() != MonsterErase)
	{
		monsterPhysics->removeFromWorld();

		monsterShadowSprite->setVisible(false);

		monsterSprite->stopAllActions();
		monsterSprite->runAction(Sequence::create(Repeat::create(act2, 20), CallFunc::create(CC_CALLBACK_0(MegaMaw::CreateDregs, this)),
			monsterAnimate5, CallFunc::create(CC_CALLBACK_0(MegaMaw::MonsterEraseCall, this)), RemoveSelf::create(), nullptr));
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

void MegaMaw::MonsterEraseCall()
{

}

void MegaMaw::DoAttack()
{
	if (AttackCycle == 0)
	{
		monsterSprite->stopAllActions();

		monsterSprite->setTag(MonsterAttack);

		auto randomAttack = RGI->getRandomNumberWithRange(1, 3);

		switch (randomAttack)
		{
		case 1:
		{
			monsterSprite->runAction(Sequence::create(monsterAnimate, CallFunc::create(CC_CALLBACK_0(MegaMaw::CreateBullet, this)), monsterAnimate3, CallFunc::create(CC_CALLBACK_0(MegaMaw::SetAttackCycle, this)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::ChangeTag, this)), nullptr));
			monsterSprite->runAction(Repeat::create(act2, 10));
		}
		break;
		case 2:
		{
			monsterSprite->runAction(Sequence::create(monsterAnimate2, CallFunc::create(CC_CALLBACK_0(MegaMaw::SetAttackCycle, this)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::ChangeTag, this)), nullptr));

			monsterSprite->runAction(Sequence::create(CallFunc::create(CC_CALLBACK_0(MegaMaw::SetCollisionBitMaskZero,this)), JumpTo::create(1.0f, Player->getIsaacBody()->getPosition(), 50, 1), 
				CallFunc::create(CC_CALLBACK_0(MegaMaw::SetCollisionBitMaskBasic, this)), nullptr));

			monsterShadowSprite->runAction(MoveTo::create(1.0f, Vec2(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 30)));
		}
		break;
		case 3:
		{
			monsterSprite->runAction(Sequence::create(monsterAnimate4, MoveBy::create(0.2f, Vec2(0,400)), CallFunc::create(CC_CALLBACK_0(MegaMaw::SetCollisionBitMaskZero, this)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::RunShadowMoveAction, this)),
				DelayTime::create(1.2f),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::SetPositionToPlayerPosition,this)),
				MoveBy::create(0.2f, Vec2(0, -370)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::SetCollisionBitMaskBasic, this)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::CreateBullet2, this)),
				Spawn::createWithTwoActions(monsterAnimate6, act3),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::SetAttackCycle, this)),
				CallFunc::create(CC_CALLBACK_0(MegaMaw::ChangeTag, this)), nullptr));

			monsterSprite->runAction(Repeat::create(act2, 20));
		}
			break;
		default:
			break;
		}
	}
}

void MegaMaw::CreateBullet()
{
	// 랜덤 총알 수
	auto randomBulletAmount = RGI->getRandomNumberWithRange(15, 35);

	for (int i = 0; i < randomBulletAmount; i++)
	{
		log("%d", i);

		auto _monsterBullet = new MonsterBullet;

		auto randomAngle = RGI->getRandomNumberWithRange(this->GetAngleToPlayer() - 15, this->GetAngleToPlayer() + 15);

		auto randomHeight = RGI->getRandomNumberWithRange(30, 100);

		auto randomBulletSpeed = RGI->getRandomNumberWithRange(180, 250);

		_monsterBullet->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 40), randomBulletSpeed, randomAngle, randomHeight);
	}
}

void MegaMaw::CreateBullet2()
{
	// 랜덤 총알 수
	auto randomBulletAmount = RGI->getRandomNumberWithRange(15, 35);

	for (int i = 0; i < randomBulletAmount; i++)
	{
		log("%d", i);

		auto _monsterBullet = new MonsterBullet;

		auto randomAngle = RGI->getRandomNumberWithRange(0, 360);

		auto randomHeight = RGI->getRandomNumberWithRange(30, 100);

		auto randomBulletSpeed = RGI->getRandomNumberWithRange(180, 250);

		_monsterBullet->CreateBullet(_scene, Vec2(monsterSprite->getPosition().x, monsterSprite->getPosition().y - 40), randomBulletSpeed, randomAngle, randomHeight);
	}
}

void MegaMaw::SetAttackCycle()
{
	AttackCycle = 150;
}

void MegaMaw::ChangeTag()
{
	monsterSprite->setTag(MonsterIdle);
}

void MegaMaw::SetCollisionBitMaskZero()
{
	monsterPhysics->setCollisionBitmask(0);
}

void MegaMaw::SetCollisionBitMaskBasic()
{
	monsterPhysics->setCollisionBitmask(4);
}

void MegaMaw::SetPositionToPlayerPosition()
{
	monsterSprite->setPosition(monsterShadowSprite->getPosition().x, monsterShadowSprite->getPosition().y + 400);
}

void MegaMaw::RunShadowMoveAction()
{
	monsterShadowSprite->runAction(MoveTo::create(1.0f, Vec2(Player->getIsaacBody()->getPosition().x, Player->getIsaacBody()->getPosition().y - 30)));
}

void MegaMaw::CreateDregs()
{
	effectBlood = new EffectBlood(_scene, monsterSprite->getPosition(), MonsterKind_MegaMaw);
	_dregs = new Dregs(_scene, monsterSprite->getPosition(), ObjectMonster, monsterSprite->getLocalZOrder());
}
