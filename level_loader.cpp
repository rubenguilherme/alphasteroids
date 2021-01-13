#include <level_loader.hpp>
#include <game_object.hpp>
#include <ship.hpp>
#include <asteroid.hpp>

LevelLoader::LevelLoader(GAMEOBJECTS& go, Shader& shader, Camera& camera)
{
	objectSet = &go;
	this->shader = &shader;
	this->camera = &camera;
	objectSet->push_back(new Ship(*(this->shader), *(this->camera)));
	objectSet->push_back(new Asteroid(*(this->shader), *(this->camera)));
}

LevelLoader::LevelLoader() {

}
