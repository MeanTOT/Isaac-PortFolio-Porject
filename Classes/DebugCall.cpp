#include "DebugCall.h"

DebugCall* DebugCall::instance = nullptr;

DebugCall * DebugCall::getInstance()
{
	if (!instance)
		instance = new DebugCall;

	return instance;
}

void DebugCall::releaseInstance()
{
	if (instance)
		delete instance;
}

void DebugCall::ShowDebug(PhysicsWorld * sceneworld)
{
	if (DebugActivation)
		sceneworld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	else
		sceneworld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
}