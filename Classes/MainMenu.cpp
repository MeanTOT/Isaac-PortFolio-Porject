#include "MainMenu.h"

Scene * MainMenu::createScene()
{
	return MainMenu::create();
}

bool MainMenu::init()
{
	if (!Scene::init())
		return false;

	
	// ---------- PressStart Screen ---------- //
	
	// 백그라운드
	titleMenuImage = Sprite::create("TitleMenu/titlemenu_01.png");
	titleMenuImage->setPosition(Position_50_50_);
	this->addChild(titleMenuImage);

	// 제목
	title = Sprite::create("TitleMenu/THEBINDINGOFISAACFONT_02.png");
	title->setPosition(Position_50_50_.x, Position_50_50_.y + 90);
	this->addChild(title);

	// PressStart 이미지
	titleMenuPressStart = Sprite::create("TitleMenu/titlemenu_10.png");
	titleMenuPressStart->setPosition(Position_50_50_.x - 13, Position_50_50_ .y - 40);
	this->addChild(titleMenuPressStart);

	// PressStart 애니메이션
	auto PressStartAnimation = Animation::create();
	PressStartAnimation->setDelayPerUnit(0.2f);
	PressStartAnimation->addSpriteFrameWithFile("TitleMenu/titlemenu_10.png");
	PressStartAnimation->addSpriteFrameWithFile("TitleMenu/titlemenu_11.png");
	auto PressStartAnimate = Animate::create(PressStartAnimation);
	auto PressStartReapeatForever = RepeatForever::create(PressStartAnimate);

	// PressStart 애니메이션 실행
	titleMenuPressStart->runAction(PressStartReapeatForever);

	// 제목 애니메이션 실행
	auto titleAction = RepeatForever::create(Sequence::create(RotateBy::create(1.f, Vec3(0, 0, 2)), RotateBy::create(1.f, Vec3(0, 0, 2))->reverse(), nullptr));
	title->runAction(titleAction);
	



	// ---------- FileSelect Screen ---------- //

	BackGound = Sprite::create("TitleMenu/FileSelectBg.png");
	BackGound->setPosition(Position_50_49_);
	BackGound->setScaleY(19.5f);
	BackGound->setScaleX(30.f);
	this->addChild(BackGound);

	File1 = Sprite::create("TitleMenu/File_1.png");
	File1->setPosition(Position_50_49_.x - 150, Position_50_49_.y + 30);
	File1->setOpacity(255.f);
	this->addChild(File1);

	File2 = Sprite::create("TitleMenu/File_2.png");
	File2->setPosition(Position_50_49_.x, Position_50_49_.y + 10);
	File2->setOpacity(120.f);
	this->addChild(File2);

	File3 = Sprite::create("TitleMenu/File_3.png");
	File3->setPosition(Position_50_49_.x + 160, Position_50_49_.y + 10);
	File3->setOpacity(120.f);
	this->addChild(File3);

	DeleteFileText = Sprite::create("TitleMenu/DeleteFile.png");
	DeleteFileText->setPosition(Position_50_49_.x, Position_50_49_.y - 110);
	DeleteFileText->setOpacity(120.f);
	this->addChild(DeleteFileText);

	FileSelectText = Sprite::create("TitleMenu/FileSelectText.png");
	FileSelectText->setPosition(Position_50_49_.x, Position_50_49_.y + 120);
	this->addChild(FileSelectText);

	auto FileSelectAnimation = Animation::create();
	FileSelectAnimation->setDelayPerUnit(0.2f);
	FileSelectAnimation->addSpriteFrameWithFile("TitleMenu/SelectFileAni_01.png");
	FileSelectAnimation->addSpriteFrameWithFile("TitleMenu/SelectFileAni_02.png");
	auto FileSelectAnimate = Animate::create(FileSelectAnimation);
	auto FileSelectReapeatForever = RepeatForever::create(FileSelectAnimate);

	IsaacDrawing1 = Sprite::create("TitleMenu/SelectFileAni_01.png");
	File1->addChild(IsaacDrawing1);
	IsaacDrawing1->setPosition(Vec2(IsaacDrawing1->getParent()->getContentSize().width / 2 + 5, (IsaacDrawing1->getParent()->getContentSize().height / 2 + 15)));
	IsaacDrawing1->runAction(FileSelectReapeatForever);

	IsaacDrawing2 = Sprite::create("TitleMenu/SelectFileAni_01.png");
	File2->addChild(IsaacDrawing2);
	IsaacDrawing2->setPosition(Vec2(IsaacDrawing2->getParent()->getContentSize().width / 2, (IsaacDrawing2->getParent()->getContentSize().height / 2 + 15)));

	IsaacDrawing3 = Sprite::create("TitleMenu/SelectFileAni_01.png");
	File3->addChild(IsaacDrawing3);
	IsaacDrawing3->setPosition(Vec2(IsaacDrawing3->getParent()->getContentSize().width / 2 - 10, (IsaacDrawing3->getParent()->getContentSize().height / 2 + 15)));




	// ---------- MainMenu Screen ---------- //

	mainMenuBackGround = Sprite::create("TitleMenu/gamemenuBg.png");
	mainMenuBackGround->setPosition(Position_50_48_);
	this->addChild(mainMenuBackGround);

	mainMenuText1 = Sprite::create("TitleMenu/NewRunText.png");
	mainMenuText1->setPosition(Position_50_48_.x, Position_50_48_.y + 80);
	this->addChild(mainMenuText1);

	mainMenuText2 = Sprite::create("TitleMenu/ContinueText.png");
	mainMenuText2->setPosition(Position_50_48_.x + 2, Position_50_48_.y + 45);
	this->addChild(mainMenuText2);

	mainMenuText3 = Sprite::create("TitleMenu/ChallengesText.png");
	mainMenuText3->setPosition(Position_50_48_.x + 6, Position_50_48_.y + 10);
	this->addChild(mainMenuText3);

	mainMenuText4 = Sprite::create("TitleMenu/StatsText.png");
	mainMenuText4->setPosition(Position_50_48_.x + 10, Position_50_48_.y - 30);
	this->addChild(mainMenuText4);

	mainMenuText5 = Sprite::create("TitleMenu/OptionsText.png");
	mainMenuText5->setPosition(Position_50_48_.x + 14, Position_50_48_.y - 70);
	this->addChild(mainMenuText5);

	mainMenuPointer = Sprite::create("TitleMenu/gamemenuPointer.png");
	mainMenuPointer->setPosition(Position_50_48_.x - 75, Position_50_48_.y + 85);
	this->addChild(mainMenuPointer);





	// ---------- CharSelect Screen ---------- //

	CharSelectBackGround = Sprite::create("TitleMenu/charactermenuBg.png");
	CharSelectBackGround->setPosition(Position_51_48_);
	this->addChild(CharSelectBackGround);

	Characters[0] = Sprite::create("TitleMenu/charactermenu_01.png");
	Characters[0]->setPosition(Position_51_48_);
	this->addChild(Characters[0]);

	Characters[1] = Sprite::create("TitleMenu/charactermenu_08.png");
	Characters[1]->setPosition(Position_51_48_.x + 40, Position_51_48_.y + 10);
	Characters[1]->setOpacity(150);
	Characters[1]->setScale(0.9f);
	this->addChild(Characters[1]);

	Characters[2] = Sprite::create("TitleMenu/charactermenu_02.png");
	Characters[2]->setPosition(Position_51_48_.x + 75, Position_51_48_.y + 20);
	Characters[2]->setOpacity(150);
	Characters[2]->setScale(0.8f);
	this->addChild(Characters[2]);

	Characters[3] = Sprite::create("TitleMenu/charactermenu_10.png");
	Characters[3]->setPosition(Position_51_48_.x + 75, Position_51_48_.y + 35);
	Characters[3]->setScale(0.7f);
	Characters[3]->setOpacity(150);
	this->addChild(Characters[3]);

	Characters[4] = Sprite::create("TitleMenu/charactermenu_12.png");
	Characters[4]->setPosition(Position_51_48_.x + 40, Position_51_48_.y + 50);
	Characters[4]->setScale(0.6f);
	Characters[4]->setOpacity(150);
	this->addChild(Characters[4]);

	Characters[5] = Sprite::create("TitleMenu/charactermenu_14.png");
	Characters[5]->setPosition(Position_51_48_.x, Position_51_48_.y + 55);
	Characters[5]->setScale(0.5f);
	Characters[5]->setOpacity(150);
	this->addChild(Characters[5]);

	Characters[6] = Sprite::create("TitleMenu/charactermenu_16.png");
	Characters[6]->setPosition(Position_51_48_.x - 40, Position_51_48_.y + 50);
	Characters[6]->setScale(0.6f);
	Characters[6]->setOpacity(150);
	this->addChild(Characters[6]);

	Characters[7] = Sprite::create("TitleMenu/charactermenu_18.png");
	Characters[7]->setPosition(Position_51_48_.x - 75, Position_51_48_.y + 35);
	Characters[7]->setScale(0.7f);
	Characters[7]->setOpacity(150);
	this->addChild(Characters[7]);

	Characters[8] = Sprite::create("TitleMenu/charactermenu_21.png");
	Characters[8]->setPosition(Position_51_48_.x - 75, Position_51_48_.y + 20);
	Characters[8]->setOpacity(150);
	Characters[8]->setScale(0.8f);
	this->addChild(Characters[8]);

	Characters[9] = Sprite::create("TitleMenu/charactermenu_20.png");
	Characters[9]->setPosition(Position_51_48_.x - 40, Position_51_48_.y + 10);
	Characters[9]->setOpacity(150);
	Characters[9]->setScale(0.9f);
	this->addChild(Characters[9]);

	CharSelectPointerL = Sprite::create("TitleMenu/charactermenuPointer_01.png");
	CharSelectPointerL->setPosition(Position_51_48_.x - 60, Position_51_48_.y - 40);
	this->addChild(CharSelectPointerL);

	CharSelectPointerR = Sprite::create("TitleMenu/charactermenuPointer_02.png");
	CharSelectPointerR->setPosition(Position_51_48_.x + 60, Position_51_48_.y - 40);
	this->addChild(CharSelectPointerR);

	CharNameText = Sprite::create("TitleMenu/charactermenuText_03.png");
	CharNameText->setPosition(Position_51_48_.x, Position_51_48_.y - 40);
	this->addChild(CharNameText);

	CharInfo = Sprite::create("TitleMenu/characterInfo_1.png");
	CharInfo->setPosition(Position_51_48_.x, Position_51_48_.y - 60);
	this->addChild(CharInfo);

	CharSelectSceneOrnament1 = Sprite::create("TitleMenu/ChaerSelectSceneOrnament1.png");
	CharSelectSceneOrnament1->setPosition(Position_51_48_.x- 130, Position_51_48_.y + 50);
	this->addChild(CharSelectSceneOrnament1);

	CharWinStreak = Sprite::create("TitleMenu/winstreakwidget.png");
	CharWinStreak->setPosition(Position_51_48_.x - 145, Position_51_48_.y - 40);
	this->addChild(CharWinStreak);

	CharDifficultyWidget = Sprite::create("TitleMenu/difficultywidget.png");
	CharDifficultyWidget->setPosition(Position_51_48_.x + 160, Position_51_48_.y);
	this->addChild(CharDifficultyWidget);

	CharDifficultyNormal = Sprite::create("TitleMenu/difficultyNormal.png");
	CharDifficultyNormal->setPosition(55,45);
	CharDifficultyWidget->addChild(CharDifficultyNormal);

	CharDifficultyHard = Sprite::create("TitleMenu/difficultyHard.png");
	CharDifficultyHard->setPosition(40, 30);
	CharDifficultyHard->setOpacity(100);
	CharDifficultyWidget->addChild(CharDifficultyHard);

	CharDifficultyIcon = Sprite::create("TitleMenu/difficultyIcon.png");
	CharDifficultyIcon->setPosition(74, 27);
	CharDifficultyIcon->setOpacity(100);
	CharDifficultyWidget->addChild(CharDifficultyIcon);

	CharDifficultyPointer = Sprite::create("TitleMenu/difficultyPointer.png");
	CharDifficultyPointer->setPosition(CharDifficultyNormal->getPosition().x - 40, CharDifficultyNormal->getPosition().y + 10);
	CharDifficultyWidget->addChild(CharDifficultyPointer);

	CharSeedWidget = Sprite::create("TitleMenu/seedwidget.png");
	CharSeedWidget->setPosition(Position_51_48_.x + 170, Position_51_48_.y + 70);
	this->addChild(CharSeedWidget);

	CharDifficultyHardBlood = Sprite::create("TitleMenu/DifficultyHardBlood.png");
	CharDifficultyHardBlood->setPosition(Position_51_48_.x + 37, Position_51_48_.y - 100);
	CharDifficultyHardBlood->setOpacity(0);
	this->addChild(CharDifficultyHardBlood);




	
	// ---------- Option Screen ---------- //

	OptionBackGround = Sprite::create("TitleMenu/FileSelectBg.png");
	OptionBackGround->setPosition(Position_51_47_);
	OptionBackGround->setScaleY(18.f);
	OptionBackGround->setScaleX(30.f);
	this->addChild(OptionBackGround);

	OptionSketch1 = Sprite::create("TitleMenu/sketch_01.png");
	OptionSketch1->setPosition(Position_51_47_.x - 190, Position_51_47_.y + 70);
	this->addChild(OptionSketch1);

	OptionSketch2 = Sprite::create("TitleMenu/sketch_02.png");
	OptionSketch2->setPosition(Position_51_47_.x - 118, Position_51_47_.y);
	this->addChild(OptionSketch2);

	OptionSketch3 = Sprite::create("TitleMenu/sketch_04.png");
	OptionSketch3->setPosition(Position_51_47_.x + 140, Position_51_47_.y + 80);
	this->addChild(OptionSketch3);

	OptionSketch4 = Sprite::create("TitleMenu/sketch_03.png");
	OptionSketch4->setPosition(Position_51_47_.x + 170, Position_51_47_.y - 40);
	this->addChild(OptionSketch4);

	OptionMenuPost = Sprite::create("TitleMenu/optionsmenu.png");
	OptionMenuPost->setPosition(Position_51_47_);
	this->addChild(OptionMenuPost);

	OptionSFX = Sprite::create("TitleMenu/optionSFX.png");
	OptionSFX->setPosition(Position_51_47_.x - 50, Position_51_47_.y + 40);
	this->addChild(OptionSFX);

	OptionMusic = Sprite::create("TitleMenu/optionMusic.png");
	OptionMusic->setPosition(Position_51_47_.x - 50, Position_51_47_.y + 15);
	this->addChild(OptionMusic);

	OptionMapOpacity = Sprite::create("TitleMenu/optionMapOpacity.png");
	OptionMapOpacity->setPosition(Position_51_47_.x - 30, Position_51_47_.y - 10);
	this->addChild(OptionMapOpacity);

	OptionFullScreen = Sprite::create("TitleMenu/optionFullScreen.png");
	OptionFullScreen->setPosition(Position_51_47_.x - 30, Position_51_47_.y - 35);
	this->addChild(OptionFullScreen);

	OptionFilter = Sprite::create("TitleMenu/optionFilter.png");
	OptionFilter->setPosition(Position_51_47_.x - 40, Position_51_47_.y - 60);
	this->addChild(OptionFilter);

	OptionON = Sprite::create("TitleMenu/optionON.png");
	OptionON->setPosition(Position_51_47_.x + 60, Position_51_47_.y - 35);
	this->addChild(OptionON);

	OptionOFF = Sprite::create("TitleMenu/optionOFF.png");
	OptionOFF->setPosition(Position_51_47_.x + 60, Position_51_47_.y - 60);
	this->addChild(OptionOFF);

	OptionBar1 = Sprite::create("TitleMenu/SoundBar1_2.png");
	OptionBar1->setPosition(Position_51_47_.x + 60, Position_51_47_.y + 40);
	this->addChild(OptionBar1);

	OptionBar2 = Sprite::create("TitleMenu/SoundBar1_2.png");
	OptionBar2->setPosition(Position_51_47_.x + 60, Position_51_47_.y + 15);
	this->addChild(OptionBar2);

	OptionBar3 = Sprite::create("TitleMenu/SoundBar1_3.png");
	OptionBar3->setPosition(Position_51_47_.x + 60, Position_51_47_.y + -10);
	this->addChild(OptionBar3);

	OptionPointer = Sprite::create("TitleMenu/OptionPointer.png");
	OptionPointer->setPosition(Position_51_47_.x + 60, Position_51_47_.y + -10);
	this->addChild(OptionPointer);





	// 스케쥴 실행
	this->schedule(schedule_selector(MainMenu::tick));

	// Bgm 재생
	SMI->PlayMainMenuBgm();

	// 키보드 생성 
	KCI->CreateKeyListener(this);

	// 카메라 생성
	CI->CreateCamera(this);

	// 오버레이
	menuOverlay1 = Sprite::create("TitleMenu/menuoverlay.png");
	menuOverlay1->setPosition(DI->getWinSize().width / 2, DI->getWinSize().height / 2);
	this->addChild(menuOverlay1);
	menuOverlay2 = Sprite::create("TitleMenu/menushadow.png");
	menuOverlay2->setPosition(0, 0);
	menuOverlay2->setAnchorPoint({ 0,0 });
	this->addChild(menuOverlay2);

	return true;
}

