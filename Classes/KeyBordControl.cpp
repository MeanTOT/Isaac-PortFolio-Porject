#include "KeyBordControl.h"

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
			Player->getIsaacBody()->stopAllActions();
			Player->setMoveD(true);
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
			sprite->runAction(FadeOut::create(0.3));
		if (Player->getDifficultySelectIndex() == 1)
			sprite->runAction(FadeIn::create(0.3));

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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, scene);
}

bool KeyBordControl::onContactBegin(PhysicsContact & contact)
{
	// CollisionBitMask
	// 1, 아이작 바디
	// 2. 오브젝트
	// 5, 아이작총알 , 그림자
	// 10 . 벽

	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();


	if (a->getCollisionBitmask() == 1 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 1 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 5 ||
		b->getCollisionBitmask() == 5 && a->getCollisionBitmask() == 5)
	{
		return false;
	}

	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 2 ||
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


	if (a->getCollisionBitmask() == 5 && b->getCollisionBitmask() == 10 ||
		b->getCollisionBitmask() == 10 && a->getCollisionBitmask() == 5)
	{
		if (b->getCollisionBitmask() == 5)
			b->getNode()->setTag(EraseBulletTag);
		if (a->getCollisionBitmask() == 5)
			a->getNode()->setTag(EraseBulletTag);
	}

	

	return true;
}
