#ifndef SCREENENGINE_
#define SCREENENGINE_

#include <vector>
#include "..\Helper\Singleton.h"
#include "..\Screen\Screen.h"

class ScreenEngine : public Singleton <ScreenEngine>
{
	friend class Singleton<ScreenEngine>;
public:
	virtual ~ScreenEngine(void);

	virtual bool Initialize();

    void Push(Screen* _pScene);
    void Pop();
    void PopAll();

    bool Update();
    void Render();

private:
	ScreenEngine();

    std::vector<Screen*>	m_GameStack;
    std::vector<Screen*>	m_PushStack;
    bool	m_bStatusChange;
    int		m_nPopCount;

};

#endif