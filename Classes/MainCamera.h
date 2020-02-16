#pragma once
#include "ProjectFW.h"

#define CameraSpeed 0.5f

class MainCamera
{
private:
	static MainCamera* instance;

	MainCamera() {};
	~MainCamera() {};
public:
	Camera* camera;

	static MainCamera* getInstance();
	static void releaseInstance();
	void CreateCamera(Scene* scene);
	void MoveR();
	void MoveL();
	void MoveT();
	void MoveB();
	void MoveRB();
	void MoveRT();
	void MoveLB();
	void MoveLT();
};
