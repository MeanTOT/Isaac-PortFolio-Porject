#pragma once
#include "MapBase.h"

class MapCase_22 : public MapBase
{
private:
	EffectPoof* BlubberMaker[2];
	MushRoom* MushRoomMaker[8];

public:
	MapCase_22(Scene* scene, Vec2 position);
	~MapCase_22();

	void tick();
	void ClearOnDidFinish();
};
