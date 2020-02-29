#pragma once
#include "ProjectFW.h"

class ObjectBase;

class Bullet;

class MonsterBullet;

class IsaacBoom;

class MonsterBase;

class ItemBase;

enum NowScene // 1 ~ 50
{
	PressStartScene = 1,
	FileSelectScene,
	MainMenuScene,
	CharSelectScene,
	OptionScene,
	StatsScreen,
	StageScreen,
	PlayerDeadScreen,
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
	ObjectMonster,
};

enum DoorName // 301 ~ 350
{
	NormalDoor = 301,
	TreasureDoor,
	TreasureNoneKeyDoor,
	BossRoomDoor,
	OpenDoor,
	CloseDoor,
};

enum MonsterTAG // 351 ~ 400
{
	MonsterColiisionBullet = 351,
	MonsterIdle,
	MonsterAttack,
	MonsterErase,
	MonsterCollisionBomb,
	MonsterEraseOnVec,
};

enum BombKind// 401 ~ 450
{
	BaseMentBomb = 401,
};

enum MonsterKind // 451 ~ 500
{
	MonsterKind_Fly = 451,
	MonsterKind_Dip,
	MonsterKind_Horf,
	MonsterKind_Pooter,
	MonsterKind_Dingle,
};

enum IsaacInfo// 501 ~ 550
{
	IsaacIdle = 501,
	IsaacTakeDamage,
	IsaacGetItem,
};

enum ItemTag// 551 ~ 600
{
	ItemIdle = 551,
	ItemErase,
};

enum ItemKind// 601 ~ 650
{
	StigmataITEM = 601,
	TheSadOnionITEM,
};

//enum AtionTag // 1001 ~ 1500
//{
//
//};

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
	IsaacInfo _isaacInfo; // �����ۻ���

	IsaacBoom* isaacBoom; // ������ ��ź

	Sprite* isaacHead_Base; // Isaac �Ӹ�
	Sprite* isaacBody_Base; // Isaac ����
	Sprite* isaacShadow; // Isaac �׸���
	Sprite* coinUiIcon;
	Sprite* bombUiIcon;
	Sprite* keyUiIcon;
	Sprite* HeartIcon[10]; 
	Sprite* DoorOpenKey;
	Sprite* getItemSprite;
	Sprite* getItemBackGround;
	Sprite* IsaacVirtualBody; // ���� Ư�� �׼ǿ� ����� ����������Ʈ

	PhysicsBody* isaacPhysicBody; // Isaac ������ ���� 

	Label* coinUitext;
	Label* bombUitext;
	Label* keyUitext;

	Label* showDebug_moveSeepd;
	Label* showDebug_FireCycle;
	Label* showDebug_bulletRange;
	Label* showDebug_bulletMoveSpeed;
	Label* showDebug_effectiveDmg;
	Label* showDebug_ItemInvLuck;

	Label* getItemInfoText1;
	Label* getItemInfoText2;

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
	Animation* DoorOpenkeyAnimation;
	Animate* DoorOpenkeyAnimate;
	Animation* GetItemAnimation;
	Animate* GetItemAnimate;
	Animation* IsaacGoToNextDoorAnimation;
	Animate* IsaacGoToNextDoorAnimate;

	int mainMenuIndex; // ���θ޴� �ε���
	int charSelectIndex; // ĳ���� ���� �ε���
	int difficultySelectIndex; // ���̵� ���� �ε���
	int OptionIndex; // �ɼǼ��� �ε���
	int OptionSfxIndex; // �ɼ�Sfx �ε���
	int OptionBgmIndex; // �ɼ�Bgm �ε���
	int RoomNumber; // ���� �����ϴ� �ε���
	int stageNumber; // ���������� �����ϴ� �ε���
	int BombCount; // ��ź ����
	int coinCount; // ���� ����
	int keyCount; // ���� ����
	int MaxHp; // �ִ�ü��
	int Hp; // ü��
	int godModeCount1; // �����
	int godModeCount2; // �����
	int getItemCount1;

	float MoveSpeed; // Isaac ���ǵ�
	float BulletFireCycle; // �Ѿ˹߻�ӵ�(�ֱ�)
	float bulletRange; // �Ѿ� ��Ÿ�
	float bulletMoveSpeed; // �Ѿ� ������ ���ǵ� 
	float basicHeight; // �Ѿ� �⺻ ���� 
	float maxHeight; // �Ѿ� �ִ� ����
	float BaseDmg; // �⺻���ݷ�
	float totalDmgUps; // ȹ���� �����۵��� ������ �հ�
	float effectiveDmg; // ����������
	float totalLuck; // ���������� ���� ���� �� max == 10
	float BaseLuck; // �⺻ ��
	float itemInvLuck; // ����� ���� ��

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
	bool GodMode; // ����
	bool isIsaacGetItem;
	bool isShowDebug;
	bool isLoadingScene;
	bool PlayerIsDead; // �÷��̾� ����

	bool miniMapPlayerMoveU;
	bool miniMapPlayerMoveD;
	bool miniMapPlayerMoveR;
	bool miniMapPlayerMoveL;

