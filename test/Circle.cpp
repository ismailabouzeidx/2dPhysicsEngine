#include "Circle.hpp"

Circle::Circle(float x, float y, float r, float mass) : PhysicsEntity(x, y, mass), radius(r) {}

void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circleShape(radius);
    circleShape.setPosition(position);
    circleShape.setFillColor(sf::Color::Red);
    window.draw(circleShape);
}
void Circle::handleWindowCollisions(sf::RenderWindow& window) {
    if (position.x - radius < 0) {
        position.x = radius;
        velocity.x = -velocity.x;
    }

    if (position.x + radius > window.getSize().x) {
        position.x = window.getSize().x - radius;
        velocity.x = -velocity.x;
    }

    if (position.y - radius < 0) {
        position.y = radius;
        velocity.y = -velocity.y;
    }

    if (position.y + radius > window.getSize().y) {
        position.y = window.getSize().y - radius;
        velocity.y = -velocity.y;
    }
}