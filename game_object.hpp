#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <sprite_renderer.hpp>

class GameObject {
public:
	//funtions other classes have to implement
	virtual void render() = 0;
	virtual int tick() = 0;
	virtual int checkCollisions() = 0;
	int checkCollisionWithSphere();
	glm::vec3 getPos();
		
protected:
	glm::vec3 position;
	SpriteRenderer spriterenderer;
	Camera * camera;
	Shader * shader;
};

#endif GAME_OBJECT_H