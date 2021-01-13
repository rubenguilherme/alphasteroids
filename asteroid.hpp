#ifndef ASTEROID_H
#define ASTEROID_H

#include <game_object.hpp>

class Asteroid : public GameObject
{
public:
	Asteroid(Shader &shader, Camera &camera);
	Asteroid();
	void render();
};

#endif ASTEROID_H

