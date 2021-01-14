#include <ship.hpp>

Ship::Ship(Shader &shader, Camera &camera) {
	this->shader = &shader;
	this->camera = &camera;
	this->spriterenderer = SpriteRenderer(*(this->shader), *(this->camera),"objects/ship.obj");
	objectType = "ship";
	deleteFlag = 0;
}

Ship::Ship() {}

void Ship::render() {
	spriterenderer.DrawSprite(position + glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f), -glm::radians(camera->Yaw + 90.0f), glm::radians(camera->Pitch));
}

int Ship::tick() {
	position = camera->Position;
	return checkCollisions();
}

int Ship::checkCollisions() {
	if (checkCollisionWithSphere())
		return 3;
	if (checkProximityWithSphere())
		//WARNING
		std::cout << "OLA" << std::endl;
	return 0;
}

int Ship::checkProximityWithSphere() {
	if (position.x >= 400 || position.x <= -400) return 1;
	if (position.y >= 400 || position.y <= -400) return 1;
	if (position.z >= 400 || position.z <= -400) return 1;
	return 0;
}