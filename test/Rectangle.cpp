#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float w, float h, float mass) : PhysicsEntity(x, y, mass), width(w), height(h) {}

void Rectangle::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectShape(sf::Vector2f(width, height));
    rectShape.setPosition(position);
    rectShape.setFillColor(sf::Color::Blue);
    window.draw(rectShape);
}
void Rectangle::handleWindowCollisions(sf::RenderWindow& window) {
    if (position.x < 0) {
        position.x = 0;
        velocity.x = -velocity.x;
    }

    if (position.x + width > window.getSize().x) {
        position.x = window.getSize().x - width;
        velocity.x = -velocity.x;
    }

    if (position.y < 0) {
        position.y = 0;
        velocity.y = -velocity.y;
    }

    if (position.y + height > window.getSize().y) {
        position.y = window.getSize().y - height;
        velocity.y = -velocity.y;
    }
}