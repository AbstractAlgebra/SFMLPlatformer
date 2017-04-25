#ifndef game_hpp
#define game_hpp
#include "Window.hpp"
#include "Textbox.hpp"
class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();
	Window* getWindow();

	sf::Time getElapsed();
	void restartClock();
	void moveSprite(EventDetails* l_details);
private:


	void moveSmile();
	Window* m_window;
	Textbox m_textbox;
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2i m_increment;
	sf::Clock m_clock;
	sf::Time m_elapsed;

};

#endif