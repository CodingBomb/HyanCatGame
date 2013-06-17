#include "InputEngine.h"

template<> InputEngine* Singleton<InputEngine>::m_pInst = NULL;

InputEngine::InputEngine()
{
	m_pGameEngine = GameEngine::Instance();
}

InputEngine::~InputEngine()
{
}

KeyState InputEngine::IsKey(int nKey)
{
	if (!m_pGameEngine)
    {
        return Key_Fail;
    }
    if (m_pGameEngine->Input_GetKeyState(nKey))
    {
        return Key_Down;
    }
    return Key_Up;
}

KeyState InputEngine::IsKey(int nFirstKey, int nSecondKey)
{
    if (!m_pGameEngine)
    {
        return Key_Fail;
    }
    if (m_pGameEngine->Input_GetKeyState(nFirstKey))
    {
        if (m_pGameEngine->Input_GetKeyState(nSecondKey))
        {
            return Key_Down;
        }
    }
    return Key_Up;
}


void InputEngine::Update()
{

}