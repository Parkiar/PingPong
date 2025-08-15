#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "DrawClass.h"

class Puck : public DrawableObject {
protected:
    std::string name;
    sf::CircleShape shape;
    sf::Vector2f velocity; // pixels/second
public:
    Puck();

    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window) override;
    void setColor(const sf::Color& color);
    void update(float deltaTime, const sf::Vector2u& windowSize);

    sf::Vector2f getPosition() const;
    float getRadius() const;
    sf::FloatRect getPositionRect() const;
    void bounceHorizontal();
};