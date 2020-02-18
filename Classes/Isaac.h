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

	Scene* _scene; // ��

	SpriteFrameCache* cache; // ĳ��

	NowScene nowScene; // ���� ���� �����ϴ� enum
	BulletVector bulletVector; // Bullet�� ���� enum

	Sprite* isaacHead_Base; // Isaac �Ӹ�
	Sprite* isaacBody_Base; // Isaac ����
	PhysicsBody* isaacPhysicBody; // Isaac ������ ���� 
	Sprite* isaacShadow; // Isaac �׸���

	IsaacBoom* isaacBoom; // ������ ��ź

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

	int mainMenuIndex; // ���θ޴� �ε���
	int charSelectIndex; // ĳ���� ���� �ε���
	int difficultySelectIndex; // ���̵� ���� �ε���
	int OptionIndex; // �ɼǼ��� �ε���
	int OptionSfxIndex; // �ɼ�Sfx �ε���
	int OptionBgmIndex; // �ɼ�Bgm �ε���
	int RoomNumber; // ���� �����ϴ� �ε���
	int BombCount; // ��ź ����

	float MoveSpeed; // Isaac ���ǵ�
	float BulletFireCycle; // �Ѿ˹߻�ӵ�(�ֱ�)
	float bulletRange; // �Ѿ� ��Ÿ�
	float bulletMoveSpeed; // �Ѿ� ������ ���ǵ� 
	float basicHeight; // �Ѿ� �⺻ ���� 
	float maxHeight; // �Ѿ� �ִ� ����


	bool ControlAtivation; // �������� �������� �ش�.
	bool SceneChange; // ����ȯ
	bool MoveR; // ������ ������
	bool MoveL; // ���� ������
	bool MoveU;	// ���� ������
	bool MoveD;	// �Ʒ��� ������
	bool BulletFireR; // �Ѿ˹߻� R
	bool BulletFireL; // �Ѿ˹߻� L
	bool BulletFireU; // �Ѿ˹߻� U
	bool BulletFireD; // �Ѿ˹߻� D
	bool BombActivation; // ��ź Ȱ��ȭ

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



	// Isaac �Ӹ����� //
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


	// �Լ����� ������ �Լ� //
	void tick();


	// ��Ÿ ��� �Լ��� //
	void CreateIsaac(Scene* scene);
	void IsaacMoving();
	void BulletFire();
	void PushBackBullet();
	void IsaacSetZoder();
	void CreateBomb();
};


