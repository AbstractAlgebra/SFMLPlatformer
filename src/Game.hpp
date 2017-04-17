#ifndef game_hpp
#define game_hpp
#include "Window.hpp"
#include "World.hpp"
#include "Snake.hpp"
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

private:

	World m_world;
	Snake m_snake;
	void moveSmile();
	Window m_window;
	Textbox m_textbox;
	sf::Texture m_smileTexture;
	sf::Sprite m_smile;
	sf::Vector2i m_increment;
	sf::Clock m_clock;
	sf::Time m_elapsed;

};

#endif