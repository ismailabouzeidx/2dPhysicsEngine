#pragma once

#include "PhysicsEntity.hpp"

class Rectangle : public PhysicsEntity {
public:
    float width;
    float height;

    Rectangle(float x, float y, float w, float h, float mass);
    virtual ~Rectangle() {}

    void draw(sf::RenderWindow& window) override;
};