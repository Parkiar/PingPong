#include "Puck.h"
#include <algorithm>

Puck::Puck(){
    const float r = 10.0f;
    shape.setRadius(r);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(sf::Vector2f(r, r)); // center origin
    shape.setPosition(sf::Vector2f(400, 300)); // middle of window
    velocity = { 180.0f, 140.f }; // px/sec (tweak for speed)
}

void Puck::setPosition(float x, float y) {
    shape.setPosition(sf::Vector2f(x, y));
}

void Puck::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Puck::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}

void Puck::bounceHorizontal() {
    velocity.x = -velocity.x;
}

float Puck::getRadius() const {
    return shape.getRadius();
}

sf::Vector2f Puck::getPosition() const {
	return shape.getPosition();
}

sf::FloatRect Puck::getPositionRect() const {
    return shape.getGlobalBounds();
}

void Puck::update(float dt, const sf::Vector2u& windowSize) {
    shape.move(velocity * dt);

    const float r = shape.getRadius();
    const float left = r;
    const float right = static_cast<float>(windowSize.x) - r;
    const float top = r;
    const float bottom = static_cast<float>(windowSize.y) - r;

    sf::Vector2f p = shape.getPosition();

    // bounce x
    if (p.x < left) { p.x = left; velocity.x = std::abs(velocity.x); } // positive std::abs = go right
    if (p.x > right) { p.x = right; velocity.x = -std::abs(velocity.x); } // negative = left

    // bound y
    if (p.y < top) { p.y = top; velocity.y = std::abs(velocity.y); } // less = go up, positive = go down
    if (p.y > bottom) { p.y = bottom; velocity.y = -std::abs(velocity.y); } // go up

    shape.setPosition(p);
}