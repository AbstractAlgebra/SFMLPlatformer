#include "Game.hpp"
#include "Window.hpp"
#include "Textbox.hpp"

Game::Game()
	:m_window("Snake", sf::Vector2u(800, 600)),
	m_snake(m_world.GetBlockSize()),
	m_textbox(),
	m_world(sf::Vector2u(800, 600))
{
	m_textbox.setup(5, 14, 350, sf::Vector2f(225, 0));
	m_textbox.add("Seeded random number generator with: " + std::to_string(time(NULL)));
}
Game::~Game()
{
}

void Game::update()
{
	m_window.update();
	float timestep = 1.0f / m_snake.getSpeed();
	if (m_elapsed.asSeconds() >= timestep) {
		m_snake.tick();
		m_world.update(m_snake);
		m_elapsed -= sf::seconds(timestep);
		if (m_snake.hasLost()) {
			m_snake.reset();
		}
	}
}

void Game::moveSmile()
{
	float fElapsed = m_elapsed.asMicroseconds();
	sf::Vector2u l_windSize = m_window.getWindowSize();
	sf::Vector2u l_texSize = m_smileTexture.getSize();

	if ((m_smile.getPosition().x > l_windSize.x - l_texSize.x && m_increment.x > 0) || (m_smile.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}
	if ((m_smile.getPosition().y > l_windSize.x - l_texSize.x && m_increment.y > 0) || (m_smile.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}
	m_smile.setPosition(m_smile.getPosition().x + m_increment.x * fElapsed, m_smile.getPosition().y + m_increment.y * fElapsed);
}

void Game::render()
{
	m_window.beginDraw();

	m_world.render(m_window.getRenderWindow());
	m_snake.render(m_window.getRenderWindow());
	m_textbox.render(m_window.getRenderWindow());

	m_window.endDraw();
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
	return &m_window;
}

void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& m_snake.getDirection() != Direction::Down)
	{
		m_snake.setDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& m_snake.getDirection() != Direction::Up)
	{
		m_snake.setDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& m_snake.getDirection() != Direction::Right)
	{
		m_snake.setDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& m_snake.getDirection() != Direction::Left)
	{
		m_snake.setDirection(Direction::Right);
	}
}