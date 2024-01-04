#pragma once

#include <vector>
#include <memory>
#include "PhysicsEntity.hpp"

class PhysicsWorld {
private:
    std::vector<std::unique_ptr<PhysicsEntity>> entities;
    sf::Vector2f gravity;

public:
    PhysicsWorld(const sf::Vector2f& gravity);
    
    void addEntity(std::unique_ptr<PhysicsEntity> entity);
    void update(float deltaTime, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    void applyGravity();

private:
    void handleWindowCollisions(PhysicsEntity& entity, sf::RenderWindow& window);
};

