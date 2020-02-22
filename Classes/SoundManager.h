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

	// ---- GET/SET ---- //
	float getBgmVolume() { return bgmVolume; }
	void setBgmVolume(float bgmvolume) { bgmVolume = bgmvolume; }
	float getSfxVolume() { return sfxVolume; }
	void setSfxVolume(float sfxvolume) { sfxVolume = sfxvolume; }

	
	void RunnigBgmVolume();
	void RunnigSfxVolume();

};