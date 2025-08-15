#include "Enemy.h"
#include <algorithm> // for std::clamp

Enemy::Enemy(float xPos) : Paddle(xPos) {
    shape.setFillColor(sf::Color::Red);
}

void Enemy::update(float dt, const sf::Vector2u& windowSize, Puck& puck) {
    float speed = 200.0f; // pixels per second

    float paddleY = shape.getPosition().y;
    float puckY = puck.getPosition().y;

    // Move paddle toward puck's Y position (up/down only)
    if (puckY < paddleY) {
        paddleY -= speed * dt;
    }
    else if (puckY > paddleY) {
        paddleY += speed * dt;
    }

    // Clamp paddle position so it stays within the window
    float halfHeight = shape.getSize().y / 2.0f;
    paddleY = std::clamp(paddleY, halfHeight, static_cast<float>(windowSize.y) - halfHeight);

    shape.setPosition(sf::Vector2f(shape.getPosition().x, paddleY));

    // Collision detection with puck (simple bounding box)
    // Reflect puck horizontal
    sf::FloatRect paddleBounds = shape.getGlobalBounds();
    sf::FloatRect puckBounds = puck.getPositionRect();

    if (paddleBounds.position.x < puckBounds.position.x + puckBounds.size.x &&
        paddleBounds.position.x + paddleBounds.size.x > puckBounds.position.x &&
        paddleBounds.position.y < puckBounds.position.y + puckBounds.size.y &&
        paddleBounds.position.y + paddleBounds.size.y > puckBounds.position.y)
    {
        puck.bounceHorizontal();
    }
}