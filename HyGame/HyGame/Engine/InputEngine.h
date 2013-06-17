#ifndef INPUTENGINE_
#define INPUTENGINE_


#include "..\Helper\Singleton.h"
#include "GameEngine.h"

typedef enum _KeyState
{
    Key_Down,
    Key_Up,
    Key_Fail,
}KeyState;

class InputEngine : public Singleton<InputEngine>
{
	friend class Singleton<InputEngine>;

public:
	InputEngine();
	virtual ~InputEngine();

	bool Initialize() { return false; }

public:

    KeyState IsKey(int nKey);

    KeyState IsKey(int nFirstKey, int nSecondKey);

    void Update();

private:

	GameEngine* m_pGameEngine;
};


#endif