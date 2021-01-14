#ifndef ASTEROID_H
#define ASTEROID_H

#include <game_object.hpp>

class Asteroid : public GameObject
{
public:
	Asteroid(Shader &shader, Camera &camera);
	Asteroid();
	void render();
	int tick();
	int checkCollisions();
};

#endif ASTEROID_H

