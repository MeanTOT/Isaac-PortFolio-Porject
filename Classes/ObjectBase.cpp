#include "ObjectBase.h"

void ObjectBase::RandomItemDrop()
{
	if (RGI->getPercentage(Player->getItemInvLuck()))
	{
		auto randomIndex = RGI->getRandomNumberWithRange(1, 5);

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
		case 4:
		{
			heartMaker = new Heart(_scene, _position);
		}
			break;
		case 5:
		{
			pillMaker = new Pill(_scene, _position);
		}
			break;
		default:
			break;
		}
	}
}

void ObjectBase::RandomItemDropUnconditional()
{
	if (RGI->getPercentage(1.0f))
	{
		auto randomIndex = RGI->getRandomNumberWithRange(1, 4);

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
		case 4:
		{
			heartMaker = new Heart(_scene, _position);
		}
		break;
		case 5:
		{
			pillMaker = new Pill(_scene, _position);
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