public:
	static Isaac* getInstance();
	static void releaseInstance();


	// Scene,Screen Control //
	NowScene getNowScene() { return nowScene; }
	void setNowScene(NowScene nowscene) { nowScene = nowscene; }
	void setIsaacInfo(IsaacInfo isaacinfo) { _isaacInfo = isaacinfo; }
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
	bool getPlayerIsDead() { return PlayerIsDead; }
	void setPlayerIsDead(bool playerisdead) { PlayerIsDead = playerisdead; }

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
	Sprite* getDoorOpenKey() { return DoorOpenKey; }
	Sprite* getIsaacVirtualBody() { return IsaacVirtualBody; }
	Animate* getDoorOpenkeyAnimate() { return DoorOpenkeyAnimate; }
	Animate* getIsaacGoToNextDoorAnimate() { return IsaacGoToNextDoorAnimate; }

	// ------------------------------------------------------ float ------------------------------------------------------ // 
	float getBulletRange() { return bulletRange; }
	void setBulletRange(float bulletrange) { bulletRange = bulletrange; }
	float getBulletMoveSpeed() { return bulletMoveSpeed; }
	void setBulletMoveSpeed(float bulletmovespeed) { bulletMoveSpeed = bulletmovespeed; }
	float getBasicHeight() { return basicHeight; }
	void setBasicHeight(float basicheight) { basicHeight = basicheight; }
	float getMaxHeight() { return maxHeight; }
	void setMaxHeight(float maxheight) { maxHeight = maxheight; }
	float getBaseDmg() { return BaseDmg; }
	void setBaseDmg(float basedmg) { BaseDmg = basedmg; }
	float getTotalDmgUps() { return totalDmgUps; }
	void setTotalDmgUps(float totaldmgups) { totalDmgUps = totaldmgups; }
	float getEffectiveDmg() { return effectiveDmg; }
	void setEffectiveDmg(float effectivedmg) { effectiveDmg = effectivedmg; }
	float getTotalLuck() { return totalLuck; }
	void setTotalLuck(float totalluck) { totalLuck = totalluck; }
	float getBaseLuck() { return BaseLuck; }
	void setBaseLuck(float baseluck) { BaseLuck = baseluck; }
	float getItemInvLuck() { return itemInvLuck; }
	void setItemInvLuck(float iteminvluck) { itemInvLuck = iteminvluck; }

	// ------------------------------------------------------ int ------------------------------------------------------ // 
	int getBombCount() { return BombCount; }
	void setBombCount(float bombcount) { BombCount = bombcount; }
	int getCoinCount() { return coinCount; }
	void setCoinCount(float coincount) { coinCount = coincount; }
	int getKeyCount() { return keyCount; }
	void setKeyCount(float keycount) { keyCount = keycount; }
	int getMaxHp() { return MaxHp; }
	void setMaxHp(float maxhp) { MaxHp = maxhp; }
	int getHp() { return Hp; }
	void setHp(float hp) { Hp = hp; }
	int getStageNumber() { return stageNumber; }
	void setStageNumber(float stagenumber) { stageNumber = stagenumber; }



	// Isaac �Ӹ����� //
	bool getBulletFireR() { return BulletFireR; }
	void setBulletFireR(int bulletfirer) { BulletFireR = bulletfirer; }
	bool getBulletFireL() { return BulletFireL; }
	void setBulletFireL(int bulletfirel) { BulletFireL = bulletfirel; }
	bool getBulletFireU() { return BulletFireU; }
	void setBulletFireU(int bulletfireu) { BulletFireU = bulletfireu; }
	bool getBulletFireD() { return BulletFireD; }
	void setBulletFireD(int bulletfired) { BulletFireD = bulletfired; }
	bool getIsIsaacGetItem() { return isIsaacGetItem; }
	
	bool getIsLoadingScene() { return isLoadingScene; }
	void setIsLoadingScene(bool isloadingscene) { isLoadingScene = isloadingscene; }

	bool getMiniMapPlayerU() { return miniMapPlayerMoveU; }
	void setMiniMapPlayerU(bool minimapplayeru) { miniMapPlayerMoveU = minimapplayeru; }
	bool getMiniMapPlayerD() { return miniMapPlayerMoveD; }
	void setMiniMapPlayerD(bool minimapplayerd) { miniMapPlayerMoveD = minimapplayerd; }
	bool getMiniMapPlayerR() { return miniMapPlayerMoveR; }
	void setMiniMapPlayerR(bool minimapplayerr) { miniMapPlayerMoveR = minimapplayerr; }
	bool getMiniMapPlayerL() { return miniMapPlayerMoveL; }
	void setMiniMapPlayerL(bool minimapplayerl) { miniMapPlayerMoveL = minimapplayerl; }


	// vector //
	std::vector <ObjectBase*> objectVec;
	std::vector <Bullet*> isaacBulletVec;
	std::vector <MonsterBase*> monsterVec;
	std::vector <MonsterBullet*> monsterBulletVec;
	std::vector <ItemBase*> itemBaseVec;


	// �Լ����� ������ �Լ� //
	void tick();


	// ��Ÿ ��� �Լ��� //
	void CreateIsaac(Scene* scene);
	void IsaacMoving();
	void BulletFire();
	void PushBackBullet();
	void IsaacSetZoder();
	void CreateBomb();
	void setUIPosition();
	void SetGodMode();
	void doGetItemAction(ItemKind itemkind);
	void IsaacChangeInfo1();
	void showDebugInfo();
};


