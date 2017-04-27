#ifndef BASESTATEHPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Window.hpp"
#include "EventManager.hpp"
enum class StateType {
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext {
	SharedContext() :m_wind(nullptr), m_eventManager(nullptr) {}
	Window* m_wind;
	EventManager* m_eventManager;
};

using TypeContainer = std::vector<StateType>;
using StateContainer = std::vector<std::pair<StateType, BaseState*>>;

using StateFactory = std::unordered_map<StateType, std::function<BaseState* (void)>>;
class StateManager;
class BaseState {
	friend class StateManager;
public:
	BaseState(StateManager* l_stateManager)
		:m_stateMgr(l_stateManager), m_transparent(false),
		m_transcendent(false) {}
	virtual ~BaseState() {}
	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;
	virtual void activate() = 0;
	virtual void deactivate() = 0;
	virtual void update(const sf::Time& l_time) = 0;
	virtual void draw() = 0;
	void setTransparent(const bool& l_transparent) {
		m_transparent = l_transparent;
	}
	bool isTransparent()const { return m_transparent; }
	void setTranscendent(const bool& l_transcendence) {
		m_transcendent = l_transcendence;
	}
	bool isTranscendent()const { return m_transcendent; }
	StateManager* getStateManager() { return m_stateMgr; }
protected:
	StateManager* m_stateMgr;
	bool m_transparent;
	bool m_transcendent;
};
#endif