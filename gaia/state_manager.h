#pragma once
#include <memory>
#include "window.h"
#include "cities.h"
#include "input.h"
#include "simulator.h"

class state_manager
{
	bool m_runPogram = true;
	std::shared_ptr<window> m_window;
	std::shared_ptr<gaia::cities> m_cities;
	void runSimulate();
	bool runInput();
public:
	state_manager();
	void runLoop();
};