#ifndef LEVEL_LOADER_H
#define LEVEL_LOADER_H
#include <vector>
#include <game_object.hpp>
#include <learnopengl/camera.h>
#include <learnopengl/shader_m.h>

typedef std::vector<GameObject*> GAMEOBJECTS;

class LevelLoader
{
	
public:
	LevelLoader(GAMEOBJECTS& go, Shader& shader, Camera& camera);
	LevelLoader();
private:
	GAMEOBJECTS* objectSet;
	Shader* shader;
	Camera* camera;
};

#endif LEVEL_LOADER_H
