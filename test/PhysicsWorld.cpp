#include "PhysicsWorld.hpp"

PhysicsWorld::PhysicsWorld(const sf::Vector2f& gravity) : gravity(gravity) {}

void PhysicsWorld::addEntity(std::unique_ptr<PhysicsEntity> entity) {
    entities.push_back(std::move(entity));
}

void PhysicsWorld::update(float deltaTime) {
    applyGravity();

    for (auto& entity : entities) {
        entity->update(deltaTime);
    }
}

void PhysicsWorld::draw(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        entity->draw(window);
    }
}
void PhysicsWorld::applyGravity() {
    // Apply gravity to all entities in the world
    for (auto& entity : entities) {
        entity->applyForce(gravity);
    }
}