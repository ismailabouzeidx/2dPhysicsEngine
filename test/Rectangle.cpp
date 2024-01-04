#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float w, float h, float mass) : PhysicsEntity(x, y, mass), width(w), height(h) {}

void Rectangle::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectShape(sf::Vector2f(width, height));
    rectShape.setPosition(position);
    rectShape.setFillColor(sf::Color::Blue);
    window.draw(rectShape);
}
