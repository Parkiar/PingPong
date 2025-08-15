#pragma once
#include "Paddles.h"
#include "Puck.h"

class Enemy : public Paddle {
public:
    Enemy(float xPos);
    void update(float dt, const sf::Vector2u& windowSize, Puck& puck);
};


