#pragma once
#include "ProjectFW.h"

class SoundManager
{
private:
	static SoundManager* instance;

	float bgmVolume;
	float sfxVolume;
	int mainMenuBgm;
	int charSelectLeft;
	int charSelectRight;
	int tearFire5;
	int tearFire4;
	int tearBlock;
	int titleScreenJingle;
	int dipteraSonata;
	int fireBurning;
	int explosion1;
	int ErrorBuzz;
	int insectSwarm;
	int hurtGrunt1;
	int hurtGrunt2;
	int hurtGrunt3;
	int pennyPickUp;
	int pennyDrop;
	int offFire;
	int plop;
	int doorUnlock;
	int shakeyKidRoar;
	int rockCrumble1;
	int rockCrumble2;
	int rockCrumble3;
	int meatyDeaths1;
	int meatyDeaths2;
	int meatyDeaths3;
	int meatyDeaths4;
	int meatyDeaths5;
	int unLock;
	int doorHeavyClose;
	int doorHeavyOpen;
	int bossFightIntroJingle;
	int castlePortCullis;
	int basicBossFight;
	int bossFightJingleOutro;
	int powerUp1;
	int powerUp2;
	int powerUp3;
	int powerUp4;
	int keyDrop;
	int keyPickUp;
	int BombPickUp;
	int dingWhistle;
	int dingleBulletFire;
	int dingleRush;
	int bloodFire1;
	int bloodFire2;
	int bloodFire3;
	int bloodFire4;
	int theCave;
	int scaredWhimper2;
	int spiderCoughs;
	int heartPickUp;

	SoundManager();
	~SoundManager() {};
public:
	static SoundManager* getInstance();
	static void releaseInstance();

	// ---- BGM ---- //
	void PlayMainMenuBgm();
	void StopMainMenuBgm();
	void PlaydipteraSonata();
	void StopdipteraSonata();

	// ---- Jingle ---- // 
	void PlayTitleScreenJingle();


	// ---- SFX ---- //
	void PlayCharSelectLeft();
	void PlayCharSelectRight();
	void PlayTearFire5();
	void PlayTearFire4();
	void PlayTearBlock();
	void PlayFireBurning();
	void StopFireBurning();
	void PlayExplosion1();
	void PlayErrorBuzz();   
	void PlayInsectSwarm();
	void StopInsectSwarm();
	void PlayHurtGrunt1();
	void PlayHurtGrunt2();
	void PlayHurtGrunt3();
	void PlayPennyPickUp();
	void PlayPennyDrop();
	void PlayOffFire();
	void PlayPlop();
	void PlayDoorUnlock();
	void PlayShakeyKidRoar();
	void PlayRockCrumble1();
	void PlayRockCrumble2();
	void PlayRockCrumble3();
	void PlayMeatyDeaths1();
	void PlayMeatyDeaths2();
	void PlayMeatyDeaths3();
	void PlayMeatyDeaths4();
	void PlayMeatyDeaths5();
	void PlayUnLock();
	void PlayDoorHeavyClose();
	void PlayDoorHeavyOpen();
	void PlayBossFightIntroJingle();
	void PlayCastlePortCullis();
	void PlayBasicBossFight();
	void PlayBossFightJingleOutro();
	void PlayPowerUp1();
	void PlayPowerUp2();
	void PlayPowerUp3();
	void PlayPowerUp4();
	void PlayKeyDrop();
	void PlayKeyPickUp();
	void PlayBombPickUp();
	void PlayDingleWhistle();
	void PlayDingleBulletFire();
	void PlayDingleRush();
	void PlayBloodFire1();
	void PlayBloodFire2();
	void PlayBloodFire3();
	void PlayBloodFire4();
	void PlayTheCave();
	void PlayScaredWhimper2();
	void PlaySpiderCoughs();
	void PlayHeartPickUp();

	// ---- GET/SET ---- //
	float getBgmVolume() { return bgmVolume; }
	void setBgmVolume(float bgmvolume) { bgmVolume = bgmvolume; }
	float getSfxVolume() { return sfxVolume; }
	void setSfxVolume(float sfxvolume) { sfxVolume = sfxvolume; }

	
	void RunnigBgmVolume();
	void RunnigSfxVolume();

};