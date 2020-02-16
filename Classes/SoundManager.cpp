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

void SoundManager::RunnigBgmVolume()
{
	AudioEngine::setVolume(mainMenuBgm, bgmVolume);
}

void SoundManager::RunnigSfxVolume()
{

}
