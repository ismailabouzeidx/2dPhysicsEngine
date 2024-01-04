#include <SFML/Graphics.hpp>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "PhysicsWorld.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "2D Physics Engine");

    PhysicsWorld physicsWorld(sf::Vector2f(0, 9.8));  // Gravity in the positive Y direction

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse events
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Left mouse button pressed - spawn circle
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    physicsWorld.addEntity(std::make_unique<Circle>(static_cast<float>(mousePosition.x),
                        static_cast<float>(mousePosition.y),
                        20.0f, 5.0f));
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    // Right mouse button pressed - spawn rectangle
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    physicsWorld.addEntity(std::make_unique<Rectangle>(static_cast<float>(mousePosition.x),
                        static_cast<float>(mousePosition.y),
                        50.0f, 30.0f, 50.0f));
                }
            }
        }

        window.clear(sf::Color::White);

        // Update and render entities
        physicsWorld.update(0.01f, window); // Adjust deltaTime as needed
        physicsWorld.draw(window);

        window.display();
    }

    return 0;
}
