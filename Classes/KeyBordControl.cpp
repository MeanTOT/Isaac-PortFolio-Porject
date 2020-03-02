#include "KeyBordControl.h"
#include "LodingScreen1.h"

KeyBordControl* KeyBordControl::instance = nullptr;

KeyBordControl::KeyBordControl()
{
	right = false;
	left = false;
	up = false;
	down = false;
}

KeyBordControl * KeyBordControl::getInstance()
{
	if (!instance)
		instance = new KeyBordControl;

	return instance;
}

void KeyBordControl::releaseInstance()
{
	if (instance)
		delete instance;
}

void KeyBordControl::onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_F1:
	{
		if (Player->getNowScene() == StageScreen)
		{
			if (DCI->getDebugActivation())
				DCI->setDebugActivation(false);
			else
				DCI->setDebugActivation(true);
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_F2:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setCoinCount(50);
			Player->setBombCount(50);
			Player->setKeyCount(50);
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_F3:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->showDebugInfo();
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_SPACE:
	{
		if (Player->getNowScene() == PressStartScene)
		{
			CI->MoveB();
			Player->setNowScene(FileSelectScene);
			return;
		}
		if (Player->getNowScene() == FileSelectScene)
		{
			CI->MoveB();
			Player->setNowScene(MainMenuScene);
			return;
		}
		if (Player->getNowScene() == MainMenuScene)
		{
			if (Player->getMainMenuIndex() == 1)
			{
				CI->MoveR();
				Player->setNowScene(CharSelectScene);
				return;
			}
			if (Player->getMainMenuIndex() == 2)
			{
				return;
			}
			if (Player->getMainMenuIndex() == 3)
			{
				return;
			}
			if (Player->getMainMenuIndex() == 4)
			{
				CI->MoveRT();
				Player->setNowScene(StatsScreen);
				return;
			}
			if (Player->getMainMenuIndex() == 5)
			{
				CI->MoveRB();
				Player->setNowScene(OptionScene);
				return;
			}
		}
		if (Player->getNowScene() == CharSelectScene)
		{
			if (Player->getCharSelectIndex() == 0)
			{
				Player->setNowScene(StageScreen);
				Player->setSceneChange(true);
				return;
			}
			else
			{
				SMI->PlayErrorBuzz();
				return;
			}
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_ESCAPE:
	{
		if (Player->getNowScene() == PressStartScene)
		{
			return;
		}
		if (Player->getNowScene() == FileSelectScene)
		{
			CI->MoveT();
			Player->setNowScene(PressStartScene);
			return;
		}
		if (Player->getNowScene() == MainMenuScene)
		{
			CI->MoveT();
			Player->setNowScene(FileSelectScene);
			return;
		}
		if (Player->getNowScene() == CharSelectScene)
		{
			CI->MoveL();
			Player->setNowScene(MainMenuScene);
			return;
		}
		if (Player->getNowScene() == OptionScene)
		{
			CI->MoveLT();
			Player->setNowScene(MainMenuScene);
			return;
		}
		if (Player->getNowScene() == StatsScreen)
		{
			CI->MoveLB();
			Player->setNowScene(MainMenuScene);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		if (Player->getNowScene() == MainMenuScene)
		{
			Player->setMainMenuIndex(Player->getMainMenuIndex() + 1);

			if (Player->getMainMenuIndex() == 6)
				Player->setMainMenuIndex(1);
			return;
		}
		if (Player->getNowScene() == CharSelectScene)
		{
			Player->setDifficultySelectIndex(Player->getDifficultySelectIndex() - 1);

			if (Player->getDifficultySelectIndex() == -1)
				Player->setDifficultySelectIndex(1);

			down = true;
			return;
		}
		if (Player->getNowScene() == OptionScene)
		{
			Player->setOptionIndex(Player->getOptionIndex() + 1);

			if (Player->getOptionIndex() == 5)
				Player->setOptionIndex(0);
			return;
		}
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireD(true);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		if (Player->getNowScene() == MainMenuScene)
		{
			Player->setMainMenuIndex(Player->getMainMenuIndex() - 1);

			if (Player->getMainMenuIndex() == 0)
				Player->setMainMenuIndex(5);
			return;
		}
		if (Player->getNowScene() == CharSelectScene)
		{
			Player->setDifficultySelectIndex(Player->getDifficultySelectIndex() + 1);

			if (Player->getDifficultySelectIndex() == 2)
				Player->setDifficultySelectIndex(0);

			up = true;

			return;
		}
		if (Player->getNowScene() == OptionScene)
		{
			Player->setOptionIndex(Player->getOptionIndex() - 1);

			if (Player->getOptionIndex() == -1)
				Player->setOptionIndex(4);
			return;
		}
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireU(true);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		if (Player->getNowScene() == CharSelectScene)
		{
			right = true;

			Player->setCharSelectIndex(Player->getCharSelectIndex() + 1);

			if (Player->getCharSelectIndex() == 10)
				Player->setCharSelectIndex(0);

			SMI->PlayCharSelectRight();

			return;
		}
		if (Player->getNowScene() == OptionScene)
		{
			if (Player->getOptionIndex() == 0)
			{
				SMI->setSfxVolume(SMI->getSfxVolume() + 0.1f);

				if (SMI->getSfxVolume() > 1.f)
					SMI->setSfxVolume(1.f);

				Player->setOptionSfxIndex(Player->getOptionSfxIndex() + 1);

				if (Player->getOptionSfxIndex() == 11)
					Player->setOptionSfxIndex(10);

				SMI->PlayTearFire5();
			}
			if (Player->getOptionIndex() == 1)
			{
				SMI->setBgmVolume(SMI->getBgmVolume() + 0.1f);

				if (SMI->getBgmVolume() > 1.f)
					SMI->setBgmVolume(1.f);

				Player->setOptionBgmIndex(Player->getOptionBgmIndex() + 1);

				if (Player->getOptionBgmIndex() == 11)
					Player->setOptionBgmIndex(10);
			}
		}
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireR(true);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		if (Player->getNowScene() == CharSelectScene)
		{
			left = true;

			Player->setCharSelectIndex(Player->getCharSelectIndex() - 1);

			if (Player->getCharSelectIndex() == -1)
				Player->setCharSelectIndex(9);

			SMI->PlayCharSelectLeft();

			return;
		}
		if (Player->getNowScene() == OptionScene)
		{
			if (Player->getOptionIndex() == 0)
			{
				SMI->setSfxVolume(SMI->getSfxVolume() - 0.1f);

				if (SMI->getSfxVolume() < 0.f)
					SMI->setSfxVolume(0.f);

				Player->setOptionSfxIndex(Player->getOptionSfxIndex() - 1);

				if (Player->getOptionSfxIndex() == -1)
					Player->setOptionSfxIndex(0);

				SMI->PlayTearFire5();
			}
			if (Player->getOptionIndex() == 1)
			{
				SMI->setBgmVolume(SMI->getBgmVolume() - 0.1f);

				if (SMI->getBgmVolume() < 0.f)
					SMI->setBgmVolume(0.f);

				Player->setOptionBgmIndex(Player->getOptionBgmIndex() - 1);

				if (Player->getOptionBgmIndex() == -1)
					Player->setOptionBgmIndex(0);
			}
		}
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireL(true);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_A:
	{
		if (Player->getNowScene() == StageScreen)
		{
			if (!Player->getIsIsaacGetItem())
				Player->getIsaacBody()->stopAllActions();
			Player->setMoveL(true);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_D:
	{
		if (Player->getNowScene() == StageScreen)
		{
			if (!Player->getIsIsaacGetItem())
				Player->getIsaacBody()->stopAllActions();
			Player->setMoveR(true);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_W:
	{
		if (Player->getNowScene() == StageScreen)
		{
			if (!Player->getIsIsaacGetItem())
				Player->getIsaacBody()->stopAllActions();
			Player->setMoveU(true);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_S:
	{
		if (Player->getNowScene() == StageScreen)
		{
			if (!Player->getIsIsaacGetItem())
				Player->getIsaacBody()->stopAllActions();
			Player->setMoveD(true);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_E:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->CreateBomb();
			return;
		}
	}
	break;
	default:
		break;
	}
	
}

void KeyBordControl::onKeyReleased(EventKeyboard::KeyCode keyCode, Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireD(false);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireU(false);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireR(false);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setBulletFireL(false);

			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_A:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setMoveL(false);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_D:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setMoveR(false);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_W:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setMoveU(false);
			return;
		}
	}
	break;
	case EventKeyboard::KeyCode::KEY_S:
	{
		if (Player->getNowScene() == StageScreen)
		{
			Player->setMoveD(false);
			return;
		}
	}
	break;
	default:
		break;
	}
}

void KeyBordControl::CreateKeyListener(Scene * scene)
{
	_scene = scene;

	keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(KeyBordControl::onKeyPressed, this);
	keyListener->onKeyReleased = CC_CALLBACK_2(KeyBordControl::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, _scene);
}

void KeyBordControl::MainMenuPointerControl(Sprite * sprite1, Sprite* sprite2)
{
	sprite1->setPosition(sprite2->getPosition().x - 70, sprite2->getPosition().y - 10);
}

void KeyBordControl::CharSelectSetPos(Sprite * sprite[])
{
	auto ActionSpeed = 0.1f;

	if (left)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (i == 9)
			{
				sprite[i]->runAction(Spawn::create(MoveTo::create(ActionSpeed, sprite[0]->getPosition()), ScaleTo::create(ActionSpeed, sprite[0]->getScale()), nullptr));
			}
			else
			{
				sprite[i]->runAction(Spawn::create(MoveTo::create(ActionSpeed, sprite[i + 1]->getPosition()), ScaleTo::create(ActionSpeed, sprite[i + 1]->getScale()), nullptr));
			}

			if (i == Player->getCharSelectIndex())
				sprite[i]->setOpacity(255);
			else 
				sprite[i]->setOpacity(150);
		}

		left = false;
	}

	if (right)
	{
		for (int i = 9; i >= 0; --i)
		{
			if (i == 0)
			{
				sprite[i]->runAction(Spawn::create(MoveTo::create(ActionSpeed, sprite[9]->getPosition()), ScaleTo::create(ActionSpeed, sprite[9]->getScale()), nullptr));
			}
			else
			{
				sprite[i]->runAction(Spawn::create(MoveTo::create(ActionSpeed, sprite[i - 1]->getPosition()), ScaleTo::create(ActionSpeed, sprite[i - 1]->getScale()), nullptr));
			}

			if (i == Player->getCharSelectIndex())
				sprite[i]->setOpacity(255);
			else
				sprite[i]->setOpacity(150);
		}

		right = false;
	}
}

void KeyBordControl::DifficultSelectPointerControl(Sprite * sprite1, Sprite * sprite2)
{
	sprite1->setPosition(sprite2->getBoundingBox().getMinX() - 3 , sprite2->getBoundingBox().getMidY() + 6);
}

void KeyBordControl::DifficultBloodSetFade(Sprite * sprite)
{
	if (up || down)
	{
		if (Player->getDifficultySelectIndex() == 0)
			sprite->runAction(FadeOut::create(0.3f));
		if (Player->getDifficultySelectIndex() == 1)
			sprite->runAction(FadeIn::create(0.3f));

		up = false;
		down = false;
	}
	
}

void KeyBordControl::OptionPointerControl(Sprite * sprite1, Sprite * sprite2)
{
	sprite1->setPosition(sprite2->getBoundingBox().getMinX() - 3, sprite2->getBoundingBox().getMidY());
}

void KeyBordControl::CreateContactListener(Scene * scene)
{
	contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(KeyBordControl::onContactBegin, this);
	contactListener->onContactPostSolve = CC_CALLBACK_2(KeyBordControl::onContactPostSolve, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, scene);
}


// Pysics Body 충돌 처리
bool KeyBordControl::onContactBegin(PhysicsContact & contact)
{
	// CollisionBitMask
	// 1, 아이작 바디
	// 2. 오브젝트
	// 3. 몬스터 바디 (공중유닛)
	// 4. 몬스터 바디 (지상유닛)
	// 5, 아이작총알 , 그림자
	// 6. 아이작 폭탄
	// 7. 폭팔범위
	// 8. 데미지입는 오브젝트[불,가시]
	// 9. 몬스터 총알
	// 10 . 벽
	// 11 . 드랍아이템
	// 12 . 패시브아이템
	// 13 . 몬스터 높은 총알
	// 14 . Pit [구덩이]
	// 15 . 두번째 벽

	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();

	// --------------------------------------------- [아이작 바디] --------------------------------------------- //

	// 아이작과 아이작총알,그림자 충돌
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	// 아이작과 폭팔 충돌
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 7)
	{
		Player->setIsaacInfo(IsaacTakeDamage);
	}

	// 아이작과 드랍 아이템
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 11 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 11)
	{
		if (b->getCollisionBitmask() == 11)
			b->getNode()->setTag(ItemErase);
		if (a->getCollisionBitmask() == 11)
			a->getNode()->setTag(ItemErase);
	}

	// 아이작과 패시브 아이템
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 12 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 12)
	{
		if (b->getCollisionBitmask() == 12)
			b->getNode()->setTag(ItemErase);
		if (a->getCollisionBitmask() == 12)
			a->getNode()->setTag(ItemErase);
	}

	// 아이작과 불,가시 등등 과 충돌
	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 8 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 8)
	{
		Player->setIsaacInfo(IsaacTakeDamage);
	}

	// --------------------------------------------- [아이작 총알] --------------------------------------------- //

	// 아이작 총알끼리 충돌
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	// 아이작 총알과 두번째 벽 충돌
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 15 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 15)
	{
		return false;
	}

	// 아이작 총알과 오브젝트 충돌
	if (a->getCollisionBitmask() == 8 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 8 && a->getCollisionBitmask() == 5)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);

		if (b->getCollisionBitmask() == 8)
			b->getNode()->setTag(ObjectHit);
		if (a->getCollisionBitmask() == 8)
			a->getNode()->setTag(ObjectHit);
	}

	// 아이작 총알과 오브젝트 충돌
	if (a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 2 && a->getCollisionBitmask() == 5)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);

		if (b->getCollisionBitmask() == 2)
			b->getNode()->setTag(ObjectHit);
		if (a->getCollisionBitmask() == 2)
			a->getNode()->setTag(ObjectHit);
	}

	//아이작 총알과 벽 충돌
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 10 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 10)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 아이작 총알과 폭탄 충돌 
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 6 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 6)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 아이작총알과 드랍아이템
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 11 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 11)
	{
		return false;
	}

	// 아이작총알과 구덩이
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 14 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 14)
	{
		return false;
	}

	// 아이작총알과 액티브아이템
	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 12 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 12)
	{
		return false;
	}


	// --------------------------------------------- [몬스터 바디] --------------------------------------------- //

	// 몬스터와 두번째벽 충돌
	if (a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 15 ||
		b->getCollisionBitmask() == 3 && a->getCollisionBitmask() == 15)
	{
		return false;
	}

	// 몬스터와 두번째벽 충돌
	if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 15 ||
		b->getCollisionBitmask() == 4 && a->getCollisionBitmask() == 15)
	{
		return false;
	}

	// 몬스터(공중)와 오브젝트 충돌
	if (a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 2 ||
		b->getCollisionBitmask() == 3 && a->getCollisionBitmask() == 2)
	{
		return false;
	}

	// 몬스터와 아이작총알 충돌
	if (a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 3 && a->getCollisionBitmask() == 5)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);

		if (b->getCollisionBitmask() == 3)
			b->getNode()->setTag(MonsterColiisionBullet);
		if (a->getCollisionBitmask() == 3)
			a->getNode()->setTag(MonsterColiisionBullet);
	}


	// 몬스터와 아이작총알 충돌
	if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 4 && a->getCollisionBitmask() == 5)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);

		if (b->getCollisionBitmask() == 4)
			b->getNode()->setTag(MonsterColiisionBullet);
		if (a->getCollisionBitmask() == 4)
			a->getNode()->setTag(MonsterColiisionBullet);
	}

	// 몬스터와 폭팔 충돌
	if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 4 && a->getCollisionBitmask() == 7)
	{
		if (b->getCollisionBitmask() == 4)
			b->getNode()->setTag(MonsterColiisionExplosion);
		if (a->getCollisionBitmask() == 4)
			a->getNode()->setTag(MonsterColiisionExplosion);
	}

	// 몬스터와 폭팔 충돌
	if (a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 3 && a->getCollisionBitmask() == 7)
	{
		if (b->getCollisionBitmask() == 3)
			b->getNode()->setTag(MonsterColiisionExplosion);
		if (a->getCollisionBitmask() == 3)
			a->getNode()->setTag(MonsterColiisionExplosion);
	}

	// 몬스터와 아이작 충돌
	if (a->getCollisionBitmask() == 3 && b->getCollisionBitmask() == 1 ||
		b->getCollisionBitmask() == 3 && a->getCollisionBitmask() == 1)
		Player->setIsaacInfo(IsaacTakeDamage);

	// 몬스터와 아이작 충돌
	if (a->getCollisionBitmask() == 4 && b->getCollisionBitmask() == 1 ||
		b->getCollisionBitmask() == 4 && a->getCollisionBitmask() == 1)
		Player->setIsaacInfo(IsaacTakeDamage);


	// --------------------------------------------- [몬스터 총알] --------------------------------------------- //

	// 몬스터 총알과 내벽 충돌
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 15 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 15)
	{
		return false;
	}

	// 몬스터 총알과 구덩이 충돌
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 14 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 14)
	{
		return false;
	}

	// 몬스터 높은총알과 내벽 충돌
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 15 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 15)
	{
		return false;
	}

	// 몬스터 총알과 몬스터바디
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 4 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 4)
	{
		return false;
	}

	// 몬스터 높은총알과 몬스터 바디
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 4 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 4)
	{
		return false;
	}

	// 몬스터 총알과 몬스터 바디
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 3 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 3)
	{
		return false;
	}

	// 몬스터 높은총알과 몬스터 바디
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 3 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 3)
	{
		return false;
	}

	// 몬스터 총알과 몬스터 총알 
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 9 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 9)
	{
		return false;
	}

	// 몬스터 높은총알과 몬스터 높은총알
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 13 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 13)
	{
		return false;
	}

	// 몬스터 총알과 아이작 총알 
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	// 몬스터 높은총알과 아이작총알
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	// 몬스터 총알과 폭탄
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 6 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 6)
	{
		return false;
	}

	// 몬스터 높은총알과 폭탄
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 6 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 6)
	{
		return false;
	}

	// 몬스터 총알과 폭팔 
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 7)
	{
		return false;
	}

	// 몬스터 높은총알과 폭팔
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 7)
	{
		return false;
	}

	// 몬스터 높은총알과 내벽 충돌
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 2 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 2)
	{
		return false;
	}

	// 몬스터 총알과 오브젝트 충돌
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 2 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 2)
	{
		if (b->getCollisionBitmask() == 9)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 9)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 몬스터 총알과 외벽 충돌
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 10 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 10)
	{
		if (b->getCollisionBitmask() == 9)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 9)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 몬스터 총알과 외벽 충돌
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 10 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 10)
	{
		if (b->getCollisionBitmask() == 13)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 13)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 몬스터총알 과 아이작 충돌
	if (a->getCollisionBitmask() == 9 && b->getCollisionBitmask() == 1 ||
		b->getCollisionBitmask() == 9 && a->getCollisionBitmask() == 1)
	{
		Player->setIsaacInfo(IsaacTakeDamage);

		if (b->getCollisionBitmask() == 9)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 9)
			a->getNode()->setTag(EraseBulletTag);
	}

	// 몬스터총알 과 아이작 충돌
	if (a->getCollisionBitmask() == 13 && b->getCollisionBitmask() == 1 ||
		b->getCollisionBitmask() == 13 && a->getCollisionBitmask() == 1)
	{
		Player->setIsaacInfo(IsaacTakeDamage);

		if (b->getCollisionBitmask() == 13)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 13)
			a->getNode()->setTag(EraseBulletTag);
	}




	// 오브젝트와 폭팔 충돌
	if (a->getCollisionBitmask() == 2 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 2 && a->getCollisionBitmask() == 7)
	{
		if (b->getCollisionBitmask() == 2)
			b->getNode()->setTag(ObjectCollisionBomb);
		if (a->getCollisionBitmask() == 2)
			a->getNode()->setTag(ObjectCollisionBomb);
	}

	// 오브젝트와 폭팔 충돌
	if (a->getCollisionBitmask() == 8 && b->getCollisionBitmask() == 7 ||
		b->getCollisionBitmask() == 8 && a->getCollisionBitmask() == 7)
	{
		if (b->getCollisionBitmask() == 8)
			b->getNode()->setTag(ObjectCollisionBomb);
		if (a->getCollisionBitmask() == 8)
			a->getNode()->setTag(ObjectCollisionBomb);
	}
	

	return true;
}

void KeyBordControl::onContactPostSolve(PhysicsContact & contact, const PhysicsContactPostSolve & solve)
{
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();
}
 