#pragma once
#include <SFML/Graphics.hpp>

class DrawableObject {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~DrawableObject() = default;
};