#ifndef GAMECONTROLLER_
#define GAMECONTROLLER_

#include "..\Helper\Singleton.h"

class GameController : public Singleton <GameController>
{
	friend class Singleton<GameController>;

public:
	GameController(void);
	~GameController(void);

	virtual bool Initialize();
    void Start();
    bool Update();
    bool Render();
    void Exit();

};

#endif