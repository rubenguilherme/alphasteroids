#ifndef BULLET_H
#define BULLET_H
#include <game_object.hpp>
#include <level_loader.hpp>

class Bullet : public GameObject
{
public:
	Bullet(Shader& shader, Camera& camera, glm::vec3 movVector, GAMEOBJECTS& objectSet);
	Bullet();
	void render();
	int tick();
	int checkCollisions();
	int checkAsteroidCollision();
private:
	GAMEOBJECTS * objectSet;
	glm::vec3 movVector;
	float velocity;
};

#endif BULLET_H
