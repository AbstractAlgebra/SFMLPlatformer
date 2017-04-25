
#include "Window.hpp"

Window::Window()
{
	setup("Window", sf::Vector2u(640, 480));

}
Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
	setup(l_title, l_size);
}

Window::~Window()
{
	destroy();
}
sf::RenderWindow& Window::getRenderWindow()
{
	return m_window;
}
EventManager* Window::getEventManager()
{
	return &m_eventManager;
}
void Window::close(EventDetails* l_event) 
{ 
	m_isDone = true; 
}

void Window::setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_isFocused = true; // Default value for focused flag.
	m_eventManager.addCallback("Fullscreen_toggle",
		&Window::toggleFullscreen, this);
	m_eventManager.addCallback("Window_close",
		&Window::close, this);
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	create();
}

void Window::create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}


void Window::destroy()
{
	m_window.close();
}

void Window::update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::LostFocus) {
			m_isFocused = false;
			m_eventManager.setFocus(false);
		}
		else if (event.type == sf::Event::GainedFocus) {
			m_isFocused = true;
			m_eventManager.setFocus(true);
		}
		m_eventManager.handleEvent(event);
	}
	m_eventManager.update();
}

void Window::toggleFullscreen(EventDetails* l_event)
{
	m_isFullscreen = !m_isFullscreen;
	destroy();
	create();
}

void Window::beginDraw()
{
	m_window.clear(sf::Color::Black);
}

void Window::endDraw()
{
	m_window.display();
}

void Window::draw(sf::Drawable& l_drawable)
{
	m_window.draw(l_drawable);
}

sf::Vector2u Window::getWindowSize()
{
	return m_windowSize;
}

bool Window::isDone()
{
	return m_isDone;
}