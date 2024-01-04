#include "PhysicsWorld.hpp"
#include <iostream>

PhysicsWorld::PhysicsWorld(const sf::Vector2f& gravity) : gravity(gravity) {}

void PhysicsWorld::addEntity(std::unique_ptr<PhysicsEntity> entity) {
    entities.push_back(std::move(entity));
}

void PhysicsWorld::update(float deltaTime, sf::RenderWindow& window) {
    applyGravity();

    for (auto& entity : entities) {
        entity->update(deltaTime);

        handleWindowCollisions(*entity, window);
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
void PhysicsWorld::handleWindowCollisions(PhysicsEntity& entity, sf::RenderWindow& window) {
    sf::Vector2f entityPosition = entity.position;
    float entityRadius = 20.0f;
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;

    if (entityPosition.x - entityRadius < 0 || entityPosition.x + entityRadius > windowWidth) {
        std::cout << "Colliding with horizontal wall" << std::endl;
        entity.velocity.x = -entity.velocity.x; // Reverse the horizontal velocity
    }

    if (entityPosition.y - entityRadius < 0 || entityPosition.y + entityRadius > windowHeight) {
        std::cout << "Colliding with vertical wall" << std::endl;
        entity.velocity.y = -entity.velocity.y; // Reverse the vertical velocity
    }
}