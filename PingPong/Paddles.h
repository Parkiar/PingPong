#pragma once
#include <SFML/Graphics.hpp>
#include "DrawClass.h"

class Paddle : public DrawableObject {
protected:
	sf::RectangleShape shape;
	float speed = 200.0f;
public:
	Paddle(float xPos);
	void draw(sf::RenderWindow& window) override;
	void move(float dt, const sf::Vector2u& windowSize, bool up);
	void setColor(const sf::Color& color);
	void setPosition(float x, float y);

	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	sf::FloatRect getGlobalBounds() const;

	float getSpeed() const { return speed; }
};