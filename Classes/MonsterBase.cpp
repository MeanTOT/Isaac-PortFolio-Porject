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
	monsterSprite->runAction(Sequence::create( DelayTime::create(0.05f), CallFunc::create(CC_CALLBACK_0(MonsterBase::ChangeColor, this)),nullptr));
}

void MonsterBase::HitEffect2()
{
	monsterSprite->setColor(Color3B::RED);
	monsterSprite->runAction(Sequence::create(DelayTime::create(0.05f), CallFunc::create(CC_CALLBACK_0(MonsterBase::ChangeColor2, this)), nullptr));

	monsterSubSprite->setColor(Color3B::RED);
	monsterSubSprite->runAction(Sequence::create(DelayTime::create(0.05f), CallFunc::create(CC_CALLBACK_0(MonsterBase::ChangeColor2, this)), nullptr));
}

void MonsterBase::ChangeColor()
{
	monsterSprite->setColor(Color3B::WHITE);
}

void MonsterBase::ChangeColor2()
{
	monsterSubSprite->setColor(Color3B::WHITE);
	monsterSprite->setColor(Color3B::WHITE);
}

float MonsterBase::GetAngleToPlayer()
{
	float _angle;
	float _positionX = monsterSprite->getPosition().x - Player->getIsaacBody()->getPosition().x; 
	float _positionY = monsterSprite->getPosition().y - Player->getIsaacBody()->getPosition().y;

	_angle = atan2f(-_positionY, -_positionX);

	return (_angle * 180) / 3.141592;
}
