#include "bullet.hpp"

Bullet::Bullet(Shader& shader, Camera& camera, glm::vec3 movVector, GAMEOBJECTS& objectSet) {
	this->shader = &shader;
	this->camera = &camera;
	this->movVector = movVector;
	this->objectSet = &objectSet;
	velocity = 0.05f;
	position = camera.Position + glm::vec3(0.0f, -1.0f, 0.0f);
	this->spriterenderer = SpriteRenderer(*(this->shader), *(this->camera), "/Users/pauloduarte/Documents/cg_project/cg_project/objects/bullet.obj");
}

Bullet::Bullet() {}

void Bullet::render() {
	spriterenderer.DrawSprite(position);
}

int Bullet::tick() {
	position += movVector * velocity;
	return (checkCollisions());
}

int Bullet::checkCollisions() {
	if (checkCollisionWithSphere())
		return 1;

	return 0;
}

int Bullet::checkAsteroidCollision()
{
	return 0;
}
