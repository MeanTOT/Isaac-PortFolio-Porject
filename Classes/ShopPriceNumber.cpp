#include "ShopPriceNumber.h"

void ShopPriceNumber::CreateObject(Scene * scene, Vec2 position, int index)
{
	Obcache = SpriteFrameCache::getInstance();
	Obcache->addSpriteFramesWithFile("Shop/ShopPriceNumber.plist");

	switch (index)
	{
	case 1:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_01.png");
		break;
	case 2:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_02.png");
		break;
	case 3:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_03.png");
		break;
	case 4:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_04.png");
		break;
	case 5:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_05.png");
		break;
	case 6:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_06.png");
		break;
	case 7:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_07.png");
		break;
	case 8:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_08.png");
		break;
	case 9:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_09.png");
		break;
	case 10:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_10.png");
		break;
	case 11:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_11.png");
		break;
	case 12:
		ObjectSprite = Sprite::createWithSpriteFrameName("shop_bitfont_12.png");
		break;
	default:
		break;
	}

	ObjectSprite->setPosition(position);
	ObjectSprite->setTag(ObjectIdle);

	scene->addChild(ObjectSprite);

	ObjectSprite->setLocalZOrder(ObjectSprite->getPositionY() * -1);

	ObjectHp = 1;

	Player->objectVec.push_back(this);

	_index = index;
	_scene = scene;
	_position = position;
}

void ShopPriceNumber::tick()
{

}
