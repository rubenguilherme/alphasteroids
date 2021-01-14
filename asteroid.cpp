#include <asteroid.hpp>

Asteroid::Asteroid(Shader &shader, Camera &camera, GAMEOBJECTS& objectSet) {
	this->shader = &shader;
	this->camera = &camera;
	this->objectSet = &objectSet;
	position = glm::vec3(8.0f,0.0f,-8.0f);
	spriterenderer = SpriteRenderer(*(this->shader), *(this->camera), "objects/asteroid.obj");
	objectType = "asteroid";
	deleteFlag = 0;
}

Asteroid::Asteroid() {}

void Asteroid::render() {
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
			//TAKE DAMAGE
			return 1;
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