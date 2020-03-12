#pragma once
#include "ProjectFW.h"
#include "MapCase_11.h"
#include "MapCase_12.h"
#include "MapCase_13.h"
#include "MapCase_14.h"
#include "MapCase_15.h"
#include "MapCase_16_ItemRoom2.h"
#include "MapCase_17.h"
#include "MapCase_18.h"
#include "MapCase_19.h"
#include "MapCase_20.h"
#include "MapCase_21.h"
#include "MapCase_22.h"
#include "MapCase_23_BossRoom.h"
#include "MapCase_24_ShopRoom.h"
#include "MapCase_25.h"
#include "MapCase_26.h"


class MiniMap_2
{
private:
	Scene* _scene;
	MapBase* _mapbase[16];

	Layer* miniMapLayer;

	Sprite* miniMapPlayer;
	Sprite* miniMapFrame;
	Sprite* miniMapBox[16];


	bool miniMapClarify[16];

public:
	MiniMap_2(Scene* scene, MapBase* mapbase[]);
	~MiniMap_2();

	void tick();
	void MiniMapPositionUpdate();
	void MiniMapPlayerMove();
	void MiniMapClarify();

};