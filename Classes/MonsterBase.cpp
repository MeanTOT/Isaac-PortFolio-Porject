#include "MonsterBase.h"

MonsterBase::MonsterBase()
{
	
}

MonsterBase::~MonsterBase()
{
}

void MonsterBase::HitEffect()
{
	monsterSprite->setColor(Color3B::RED);
	monsterSprite->runAction(Sequence::create( DelayTime::create(0.1f), CallFunc::create(CC_CALLBACK_0(MonsterBase::ChangeColor, this)),nullptr));
}

void MonsterBase::ChangeColor()
{
	if (monsterSprite->getColor() == Color3B::RED)
	{
		monsterSprite->setColor(Color3B::WHITE);
		return;
	}
}
