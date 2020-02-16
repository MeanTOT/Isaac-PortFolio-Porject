#pragma once
#include "ProjectFW.h"

class KeyBordControl : public Scene
{
private:
	static KeyBordControl* instance;

	EventListenerKeyboard* keyListener;
	EventListenerPhysicsContact* contactListener;

	Scene* _scene;

	KeyBordControl();
	~KeyBordControl() {};
public:
	static KeyBordControl* getInstance();
	static void releaseInstance();

	bool right;
	bool left;
	bool up;
	bool down;

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	void CreateKeyListener(Scene* scene);
	void MainMenuPointerControl(Sprite* sprite1, Sprite* sprite2);
	void CharSelectSetPos(Sprite* sprite[]);
	void DifficultSelectPointerControl(Sprite* sprite1, Sprite* sprite2);
	void DifficultBloodSetFade(Sprite* sprite);
	void OptionPointerControl(Sprite* sprite1, Sprite* sprite2);
	void CreateContactListener(Scene* scene);
	bool onContactBegin(PhysicsContact& contact);
	void onContactPostSolve(PhysicsContact& contact, const PhysicsContactPostSolve& solve);

};

