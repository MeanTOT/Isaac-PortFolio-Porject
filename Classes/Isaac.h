#pragma once
#include "ProjectFW.h"

class ObjectBase;

class Bullet;

class IsaacBoom;

enum NowScene // 1 ~ 50
{
	PressStartScene = 1,
	FileSelectScene,
	MainMenuScene,
	CharSelectScene,
	OptionScene,
	StatsScreen,
	StageScreen
};

enum BulletVector // 51 ~ 100
{
	BulletVectorR = 51,
	BulletVectorL,
	BulletVectorU,
	BulletVectorD,
};

enum WalkVector // 101 ~ 150
{
	WalkRightLeft = 101,
	WalkUpDown,
};

enum BulletTAG // 151 ~ 200
{
	EraseBulletTag = 151,
	EraseBulletTag2,
	EraseOnVec,
	ActivationBulletTag,
};

enum ObjectTAG // 201 ~ 250
{
	ObjectHit = 201,
	ObjectIdle,
	ObjectErase,
	ObjectCollisionBomb,
};

enum ObjectName // 251 ~ 300
{
	ObjectRock = 251,
	ObjectFire,
	ObjectPoop,
};

class Isaac
{
private:
	Isaac();
	~Isaac() {};
	static Isaac* instance;

	Scene* _scene; // 씬

	SpriteFrameCache* cache; // 캐쉬

	NowScene nowScene; // 현재 맵을 구분하는 enum
	BulletVector bulletVector; // Bullet의 방향 enum

	Sprite* isaacHead_Base; // Isaac 머리
	Sprite* isaacBody_Base; // Isaac 몸통
	PhysicsBody* isaacPhysicBody; // Isaac 피직스 몸통 
	Sprite* isaacShadow; // Isaac 그림자

	IsaacBoom* isaacBoom; // 아이작 폭탄

	Animation* BulletFireAnimatioR;
	Animate* BulletFireAnimateR;
	Animation* BulletFireAnimatioL;
	Animate* BulletFireAnimateL;
	Animation* BulletFireAnimatioU;
	Animate* BulletFireAnimateU;
	Animation* BulletFireAnimatioD;
	Animate* BulletFireAnimateD;

	Animation* IsaacWalkAnimationRL;
	Animate* IsaacWalkAnimateRL;
	Animation* IsaacWalkAnimationUD;
	Animate* IsaacWalkAnimateUD;

	int mainMenuIndex; // 메인메뉴 인덱스
	int charSelectIndex; // 캐릭터 선택 인덱스
	int difficultySelectIndex; // 난이도 선택 인덱스
	int OptionIndex; // 옵션선택 인덱스
	int OptionSfxIndex; // 옵션Sfx 인덱스
	int OptionBgmIndex; // 옵션Bgm 인덱스
	int RoomNumber; // 방을 구분하는 인덱스
	int BombCount; // 폭탄 갯수

	float MoveSpeed; // Isaac 스피드
	float BulletFireCycle; // 총알발사속도(주기)
	float bulletRange; // 총알 사거리
	float bulletMoveSpeed; // 총알 움직임 스피드 
	float basicHeight; // 총알 기본 높이 
	float maxHeight; // 총알 최대 높이


	bool ControlAtivation; // 유저에게 조종권을 준다.
	bool SceneChange; // 씬전환
	bool MoveR; // 오른쪽 움직임
	bool MoveL; // 왼쪽 움직임
	bool MoveU;	// 위쪽 움직임
	bool MoveD;	// 아래쪽 움직임
	bool BulletFireR; // 총알발사 R
	bool BulletFireL; // 총알발사 L
	bool BulletFireU; // 총알발사 U
	bool BulletFireD; // 총알발사 D
	bool BombActivation; // 폭탄 활성화

public:
	static Isaac* getInstance();
	static void releaseInstance();


	// Scene,Screen Control //
	NowScene getNowScene() { return nowScene; }
	void setNowScene(NowScene nowscene) { nowScene = nowscene; }
	int getMainMenuIndex() { return mainMenuIndex; }
	void setMainMenuIndex(int mainmenuindex) { mainMenuIndex = mainmenuindex; }
	int getCharSelectIndex() { return charSelectIndex; }
	void setCharSelectIndex(int charselectindex) { charSelectIndex = charselectindex; }
	int getDifficultySelectIndex() { return difficultySelectIndex; }
	void setDifficultySelectIndex(int difficultyselectindex) { difficultySelectIndex = difficultyselectindex; }
	int getOptionIndex() { return OptionIndex; }
	void setOptionIndex(int optionIndex) { OptionIndex = optionIndex; }
	int getOptionSfxIndex() { return OptionSfxIndex; }
	void setOptionSfxIndex(int optionsfxindex) { OptionSfxIndex = optionsfxindex; }
	int getOptionBgmIndex() { return OptionBgmIndex; }
	void setRoomNumber(int roomnumber) { RoomNumber = roomnumber; }
	int getRoomNumber() { return RoomNumber; }
	void setOptionBgmIndex(int optionbgmindex) { OptionBgmIndex = optionbgmindex; }
	bool getControlAtivation() { return ControlAtivation; }
	void setControlAtivation(int controlativation) { ControlAtivation = controlativation; }
	bool getSceneChange() { return SceneChange; }
	void setSceneChange(int scenechange) { SceneChange = scenechange; }

	// Isaac Move //
	bool getMoveR() { return MoveR; }
	void setMoveR(int mover) { MoveR = mover; }
	bool getMoveL() { return MoveL; }
	void setMoveL(int movel) { MoveL = movel; }
	bool getMoveU() { return MoveU; }
	void setMoveU(int moveu) { MoveU = moveu; }
	bool getMoveD() { return MoveD; }
	void setMoveD(int moved) { MoveD = moved; }
	bool getBombActivation() { return BombActivation; }
	void setBombActivation(int bombactivation) { BombActivation = bombactivation; }
	PhysicsBody* getIsaacPysicBody() { return isaacPhysicBody; }
	Sprite* getIsaacBody() { return isaacBody_Base; }
	Sprite* getIsaacHead() { return isaacHead_Base; }

	// ------------------------------------------------------ float ------------------------------------------------------ // 
	float getBulletRange() { return bulletRange; }
	void setBulletRange(float bulletrange) { bulletRange = bulletrange; }
	float getBulletMoveSpeed() { return bulletMoveSpeed; }
	void setBulletMoveSpeed(float bulletmovespeed) { bulletMoveSpeed = bulletmovespeed; }
	float getBasicHeight() { return basicHeight; }
	void setBasicHeight(float basicheight) { basicHeight = basicheight; }
	float getMaxHeight() { return maxHeight; }
	void setMaxHeight(float maxheight) { maxHeight = maxheight; }



	// Isaac 머리방향 //
	bool getBulletFireR() { return BulletFireR; }
	void setBulletFireR(int bulletfirer) { BulletFireR = bulletfirer; }
	bool getBulletFireL() { return BulletFireL; }
	void setBulletFireL(int bulletfirel) { BulletFireL = bulletfirel; }
	bool getBulletFireU() { return BulletFireU; }
	void setBulletFireU(int bulletfireu) { BulletFireU = bulletfireu; }
	bool getBulletFireD() { return BulletFireD; }
	void setBulletFireD(int bulletfired) { BulletFireD = bulletfired; }


	// vector //
	std::vector <ObjectBase*> objectVec;
	std::vector <Bullet*> isaacBulletVec;


	// 함수들을 모으는 함수 //
	void tick();


	// 기타 기능 함수들 //
	void CreateIsaac(Scene* scene);
	void IsaacMoving();
	void BulletFire();
	void PushBackBullet();
	void IsaacSetZoder();
	void CreateBomb();
};


