#pragma once

// include library
#include <string>
#include <map>
#include <cmath>
#include "cocos2d.h"
#include "ui/UIEditBox/UIEditBox.h"
#include "ui/CocosGUI.h"
#include "cocos2d/extensions/cocos-ext.h" // for tableView
#include "LabelTypingEffect.h"
#include "tinyxml2/tinyxml2.h" // for xml import
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/prettywriter.h"
#include "network/HttpClient.h"
#include "AudioEngine.h"

// include Class
#include "MainCamera.h"
#include "DebugCall.h"
#include "SoundManager.h"
#include "KeyBordControl.h"
#include "Isaac.h"
#include "RandomGeneration.h"

// Difinision
#define DI Director::getInstance() // Director Instance
#define CI MainCamera::getInstance() // Camera Instance
#define DCI DebugCall::getInstance() // Debug Call Instance
#define SMI SoundManager::getInstance() // Sound Manager Instance
#define KCI KeyBordControl::getInstance() // Keybord Control Instance
#define Player Isaac::getInstance() // Isaac Instance
#define RGI RandomGeneration::getInstance() // RandomGeneration Instance

#define Position_50_50_ Vec2(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2) // Press Start Screen
#define Position_50_49_ Vec2(Director::getInstance()->getWinSize().width / 2, (Director::getInstance()->getWinSize().height / 2) * -1) // File Select Screen
#define Position_50_48_ Vec2(Director::getInstance()->getWinSize().width / 2, (Director::getInstance()->getWinSize().height / 2) * -3) // Main Menu Screen
#define Position_51_48_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, (Director::getInstance()->getWinSize().height / 2) * -3) // Character Select Screen
#define Position_51_47_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, (Director::getInstance()->getWinSize().height / 2) * -5) // Option Screen
#define Position_51_49_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, (Director::getInstance()->getWinSize().height / 2) * -1) // Stats Screen
#define Position_51_50_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, Director::getInstance()->getWinSize().height / 2)
#define Position_49_50_ Vec2((Director::getInstance()->getWinSize().width / 2) * -1, Director::getInstance()->getWinSize().height / 2)
#define Position_50_51_ Vec2(Director::getInstance()->getWinSize().width / 2, (Director::getInstance()->getWinSize().height / 2) * 3)
#define Position_48_50_ Vec2((Director::getInstance()->getWinSize().width / 2) * -3, Director::getInstance()->getWinSize().height / 2)
#define Position_50_52_ Vec2(Director::getInstance()->getWinSize().width / 2, (Director::getInstance()->getWinSize().height / 2) * 5)
#define Position_52_50_ Vec2((Director::getInstance()->getWinSize().width / 2) * 5, Director::getInstance()->getWinSize().height / 2)
#define Position_52_49_ Vec2((Director::getInstance()->getWinSize().width / 2) * 5, (Director::getInstance()->getWinSize().height / 2) * -1)
#define Position_50_47_ Vec2(Director::getInstance()->getWinSize().width / 2, (Director::getInstance()->getWinSize().height / 2) * -5)
#define Position_49_48_ Vec2((Director::getInstance()->getWinSize().width / 2) * -1, (Director::getInstance()->getWinSize().height / 2) * -3)
#define Position_49_47_ Vec2((Director::getInstance()->getWinSize().width / 2) * -1, (Director::getInstance()->getWinSize().height / 2) * -5)
#define Position_50_46_ Vec2((Director::getInstance()->getWinSize().width / 2), (Director::getInstance()->getWinSize().height / 2) * -7)
#define Position_49_51_ Vec2((Director::getInstance()->getWinSize().width / 2) * -1, (Director::getInstance()->getWinSize().height / 2) * 3)
#define Position_51_51_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, (Director::getInstance()->getWinSize().height / 2) * 3)
#define Position_51_52_ Vec2((Director::getInstance()->getWinSize().width / 2) * 3, (Director::getInstance()->getWinSize().height / 2) * 5)
#define Position_53_50_ Vec2((Director::getInstance()->getWinSize().width / 2) * 7, Director::getInstance()->getWinSize().height / 2)
#define Position_53_51_ Vec2((Director::getInstance()->getWinSize().width / 2) * 7, (Director::getInstance()->getWinSize().height / 2) * 3)

#define BackGroundZoder -100000
#define DoorZoder -90000
#define StageOverlayZoder 5000
#define MiniMapZoder 7000
#define DeathScrennZoder 9000

#define DoorCorrectionRL 200
#define DoorCorrectionUD 111

// using namespace
USING_NS_CC; // for cocos2d
USING_NS_CC_EXT; // the same using namespace extension
using namespace std; // for std
using namespace ui; // for ui
using namespace tinyxml2; // for xml import
using namespace cocos2d::network;
using namespace experimental;
// using namespace extension; // for tableView

// is make you can print korean language on cocos2d
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif







