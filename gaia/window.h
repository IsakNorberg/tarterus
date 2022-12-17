#pragma once
#include <string_view>
#include <algorithm>

#include "SFML/Graphics.hpp"
#include "draw_city.h"
#include "draw_path.h"
#include "render_buffer.h"

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
	render_buffer m_renderBuffer;
public:

	window();
	bool isOpen() noexcept;
	bool pollEvents() noexcept;
	bool isEventType(EventType event) noexcept;
	bool isKeyDown(Key key) noexcept;
	bool isMuseKeyDown(Button button) noexcept;
	void renderTheBuffer() noexcept;
	void clearBuffer() noexcept;
	void addToRenderBuffer(draw_city city);
	void addToRenderBuffer(std::vector<draw_path> paths);
	sf::Vector2f getMusePosition();
	~window();
};

