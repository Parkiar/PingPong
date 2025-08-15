#include "Paddles.h"

Paddle::Paddle(float x) {
	shape.setSize(sf::Vector2f(20.0f, 100.0f));
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(shape.getSize() / 2.0f); //. Middle
	shape.setPosition(sf::Vector2f(x, 300.0f));
}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

sf::Vector2f Paddle::getPosition() const {
	return shape.getPosition();
}

sf::Vector2f Paddle::getSize() const {
	return shape.getSize();
}

sf::FloatRect Paddle::getGlobalBounds() const {
	return shape.getGlobalBounds();
}

// Move for player
void Paddle::move(float dt, const sf::Vector2u& windowSize, bool up) {
    float moveAmount = speed * dt;
    float currentY = shape.getPosition().y;

    if (up) {
        currentY -= moveAmount;
    }
    else {
        currentY += moveAmount;
    }

    // Clamp the paddle's position
    float halfHeight = shape.getSize().y / 2.0f;
    float clampedY = std::clamp(currentY, halfHeight, static_cast<float>(windowSize.y) - halfHeight);

    shape.setPosition(sf::Vector2f(shape.getPosition().x, clampedY));
}

void Paddle::setColor(const sf::Color& color) {
	shape.setFillColor(color);
}

void Paddle::setPosition(float x, float y) {
	shape.setPosition(sf::Vector2f(x, y));
}