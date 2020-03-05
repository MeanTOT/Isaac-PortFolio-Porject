#pragma once
#include "ProjectFW.h"
#include "Dregs.h"

class Bone
{
private:

	SpriteFrameCache* cache;

	Animation* BoneThrowAnimation;
	Animate* BoneThrowAnimate;

	Sequence* eraseAction1;
	Sequence* eraseAction2;
	Sequence* eraseAction3;

	Dregs* _dregs;
	
	Scene* _scene;

	float range;
	float _impulseX;
	float _impulseY;
	float _height;
	float _speed;
	float _angle;

public:
	Bone();
	~Bone() {};

	Sprite* bullet;
	PhysicsBody* bulletPhysics;
	Sprite* bulletShadow;
	PhysicsBody* bulletShadowPhysics;

	void CreateIsaacBullet(Scene * scene, Vec2 position, float ImpulseX, float ImpulseY);

	void tick();

	void MoveBullet();
	void MoveBulletForAngle();
	void EraseBullet();
	void RangeCount();
	void ErasePhysicsBody();
	void EraseBulletVec();
	void PlayBulletEraseSound();
	void SetZorder();
	void ChangeTag();

};