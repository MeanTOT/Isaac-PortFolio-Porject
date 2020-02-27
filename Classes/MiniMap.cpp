#include "MiniMap.h"

MiniMap::MiniMap(Scene * scene, MapBase * mapbase[])
{
	_scene = scene;
	
	for (int i = 0; i < 10; i++)
	{
		_mapbase[i] = mapbase[i];
	}

	miniMapFrame = Sprite::create("MiniMap/minimap1_01.png");
	miniMapFrame->setPosition(CI->camera->getPosition().x + 190, CI->camera->getPosition().y + 100);
	_scene->addChild(miniMapFrame, MiniMapZoder - 500);

	miniMapLayer = Layer::create();
	miniMapLayer->setContentSize(Size(55, 49));
	miniMapLayer->setAnchorPoint({ 0,0 });
	miniMapFrame->addChild(miniMapLayer);

	miniMapPlayer = Sprite::create("MiniMap/minimap1_33.png");
	miniMapPlayer->setPosition(miniMapFrame->getContentSize().width / 2, miniMapFrame->getContentSize().height / 2);
	miniMapPlayer->setVisible(true);
	miniMapFrame->addChild(miniMapPlayer, MiniMapZoder + 1000);
		
	miniMapBox[0] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[0]->setPosition(miniMapFrame->getContentSize().width / 2, miniMapFrame->getContentSize().height / 2);
	miniMapFrame->addChild(miniMapBox[0], MiniMapZoder);

	miniMapBox[1] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[1]->setPosition(miniMapBox[0]->getPosition().x, miniMapBox[0]->getPosition().y + miniMapBox[0]->getContentSize().height);
	miniMapFrame->addChild(miniMapBox[1], MiniMapZoder);

	miniMapBox[2] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[2]->setPosition(miniMapBox[0]->getPosition().x - miniMapBox[0]->getContentSize().width, miniMapBox[0]->getPosition().y);
	miniMapFrame->addChild(miniMapBox[2], MiniMapZoder);

	miniMapBox[3] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[3]->setPosition(miniMapBox[0]->getPosition().x, miniMapBox[0]->getPosition().y - miniMapBox[0]->getContentSize().height);
	miniMapFrame->addChild(miniMapBox[3], MiniMapZoder);

	miniMapBox[4] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[4]->setPosition(miniMapBox[3]->getPosition().x + miniMapBox[3]->getContentSize().width, miniMapBox[3]->getPosition().y);
	miniMapFrame->addChild(miniMapBox[4], MiniMapZoder);

	miniMapBox[5] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[5]->setPosition(miniMapBox[3]->getPosition().x, miniMapBox[3]->getPosition().y - miniMapBox[3]->getContentSize().height);
	miniMapFrame->addChild(miniMapBox[5], MiniMapZoder);

	miniMapBox[7] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[7]->setPosition(miniMapBox[5]->getPosition().x, miniMapBox[5]->getPosition().y - miniMapBox[5]->getContentSize().height);
	miniMapFrame->addChild(miniMapBox[7], MiniMapZoder);

	miniMapBox[6] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[6]->setPosition(miniMapBox[7]->getPosition().x - miniMapBox[7]->getContentSize().height, miniMapBox[7]->getPosition().y);
	miniMapFrame->addChild(miniMapBox[6], MiniMapZoder);

	miniMapBox[8] = Sprite::create("MiniMap/minimap1_Treasure.png");
	miniMapBox[8]->setPosition(miniMapBox[7]->getPosition().x, miniMapBox[7]->getPosition().y - miniMapBox[7]->getContentSize().height);
	miniMapFrame->addChild(miniMapBox[8], MiniMapZoder);

	miniMapBox[9] = Sprite::create("MiniMap/minimap1_06.png");
	miniMapBox[9]->setPosition(miniMapBox[4]->getPosition().x + miniMapBox[4]->getContentSize().width, miniMapBox[4]->getPosition().y);
	miniMapFrame->addChild(miniMapBox[9], MiniMapZoder);

	for (int i = 0; i < 10; i++)
	{
		miniMapClarify[i] = false;
		miniMapBox[i]->setVisible(false);
	}

	//miniMapLayer->runAction(Follow::create(miniMapPlayer, Rect(miniMapFrame->getPosition().x - miniMapFrame->getContentSize().width /2,
	//	miniMapFrame->getPosition().y + miniMapFrame->getContentSize().height / 2 ,55 * 2,49 * 2)));
}

MiniMap::~MiniMap()
{
}

void MiniMap::tick()
{
	this->MiniMapPositionUpdate();
	this->MiniMapPlayerMove();
	this->MiniMapClarify();

	for (int i = 0; i < 10; i++)
	{
		if (miniMapFrame->getBoundingBox().containsPoint(miniMapBox[i]->convertToWorldSpace(_scene->getPosition())) && miniMapClarify[i])
		{
			miniMapBox[i]->setVisible(true);
		}
		else
		{
			miniMapBox[i]->setVisible(false);
		}
	}
}

void MiniMap::MiniMapPositionUpdate()
{
	miniMapFrame->setPosition(CI->camera->getPosition().x + 190, CI->camera->getPosition().y + 100);
	miniMapLayer->setPosition(CI->camera->getPosition().x + 190 - miniMapLayer->getContentSize().width / 2,
		CI->camera->getPosition().y + 100 - miniMapLayer->getContentSize().height / 2);
}

void MiniMap::MiniMapPlayerMove()
{
	if (Player->getMiniMapPlayerU())
	{
		
		for (int i = 0; i < 10; i++)
		{
			miniMapBox[i]->setPosition(miniMapBox[i]->getPosition().x, miniMapBox[i]->getPosition().y - miniMapPlayer->getContentSize().height);
		}

		Player->setMiniMapPlayerU(false);
	}

	if (Player->getMiniMapPlayerD())
	{
		for (int i = 0; i < 10; i++)
		{
			miniMapBox[i]->setPosition(miniMapBox[i]->getPosition().x, miniMapBox[i]->getPosition().y + miniMapPlayer->getContentSize().height);
		}

		Player->setMiniMapPlayerD(false);
	}

	if (Player->getMiniMapPlayerR())
	{
		for (int i = 0; i < 10; i++)
		{
			miniMapBox[i]->setPosition(miniMapBox[i]->getPosition().x - miniMapPlayer->getContentSize().width, miniMapBox[i]->getPosition().y);
		}

		Player->setMiniMapPlayerR(false);
	}

	if (Player->getMiniMapPlayerL())
	{
		for (int i = 0; i < 10; i++)
		{
			miniMapBox[i]->setPosition(miniMapBox[i]->getPosition().x + miniMapPlayer->getContentSize().width, miniMapBox[i]->getPosition().y);
		}

		Player->setMiniMapPlayerL(false);
	}
}

void MiniMap::MiniMapClarify()
{
	if (Player->getRoomNumber() == 1)
	{
		miniMapClarify[0] = true;
		miniMapClarify[1] = true;
		miniMapClarify[2] = true;
		miniMapClarify[3] = true;
	}

	if (Player->getRoomNumber() == 4)
	{
		miniMapClarify[4] = true;
		miniMapClarify[5] = true;
	}

	if (Player->getRoomNumber() == 5)
	{
		miniMapClarify[9] = true;
	}

	if (Player->getRoomNumber() == 6)
	{
		miniMapClarify[7] = true;
	}

	if (Player->getRoomNumber() == 8)
	{
		miniMapClarify[8] = true;
		miniMapClarify[6] = true;
	}

	log("%d", Player->getRoomNumber());
}
