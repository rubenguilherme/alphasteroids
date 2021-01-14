#ifndef ASTEROID_H
#define ASTEROID_H

#include <game_object.hpp>
#include <typedefs.h>

class Asteroid : public GameObject
{
public:
	Asteroid(Shader &shader, Camera &camera, GAMEOBJECTS& objectSet, glm::vec3 movVector, glm::vec3 position, float velocity);
	Asteroid();
	void render();
	int tick();
	int checkCollisions();
	GAMEOBJECTS* objectSet;
private:
	glm::vec3 movVector;
	float velocity;
};

#endif ASTEROID_H

