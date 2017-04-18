#include "Game.hpp"
#include "Window.hpp"
#include "Textbox.hpp"
#include <iostream>
Game::Game()
	:m_window(new Window("Sprite Demo", sf::Vector2u(800, 600)))
{
}

Game::~Game()
{
}

void Game::update()
{
	m_window->update();

}

void Game::moveSprite(EventDetails* l_details)
{
	sf::Vector2i mousepos =
		m_window->getEventManager()->getMousePos(
			&m_window->getRenderWindow());
	m_sprite.setPosition(mousepos.x, mousepos.y);
	std::cout << "Moving sprite to: "
		<< mousepos.x << ":"
		<< mousepos.y << std::endl;
}

void Game::render()
{
	m_window->beginDraw();

	m_window->endDraw();
}

sf::Time Game::getElapsed()
{
	return m_elapsed;
}

void Game::restartClock()
{
	m_elapsed += m_clock.restart();
}

Window* Game::getWindow()
{
	return m_window;
}

void Game::handleInput()
{
}