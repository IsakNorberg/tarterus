#pragma once
#include <string_view>
#include "SFML/Graphics.hpp"
#include "draw_city.h"
#include <algorithm>

constexpr int WINDOW_HIGHT = 540;
constexpr int WINDOW_WIDTH = 910;
constexpr std::string_view TITLE = "gaia";
const sf::Color CLEAR_COLOR = sf::Color::Black;

using EventType = sf::Event::EventType;
using Key = sf::Keyboard::Key;
using Button = sf::Mouse::Button;
class window
{
	sf::RenderWindow m_window;
	sf::Event m_event;
	std::vector<draw_city> m_renderBuffer;
public:
	window(const window& rhs) = default;
	window& operator=(const window& rhs) = default;
	window(window&& rhs) = default;
	window& operator=(window&& rhs) = default;
	window();
	bool isOpen() noexcept;
	bool pollEvents() noexcept;
	bool isEventType(EventType event) noexcept;
	bool isKeyDown(Key key) noexcept;
	bool isMuseKeyDown(Button button);
	void renderTheBuffer();
	void clearBuffer();
	void addToRenderBuffer(draw_city city);
	sf::Vector2f getMusePosition();
	~window();
};