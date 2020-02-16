#pragma once
#include "ProjectFW.h"

class DebugCall
{
private:
	static DebugCall* instance;
	LayerColor* MoveArea;
	bool DebugActivation;

	DebugCall() { DebugActivation = false; };
	~DebugCall() {};
public:
	static DebugCall* getInstance();
	static void releaseInstance();

	void ShowDebug(PhysicsWorld* sceneworld);

	bool getDebugActivation() { return DebugActivation; }
	void setDebugActivation(bool debug) { DebugActivation = debug; }
};