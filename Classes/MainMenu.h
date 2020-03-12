#pragma once
#include "ProjectFW.h"
#include "LodingScreen1.h"

class MainMenu : public Scene
{
private:
	Sprite* outSideBackGround;

	// All Screen
	Sprite* menuOverlay1;
	Sprite* menuOverlay2;

	// PressStart Screen
	Sprite* titleMenuImage;
	Sprite* title;
	Sprite* titleMenuPressStart;

	// FileSelect Screen
	Sprite* File1;
	Sprite* File2;
	Sprite* File3;
	Sprite* BackGound;
	Sprite* DeleteFileText;
	Sprite* FileSelectText;
	Sprite* IsaacDrawing1;
	Sprite* IsaacDrawing2;
	Sprite* IsaacDrawing3;

	// MainMenu Screen
	Sprite* mainMenuBackGround;
	Sprite* mainMenuText1;
	Sprite* mainMenuText2;
	Sprite* mainMenuText3;
	Sprite* mainMenuText4;
	Sprite* mainMenuText5;
	Sprite* mainMenuPointer;

	// CharacterSelect Screen
	Sprite* CharSelectBackGround;
	Sprite* Characters[10];
	Sprite* CharSelectPointerL;
	Sprite* CharSelectPointerR;
	Sprite* CharNameText;
	Sprite* CharInfo;
	Sprite* CharSelectSceneOrnament1;
	Sprite* CharWinStreak;
	Sprite* CharDifficultyWidget;
	Sprite* CharDifficultyNormal;
	Sprite* CharDifficultyHard;
	Sprite* CharDifficultyIcon;
	Sprite* CharDifficultyPointer;
	Sprite* CharSeedWidget;
	Sprite* CharDifficultyHardBlood;

	// Option Screen
	Sprite* OptionMenuPost;
	Sprite* OptionBackGround;
	Sprite* OptionSketch1;
	Sprite* OptionSketch2;
	Sprite* OptionSketch3;
	Sprite* OptionSketch4;
	Sprite* OptionSFX;
	Sprite* OptionMusic;
	Sprite* OptionMapOpacity;
	Sprite* OptionFullScreen;
	Sprite* OptionFilter;
	Sprite* OptionON;
	Sprite* OptionOFF;
	Sprite* OptionBar1;
	Sprite* OptionBar2;
	Sprite* OptionBar3;
	Sprite* OptionPointer;



public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MainMenu);

	void tick(float delta);
};