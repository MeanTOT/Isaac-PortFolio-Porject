#include "ItemBase.h"

void ItemBase::ItemSummonAnimation(Sprite* pSprite)
{
	pSprite->runAction(Sequence::create(ScaleTo::create(0.1f, 0.1f, 3.0f), ScaleTo::create(0.1f, 1.2f, 0.8f), ScaleTo::create(0.1f, 1.0f), nullptr));
}
