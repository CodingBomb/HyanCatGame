#include "ScreenEngine.h"

template<> ScreenEngine* Singleton<ScreenEngine>::m_pInst = NULL;

ScreenEngine::~ScreenEngine()
{
	while (m_GameStack.size() != 0)
	{
		delete m_GameStack.back();
		m_GameStack.pop_back();
	}

	while (m_PushStack.size() != 0)
	{
		delete m_PushStack.back();
		m_PushStack.pop_back();
	}
}

ScreenEngine::ScreenEngine()
{
	m_bStatusChange = false;
	m_nPopCount     = 0;
}

bool ScreenEngine::Initialize()
{
	return true;
}

void ScreenEngine::Push( Screen* pScene )
{
	m_PushStack.push_back(pScene);
	m_bStatusChange = true;
}

void ScreenEngine::Pop()
{
	m_nPopCount++;
	if (!m_PushStack.empty())
	{
		m_PushStack.pop_back();
		m_nPopCount--;
	}
	if (m_nPopCount > (int)m_GameStack.size())
	{
		///> pop过多
		///assert(false);
	}
	m_bStatusChange = true;
}

void ScreenEngine::PopAll()
{
	m_nPopCount = m_GameStack.size();
	m_bStatusChange = true;
}

bool ScreenEngine::Update()
{
	if (m_bStatusChange == true)
	{
		///InputEngine_->Reset();
		while (m_nPopCount != 0)
		{
			if (m_GameStack.empty())
			{
				///> 不科学！
				///assert(false);
			}
			else
			{
				delete m_GameStack.back();
				m_GameStack.pop_back();
			}
			m_nPopCount--;
		}

		while (m_PushStack.size() != 0)
		{
			m_GameStack.push_back(m_PushStack.back());
			m_PushStack.pop_back();
		}

		if (m_GameStack.empty())
		{
			///> 没有场景了
			return true;
		}

		if (!m_GameStack.empty())
		{
			m_GameStack.back()->Reset();
		}

		m_bStatusChange = false;
	}
	if (!m_GameStack.empty())
	{
		m_GameStack.back()->Update();
	}
	return false;
}

void ScreenEngine::Render()
{
	if (!m_GameStack.empty())
	{
		m_GameStack.back()->Render();
	}
}