void MainMenu::tick(float delta)
{
	// ------- 사운드를 실시간으로 조정  ------- //
	SMI->RunnigBgmVolume();
	SMI->RunnigSfxVolume();


	// ------- MainMenu Screen  ------- //

	if (Player->getMainMenuIndex() == 1)
		KCI->MainMenuPointerControl(mainMenuPointer, mainMenuText1);
	if (Player->getMainMenuIndex() == 2)
		KCI->MainMenuPointerControl(mainMenuPointer, mainMenuText2);
	if (Player->getMainMenuIndex() == 3)
		KCI->MainMenuPointerControl(mainMenuPointer, mainMenuText3);
	if (Player->getMainMenuIndex() == 4)
		KCI->MainMenuPointerControl(mainMenuPointer, mainMenuText4);
	if (Player->getMainMenuIndex() == 5)
		KCI->MainMenuPointerControl(mainMenuPointer, mainMenuText5);



	// ------- Character Select Screen  ------- //

	for (int i = 0; i < 10; ++i)
	{
		Characters[i]->setLocalZOrder(Characters[i]->getPositionY() * -1);
		KCI->CharSelectSetPos(Characters);
	}

	if (Player->getCharSelectIndex() == 0)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_03.png");
		CharInfo->setTexture("TitleMenu/characterInfo_1.png");
	}
	if (Player->getCharSelectIndex() == 1)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_07.png");
		CharInfo->setTexture("TitleMenu/characterInfo2.png");
	}
	if (Player->getCharSelectIndex() == 2)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_05.png");
		CharInfo->setTexture("TitleMenu/characterInfo3.png");
	}
	if (Player->getCharSelectIndex() == 3)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_09.png");
		CharInfo->setTexture("TitleMenu/characterInfo5.png");
	}
	if (Player->getCharSelectIndex() == 4)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_11.png");
		CharInfo->setTexture("TitleMenu/characterInfo4.png");
	}
	if (Player->getCharSelectIndex() == 5)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_15.png");
		CharInfo->setTexture("TitleMenu/characterInfo6.png");
	}
	if (Player->getCharSelectIndex() == 6)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_06.png");
		CharInfo->setTexture("TitleMenu/characterInfo7.png");
	}
	if (Player->getCharSelectIndex() == 7)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_04.png");
		CharInfo->setTexture("TitleMenu/characterInfo8.png");
	}
	if (Player->getCharSelectIndex() == 8)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_08.png");
		CharInfo->setTexture("TitleMenu/characterInfo5.png");
	}
	if (Player->getCharSelectIndex() == 9)
	{
		CharNameText->setTexture("TitleMenu/charactermenuText_13.png");
		CharInfo->setTexture("");
	}

	if (Player->getDifficultySelectIndex() == 0)
	{
		KCI->DifficultSelectPointerControl(CharDifficultyPointer, CharDifficultyNormal);
		CharDifficultyNormal->setOpacity(255);
	}
	else
	{
		CharDifficultyNormal->setOpacity(100);
	}
	if (Player->getDifficultySelectIndex() == 1)
	{
		KCI->DifficultSelectPointerControl(CharDifficultyPointer, CharDifficultyHard);
		CharDifficultyHard->setOpacity(255);
		CharDifficultyIcon->setOpacity(255);
	}
	else
	{
		CharDifficultyHard->setOpacity(100);
		CharDifficultyIcon->setOpacity(100);
	}

	KCI->DifficultBloodSetFade(CharDifficultyHardBlood);




	// ------- Option Screen  ------- //

	// -[Sfx Volume Set]- // 
	if (Player->getOptionSfxIndex() == 0)
		OptionBar1->setTexture("TitleMenu/SoundBar1_0.png");
	if (Player->getOptionSfxIndex() == 1)
		OptionBar1->setTexture("TitleMenu/SoundBar1_1.png");
	if (Player->getOptionSfxIndex() == 2)
		OptionBar1->setTexture("TitleMenu/SoundBar1_2.png");
	if (Player->getOptionSfxIndex() == 3)
		OptionBar1->setTexture("TitleMenu/SoundBar1_3.png");
	if (Player->getOptionSfxIndex() == 4)
		OptionBar1->setTexture("TitleMenu/SoundBar1_4.png");
	if (Player->getOptionSfxIndex() == 5)
		OptionBar1->setTexture("TitleMenu/SoundBar1_5.png");
	if (Player->getOptionSfxIndex() == 6)
		OptionBar1->setTexture("TitleMenu/SoundBar1_6.png");
	if (Player->getOptionSfxIndex() == 7)
		OptionBar1->setTexture("TitleMenu/SoundBar1_7.png");
	if (Player->getOptionSfxIndex() == 8)
		OptionBar1->setTexture("TitleMenu/SoundBar1_8.png");
	if (Player->getOptionSfxIndex() == 9)
		OptionBar1->setTexture("TitleMenu/SoundBar1_9.png");
	if (Player->getOptionSfxIndex() == 10)
		OptionBar1->setTexture("TitleMenu/SoundBar1_10.png");


	// -[Bgm Volume Set]- // 
	if (Player->getOptionBgmIndex() == 0)
		OptionBar2->setTexture("TitleMenu/SoundBar1_0.png");
	if (Player->getOptionBgmIndex() == 1)
		OptionBar2->setTexture("TitleMenu/SoundBar1_1.png");
	if (Player->getOptionBgmIndex() == 2)
		OptionBar2->setTexture("TitleMenu/SoundBar1_2.png");
	if (Player->getOptionBgmIndex() == 3)
		OptionBar2->setTexture("TitleMenu/SoundBar1_3.png");
	if (Player->getOptionBgmIndex() == 4)
		OptionBar2->setTexture("TitleMenu/SoundBar1_4.png");
	if (Player->getOptionBgmIndex() == 5)
		OptionBar2->setTexture("TitleMenu/SoundBar1_5.png");
	if (Player->getOptionBgmIndex() == 6)
		OptionBar2->setTexture("TitleMenu/SoundBar1_6.png");
	if (Player->getOptionBgmIndex() == 7)
		OptionBar2->setTexture("TitleMenu/SoundBar1_7.png");
	if (Player->getOptionBgmIndex() == 8)
		OptionBar2->setTexture("TitleMenu/SoundBar1_8.png");
	if (Player->getOptionBgmIndex() == 9)
		OptionBar2->setTexture("TitleMenu/SoundBar1_9.png");
	if (Player->getOptionBgmIndex() == 10)
		OptionBar2->setTexture("TitleMenu/SoundBar1_10.png");


	// -[Pointer Control]- // 
	if (Player->getOptionIndex() == 0)
		KCI->OptionPointerControl(OptionPointer, OptionSFX);
	if (Player->getOptionIndex() == 1)
		KCI->OptionPointerControl(OptionPointer, OptionMusic);
	if (Player->getOptionIndex() == 2)
		KCI->OptionPointerControl(OptionPointer, OptionMapOpacity);
	if (Player->getOptionIndex() == 3)
		KCI->OptionPointerControl(OptionPointer, OptionFullScreen);
	if (Player->getOptionIndex() == 4)
		KCI->OptionPointerControl(OptionPointer, OptionFilter);

	if (Player->getSceneChange())
	{
		SMI->StopMainMenuBgm();
		Player->setSceneChange(false);
		auto scene = LodingScreen1::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
	}
}
