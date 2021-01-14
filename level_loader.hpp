#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <typedefs.h>
#include <learnopengl/camera.h>
#include <learnopengl/shader_m.h>
#include <ship.hpp>

class LevelLoader
{
	
public:
	LevelLoader(GAMEOBJECTS& go, Shader& shader, Camera& camera);
	LevelLoader();
	Ship * getShip();
	void addDifficulty();
private:
	float velocity;
	int difficulty;
	GAMEOBJECTS* objectSet;
	Shader* shader;
	Camera* camera;
	Ship* ship;
};

#endif LEVEL_LOADER_H
