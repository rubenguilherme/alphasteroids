#include <asteroid.hpp>

Asteroid::Asteroid(Shader &shader, Camera &camera, GAMEOBJECTS& objectSet, glm::vec3 movVector, glm::vec3 position, float velocity) {
	this->shader = &shader;
	this->camera = &camera;
	this->objectSet = &objectSet;
	this->movVector = movVector;
	this->position = position;
	this->velocity = velocity;
	spriterenderer = SpriteRenderer(*(this->shader), *(this->camera), "objects/asteroid1.obj");
	objectType = "asteroid";
	deleteFlag = 0;
}

Asteroid::Asteroid() {}

void Asteroid::render() {
	position += movVector * velocity;
	spriterenderer.DrawSprite(position);
}

int Asteroid::tick() {
	return checkCollisions();
}

int Asteroid::checkCollisions() {
	if (checkCollisionWithSphere())
		return 1;
	for (GAMEOBJECTS::iterator it = objectSet->begin(); it != objectSet->end(); ++it) {
	if ((*it)->objectType == "ship") {
		if (sqrt(((*it)->position.x - position.x) * ((*it)->position.x - position.x) +
			((*it)->position.y - position.y) * ((*it)->position.y - position.y) +
			((*it)->position.z - position.z) * ((*it)->position.z - position.z)) <= 1.3f + 5.0f) {
			return 3;
		}
	}
	else if ((*it)->objectType == "asteroid" && (this != (*it))) {
		if (sqrt(((*it)->position.x - position.x) * ((*it)->position.x - position.x) +
			((*it)->position.y - position.y) * ((*it)->position.y - position.y) +
			((*it)->position.z - position.z) * ((*it)->position.z - position.z)) <= 1.3f + 1.3f) 
		{
			objectSet->erase(it);
			deleteFlag = 1;
			return 2;
		}
	}
	}
	return 0;
}
