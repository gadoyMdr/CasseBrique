#pragma once

#include <SFML/Graphics.hpp>

static class Global {
public:
	static sf::RenderWindow window;
	static float deltaTime;
	static sf::Color themeColor;
	static sf::Color backGroundColor;
	static sf::Vector2f baseBriqueSize;
};