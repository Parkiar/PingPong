#include <SFML/Graphics.hpp>
#include <vector>

#include "Puck.h" 
#include "Paddles.h"
#include "Enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800, 600)), "SFML PUCK");

    sf::Clock clock; // starts the timer for smooth movements to match frame rate

    Puck myPuck;
    Paddle player(50.0f);
    Enemy enemy(750.0f);
    
    enemy.setPosition(enemy.getPosition().x, 300.0f);

    std::vector<DrawableObject*> gameObjects = { &player, &enemy, &myPuck };

    while (window.isOpen()) {
        // Updated SFML 3 event handling
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        float dt = clock.restart().asSeconds();  // time since last frame in seconds

        // Player movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            player.move(dt, window.getSize(), true); // 'true' for moving up (see paddles cpp)
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || 
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            player.move(dt, window.getSize(), false); // 'false' for moving down
        }

        myPuck.update(dt, window.getSize());
        enemy.update(dt, window.getSize(), myPuck);

        // Player collision w puck
        sf::FloatRect playerBounds = player.getGlobalBounds();
        sf::FloatRect puckBounds = myPuck.getPositionRect();

        if (playerBounds.position.x < puckBounds.position.x + puckBounds.size.x &&
            playerBounds.position.x + playerBounds.size.x > puckBounds.position.x &&
            playerBounds.position.y < puckBounds.position.y + puckBounds.size.y &&
            playerBounds.position.y + playerBounds.size.y > puckBounds.position.y)
        {
            myPuck.bounceHorizontal();
        }


        window.clear(sf::Color::Black);

        for (auto obj : gameObjects) {
            obj->draw(window);
        }

        window.display();
    }

    return 0;
}
