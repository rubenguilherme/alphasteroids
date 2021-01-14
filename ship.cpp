#include <ship.hpp>

Ship::Ship(Shader &shader, Camera &camera) {
	this->shader = &shader;
	this->camera = &camera;
	this->spriterenderer = SpriteRenderer(*(this->shader), *(this->camera),"objects/ship.obj");
	objectType = "ship";
	deleteFlag = 0;
	healthpoints = 100;
}

Ship::Ship() {}

void Ship::render() {
	spriterenderer.DrawSprite(position + glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f), -glm::radians(camera->Yaw + 90.0f), glm::radians(camera->Pitch));
}

int Ship::tick() {
	if (healthpoints < 0) return 4;
	position = camera->Position;
	return checkCollisions();
}

int Ship::checkCollisions() {
	if (checkCollisionWithSphere())
		return 4;
	if (checkProximityWithSphere())
		return 5;
	return 6;
}

int Ship::checkProximityWithSphere() {
	if (sqrt((position.x) * (position.x) +
		(position.y) * (position.y) +
		(position.z) * (position.z)) >= 350) return 1;
	return 0;
}
