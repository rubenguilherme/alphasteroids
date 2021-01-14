#include "bullet.hpp"

Bullet::Bullet(Shader& shader, Camera& camera, glm::vec3 movVector, GAMEOBJECTS& objectSet) {
	this->shader = &shader;
	this->camera = &camera;
	this->movVector = movVector;
	this->objectSet = &objectSet;
	velocity = 0.2f;
	position = camera.Position + camera.Front + camera.Front;
	this->spriterenderer = SpriteRenderer(*(this->shader), *(this->camera), "objects/bullet.obj");
	objectType = "bullet";
	deleteFlag = 0;
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
	return (checkAsteroidCollision());
}

int Bullet::checkAsteroidCollision()
{
	for (GAMEOBJECTS::iterator it = objectSet->begin(); it != objectSet->end(); ++it)
		if ((*it)->objectType == "asteroid") {
			if (sqrt(((*it)->position.x - position.x) * ((*it)->position.x - position.x) +
				((*it)->position.y - position.y) * ((*it)->position.y - position.y) +
				((*it)->position.z - position.z) * ((*it)->position.z - position.z)) <= 1.3f + 0.1f) 
			{
				objectSet->erase(it);
				deleteFlag = 1;
				return 2;
			}
		}

	return 0;
}
