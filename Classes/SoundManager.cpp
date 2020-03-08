#include "SoundManager.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
	bgmVolume = 0.2f;
	sfxVolume = 0.2f;
}

SoundManager * SoundManager::getInstance()
{
	if (!instance)
	{
		instance = new SoundManager;
	}

	return instance;
}

void SoundManager::releaseInstance()
{
	if (instance)
		delete instance;
}

void SoundManager::PlayMainMenuBgm()
{
	mainMenuBgm = AudioEngine::play2d("Sound/Bgm/title screen.ogg", true, bgmVolume);
}

void SoundManager::StopMainMenuBgm()
{
	AudioEngine::stop(mainMenuBgm);
}

void SoundManager::PlaydipteraSonata()
{
	dipteraSonata = AudioEngine::play2d("Sound/Bgm/diptera sonata(basement).ogg", true, bgmVolume);
}

void SoundManager::StopdipteraSonata()
{
	AudioEngine::stop(dipteraSonata);
}

void SoundManager::PlayTitleScreenJingle()
{
	titleScreenJingle = AudioEngine::play2d("Sound/Jingle/title screen jingle v1_01.ogg", false, bgmVolume);
}

void SoundManager::PlayCharSelectLeft()
{
	charSelectLeft = AudioEngine::play2d("Sound/Sfx/character select left.mp3", false, sfxVolume);
}

void SoundManager::PlayCharSelectRight()
{
	charSelectRight = AudioEngine::play2d("Sound/Sfx/character select right.mp3", false, sfxVolume);
}

void SoundManager::PlayTearFire5()
{
	tearFire5 = AudioEngine::play2d("Sound/Sfx/tear fire 5.mp3", false, sfxVolume);
}

void SoundManager::PlayTearFire4()
{
	tearFire4 = AudioEngine::play2d("Sound/Sfx/tear-fire-4.mp3", false, sfxVolume);
}

void SoundManager::PlayTearBlock()
{
	tearBlock = AudioEngine::play2d("Sound/Sfx/tear-block.mp3", false, sfxVolume);
}

void SoundManager::PlayFireBurning()
{
	if (AudioEngine::getState(fireBurning) != AudioEngine::AudioState::PLAYING)
	{
		fireBurning = AudioEngine::play2d("Sound/Sfx/fire burning.mp3", true, sfxVolume);
	}
}

void SoundManager::StopFireBurning()
{
	AudioEngine::stop(fireBurning);
}

void SoundManager::PlayExplosion1()
{
	explosion1 = AudioEngine::play2d("Sound/Sfx/boss-explosions-1.mp3", false, sfxVolume);
}

void SoundManager::PlayErrorBuzz()
{
	if (AudioEngine::getState(ErrorBuzz) != AudioEngine::AudioState::PLAYING)
	{
		ErrorBuzz = AudioEngine::play2d("Sound/Sfx/boss 2 intro errorbuzz.mp3", false, sfxVolume);
	}
}

void SoundManager::PlayInsectSwarm()
{
	if (AudioEngine::getState(insectSwarm) != AudioEngine::AudioState::PLAYING)
	{
		insectSwarm = AudioEngine::play2d("Sound/Sfx/insect swarm.mp3", false, 0.05f);
	}
	if (AudioEngine::getCurrentTime(insectSwarm) >= 0.7f)
	{
		insectSwarm = AudioEngine::play2d("Sound/Sfx/insect swarm.mp3", false, 0.05f);
	}
}

void SoundManager::StopInsectSwarm()
{
	AudioEngine::stop(insectSwarm);
}

void SoundManager::PlayHurtGrunt1()
{
	hurtGrunt1 = AudioEngine::play2d("Sound/Sfx/hurt grunt .mp3", false, sfxVolume);
}

void SoundManager::PlayHurtGrunt2()
{
	hurtGrunt2 = AudioEngine::play2d("Sound/Sfx/hurt grunt 1.mp3", false, sfxVolume);
}

void SoundManager::PlayHurtGrunt3()
{
	hurtGrunt3 = AudioEngine::play2d("Sound/Sfx/hurt grunt 2.mp3", false, sfxVolume);
}

void SoundManager::PlayPennyPickUp()
{
	pennyPickUp = AudioEngine::play2d("Sound/Sfx/penny-pickup-1.mp3", false, sfxVolume);
}

void SoundManager::PlayPennyDrop()
{
	pennyDrop = AudioEngine::play2d("Sound/Sfx/penny-drop-1.mp3", false, sfxVolume);
}

void SoundManager::PlayOffFire()
{
	offFire = AudioEngine::play2d("Sound/Sfx/steam-half-sec.mp3", false, sfxVolume);
}

void SoundManager::PlayPlop()
{
	plop= AudioEngine::play2d("Sound/Sfx/plop.mp3", false, sfxVolume);
}

void SoundManager::PlayDoorUnlock()
{
	doorUnlock = AudioEngine::play2d("Sound/Sfx/unlock.mp3", false, sfxVolume);
}

void SoundManager::PlayShakeyKidRoar()
{
	shakeyKidRoar = AudioEngine::play2d("Sound/Sfx/shakey-kid-roar.mp3", false, sfxVolume);
}

void SoundManager::PlayRockCrumble1()
{
	rockCrumble1 = AudioEngine::play2d("Sound/Sfx/rock_crumble_0.mp3", false, sfxVolume);
}

void SoundManager::PlayRockCrumble2()
{
	rockCrumble2 = AudioEngine::play2d("Sound/Sfx/rock_crumble_2.mp3", false, sfxVolume);
}

void SoundManager::PlayRockCrumble3()
{
	rockCrumble3 = AudioEngine::play2d("Sound/Sfx/rock_crumble_3.mp3", false, sfxVolume);
}

