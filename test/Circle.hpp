#pragma once

#include "PhysicsEntity.hpp"

class Circle : public PhysicsEntity {
public:
	float radius;
	Circle(float x, float y, float z, float mass);
	virtual ~Circle() {};
	
	void handleWindowCollisions(sf::RenderWindow& window) override;
	void draw(sf::RenderWindow& window) override;
};