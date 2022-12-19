#include "window.h"

window::window() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), TITLE.data()), m_event({})
{
	m_event = sf::Event(sf::Event::Count);
	m_window.setKeyRepeatEnabled(false);
}

bool window::isOpen() noexcept
{
	return m_window.isOpen();
}

bool window::pollEvents() noexcept
{
	return m_window.pollEvent(m_event);
}

bool window::isEventType(EventType event) noexcept
{
	return event == m_event.type;
}

bool window::isKeyDown(Key key) noexcept
{
	if (EventType::KeyPressed != m_event.type)
	{
		return false;
	}
	return m_event.key.code == key;
}

bool window::isMuseKeyDown(Button button) noexcept
{
	return m_event.mouseButton.button == button;
}

void window::renderTheBuffer() noexcept
{
	m_window.clear(CLEAR_COLOR);
	m_renderBuffer.renderBuffer(m_window);
	m_window.display();
}

void window::clearBuffer() noexcept
{
	m_renderBuffer.clear();
}

void window::addToRenderBuffer(draw_city city)
{
	m_renderBuffer.addToBuffer(city);
}
void window::addToRenderBuffer(std::vector<draw_path> paths)
{
	if (!m_renderBuffer.pathEmpty())
	{
		m_renderBuffer.clerPaths();
	}
	m_renderBuffer.addToBuffer(paths);
}

sf::Vector2f window::getMusePosition()
{
	sf::Vector2i musePosition = sf::Mouse::getPosition(m_window);
	return static_cast<sf::Vector2f>(musePosition);
}

window::~window()
{
	m_window.close();
}
