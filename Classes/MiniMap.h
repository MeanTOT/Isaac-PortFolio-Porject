#pragma once
#include "ProjectFW.h"
#include "MapCase_1.h"
#include "MapCase_2.h"
#include "MapCase_3.h"
#include "MapCase_4.h"
#include "MapCase_5.h"
#include "MapCase_6.h"
#include "MapCase_7.h"
#include "MapCase_8.h"
#include "MapCase_ItemRoom1.h"
#include "MapCase_BossRoom.h"

class MiniMap
{
private:
	Scene* _scene;
	MapBase* _mapbase[10];

	Layer* miniMapLayer;

	Sprite* miniMapPlayer;
	Sprite* miniMapFrame;
	Sprite* miniMapBox[10];


	bool miniMapClarify[10];

public:
	MiniMap(Scene* scene, MapBase* mapbase[]);
	~MiniMap();
	
	void tick();
	void MiniMapPositionUpdate();
	void MiniMapPlayerMove();
	void MiniMapClarify();
	
};