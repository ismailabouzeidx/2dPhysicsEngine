#include "Circle.hpp"

Circle::Circle(float x, float y, float r, float mass) : PhysicsEntity(x, y, mass), radius(r) {}

void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circleShape(radius);
    circleShape.setPosition(position);
    circleShape.setFillColor(sf::Color::Red);
    window.draw(circleShape);
}
