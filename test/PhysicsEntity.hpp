#pragma once

#include <SFML/Graphics.hpp>

class PhysicsEntity {
public:
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
    float mass;

    PhysicsEntity(float x, float y, float mass);
    virtual ~PhysicsEntity() {}

    virtual void update(float deltaTime);
    virtual void draw(sf::RenderWindow& window) = 0;

    void applyForce(const sf::Vector2f& force);
};
