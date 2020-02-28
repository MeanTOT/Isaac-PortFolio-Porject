#include "GameStage_2.h"

Scene * GameStage_2::createScene()
{
	return GameStage_2::create();
}

bool GameStage_2::init()
{
	if (!Scene::init())
		return false;

	return true;
}

GameStage_2::GameStage_2()
{
}

GameStage_2::~GameStage_2()
{
}