void SoundManager::PlayMeatyDeaths1()
{
	meatyDeaths1 = AudioEngine::play2d("Sound/Sfx/meaty_deaths_0.mp3", false, sfxVolume);
}

void SoundManager::PlayMeatyDeaths2()
{
	meatyDeaths2 = AudioEngine::play2d("Sound/Sfx/meaty_deaths_1.mp3", false, sfxVolume);
}

void SoundManager::PlayMeatyDeaths3()
{
	meatyDeaths3 = AudioEngine::play2d("Sound/Sfx/meaty_deaths_2.mp3", false, sfxVolume);
}

void SoundManager::PlayMeatyDeaths4()
{
	meatyDeaths4 = AudioEngine::play2d("Sound/Sfx/meaty_deaths_3.mp3", false, sfxVolume);
}

void SoundManager::PlayMeatyDeaths5()
{
	meatyDeaths5 = AudioEngine::play2d("Sound/Sfx/meaty_deaths_4.mp3", false, sfxVolume);
}

void SoundManager::PlayUnLock()
{
	unLock = AudioEngine::play2d("Sound/Sfx/unlock.mp3", false, sfxVolume);
}

void SoundManager::PlayDoorHeavyClose()
{
	doorHeavyClose = AudioEngine::play2d("Sound/Sfx/door_heavy_close.mp3", false, sfxVolume);
}

void SoundManager::PlayDoorHeavyOpen()
{
	doorHeavyOpen = AudioEngine::play2d("Sound/Sfx/door_heavy_open.mp3", false, sfxVolume);
}

void SoundManager::PlayBossFightIntroJingle()
{
	bossFightIntroJingle = AudioEngine::play2d("Sound/Jingle/boss fight intro jingle v2.1.mp3", false, bgmVolume);
}

void SoundManager::PlayCastlePortCullis()
{
	castlePortCullis = AudioEngine::play2d("Sound/Sfx/castleportcullis.mp3", false, sfxVolume);
}

void SoundManager::PlayBasicBossFight()
{
	basicBossFight = AudioEngine::play2d("Sound/Bgm/basic boss fight.ogg", true, bgmVolume);
}

void SoundManager::PlayBossFightJingleOutro()
{
	bossFightJingleOutro = AudioEngine::play2d("Sound/Jingle/boss fight jingle outro v2_12.ogg", false, bgmVolume);
}

void SoundManager::PlayPowerUp1()
{
	powerUp1 = AudioEngine::play2d("Sound/Sfx/power up1.mp3", false, sfxVolume);
}

void SoundManager::PlayPowerUp2()
{
	powerUp2 = AudioEngine::play2d("Sound/Sfx/power up3.mp3", false, sfxVolume);
}

void SoundManager::PlayPowerUp3()
{
	powerUp3 = AudioEngine::play2d("Sound/Sfx/power up4.mp3", false, sfxVolume);
}

void SoundManager::PlayPowerUp4()
{
	powerUp4 = AudioEngine::play2d("Sound/Sfx/power up7.mp3", false, sfxVolume);
}

void SoundManager::PlayKeyDrop()
{
	keyDrop = AudioEngine::play2d("Sound/Sfx/key_drop_2.mp3", false, sfxVolume);
}

void SoundManager::PlayKeyPickUp()
{
	keyPickUp = AudioEngine::play2d("Sound/Sfx/key_pickup_guantlet_4.mp3", false, sfxVolume);
}

void SoundManager::PlayBombPickUp()
{
	BombPickUp = AudioEngine::play2d("Sound/Sfx/fetus feet.mp3", false, sfxVolume);
}

void SoundManager::PlayDingleWhistle()
{
	dingWhistle = AudioEngine::play2d("Sound/Sfx/ding whistle whistle.mp3", false, sfxVolume);
}

void SoundManager::PlayDingleBulletFire()
{
	dingleBulletFire = AudioEngine::play2d("Sound/Sfx/sink drain gurgle.mp3", false, sfxVolume);
}

void SoundManager::PlayDingleRush()
{
	dingleRush = AudioEngine::play2d("Sound/Sfx/fart gurg.mp3", false, sfxVolume);
}

void SoundManager::PlayBloodFire1()
{
	bloodFire1 = AudioEngine::play2d("Sound/Sfx/blood fire.mp3", false, sfxVolume);
}

void SoundManager::PlayBloodFire2()
{
	bloodFire2 = AudioEngine::play2d("Sound/Sfx/blood fire 2.mp3", false, sfxVolume);
}

void SoundManager::PlayBloodFire3()
{
	bloodFire3 = AudioEngine::play2d("Sound/Sfx/blood fire 3.mp3", false, sfxVolume);
}

void SoundManager::PlayBloodFire4()
{
	bloodFire4 = AudioEngine::play2d("Sound/Sfx/blood fire 4.mp3", false, sfxVolume);
}

void SoundManager::PlayTheCave()
{
	theCave = AudioEngine::play2d("Sound/Bgm/the caves.ogg", true, bgmVolume);
}

void SoundManager::PlayScaredWhimper2()
{
	scaredWhimper2 = AudioEngine::play2d("Sound/Sfx/scared whimper 2.mp3", false, sfxVolume);
}

void SoundManager::PlaySpiderCoughs()
{
	spiderCoughs = AudioEngine::play2d("Sound/Sfx/spider coughs.mp3", false, sfxVolume);
}

void SoundManager::PlayHeartPickUp()
{
	heartPickUp = AudioEngine::play2d("Sound/Sfx/boss 2 bubbles.mp3", false, sfxVolume);
}

void SoundManager::RunnigBgmVolume()
{
	AudioEngine::setVolume(mainMenuBgm, bgmVolume);
}

void SoundManager::RunnigSfxVolume()
{

}
