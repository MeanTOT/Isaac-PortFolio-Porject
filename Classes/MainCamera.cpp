#include "MainCamera.h"

MainCamera* MainCamera::instance = nullptr;

void MainCamera::CreateCamera(Scene * scene)
{
	camera = Camera::createOrthographic(DI->getWinSize().width, DI->getWinSize().height, 1, 1000);
	camera->setCameraFlag(CameraFlag::USER1);
	camera->setPosition3D({ 0,0,1 });
	camera->lookAt(camera->getPosition3D());
	scene->setCameraMask((unsigned short)CameraFlag::USER1);
	scene->addChild(camera);
}

MainCamera * MainCamera::getInstance()
{
	if (!instance)
		instance = new MainCamera;

	return instance;
}

void MainCamera::releaseInstance()
{
	if (instance)
		delete instance;
}

void MainCamera::MoveR()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(DI->getWinSize().width, 0)), 3));
}

void MainCamera::MoveL()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(-DI->getWinSize().width, 0)), 3));
}

void MainCamera::MoveT()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(0, DI->getWinSize().height)), 3));
}

void MainCamera::MoveB()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(0, -DI->getWinSize().height)), 3));
}

void MainCamera::MoveRB()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(DI->getWinSize().width, -DI->getWinSize().height)), 3));
}

void MainCamera::MoveRT()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(DI->getWinSize().width, DI->getWinSize().height)), 3));
}

void MainCamera::MoveLB()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(-DI->getWinSize().width, -DI->getWinSize().height)), 3));
}

void MainCamera::MoveLT()
{
	camera->runAction(EaseInOut::create(MoveBy::create(CameraSpeed, Vec2(-DI->getWinSize().width, DI->getWinSize().height)), 3));
}

