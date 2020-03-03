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
