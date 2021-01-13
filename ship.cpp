#include <ship.hpp>

Ship::Ship(Shader &shader, Camera &camera) {
	this->shader = &shader;
	this->camera = &camera;
	this->spriterenderer = SpriteRenderer(*(this->shader), *(this->camera),"objects/ship.obj");
}

Ship::Ship() {}

void Ship::render() {
	position = camera->Position;
	spriterenderer.DrawSprite(position + glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(0.0f,0.0f,0.0f), -glm::radians(camera->Yaw + 90.0f), glm::radians(camera->Pitch));
}

