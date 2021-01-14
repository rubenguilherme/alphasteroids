#ifndef BULLET_H
#define BULLET_H
#include <game_object.hpp>
#include <typedefs.h>

class Bullet : public GameObject
{
public:
	Bullet(Shader& shader, Camera& camera, glm::vec3 movVector, GAMEOBJECTS& objectSet);
	Bullet();
	void render();
	int tick();
	int checkCollisions();
	int checkAsteroidCollision();
	GAMEOBJECTS* objectSet;
private:
	glm::vec3 movVector;
	float velocity;
};

#endif BULLET_H
