#pragma once
#include "MapBase.h"

class MapCase_11 : public MapBase
{
private:
	Sprite* StageNameBackGround;
	Label* StageNameText;
public:
	MapCase_11(Scene* scene, Vec2 position);
	~MapCase_11();

	void tick();
	void ShowStageNameText();
};