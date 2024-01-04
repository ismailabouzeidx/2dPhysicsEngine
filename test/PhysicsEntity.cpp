#include "PhysicsEntity.hpp"

PhysicsEntity::PhysicsEntity(float x, float y, float mass)
    : position(x, y), velocity(0, 0), acceleration(0, 0), mass(mass) {}

void PhysicsEntity::update(float deltaTime) {
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;
    acceleration = sf::Vector2f(0, 0);
}
void PhysicsEntity::applyForce(const sf::Vector2f& force) {
    // Newton's second law: F = ma
    // Calculate acceleration based on force and mass
    acceleration += force / mass;
}