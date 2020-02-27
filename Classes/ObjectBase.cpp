#include "ObjectBase.h"

void ObjectBase::RandomItemDrop()
{
	if (RGI->getPercentage(Player->getItemInvLuck()))
	{
		auto randomIndex = RGI->getRandomNumberWithRange(1, 3);

		switch (randomIndex)
		{
		case 1:
		{
			coinMaker = new Coin(_scene, _position);
		}
		break;
		case 2:
		{
			keyMaker = new Key(_scene, _position);
		}
		break;
		case 3:
		{
			bombMaker = new Bomb(_scene, _position);
		}
			break;
		default:
			break;
		}
	}
}

void ObjectBase::RandomItemDropSpecial()
{
}
