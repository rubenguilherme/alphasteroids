#include <level_loader.hpp>
#include <game_object.hpp>
#include <asteroid.hpp>
#include <stdlib.h>
#include <GLFW/glfw3.h>

LevelLoader::LevelLoader(GAMEOBJECTS& go, Shader& shader, Camera& camera)
{
	difficulty = 5;
	velocity = 0.001f;
	srand(glfwGetTime());
	objectSet = &go;
	this->shader = &shader;
	this->camera = &camera;
	ship = new Ship(*(this->shader), *(this->camera));
	objectSet->push_back(ship);
	for (int i = 0; i < 10; i++) {
		objectSet->push_back(new Asteroid(*(this->shader), *(this->camera), *(this->objectSet), glm::vec3(((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX)) * 2.0f - 1.0f, glm::vec3(rand() % 200 - 100, rand() % 200 - 100, rand() % 200 - 100), velocity));
	}
	for (int i = 0; i < 10; i++) {
		objectSet->push_back(new Asteroid(*(this->shader), *(this->camera), *(this->objectSet), glm::vec3(((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX)) * 2.0f - 1.0f, glm::vec3(rand() % 700 - 350, rand() % 200 - 100, rand() % 700 - 350), velocity));
	}
}

LevelLoader::LevelLoader() {

}

Ship* LevelLoader::getShip() {
	return ship;
}

void LevelLoader::addDifficulty()
{
	if (difficulty > 2) {
		difficulty -= 0.5;
		velocity *= 1.5f;
	} else velocity *= 1.2f;
	for (int i = 0; i < 20; i++) {
		objectSet->push_back(new Asteroid(*(this->shader), *(this->camera), *(this->objectSet), glm::vec3(((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX) * 2.0f - 1.0f, ((float)rand() / RAND_MAX)) * 2.0f - 1.0f, glm::vec3(rand() % 700 - 350, rand() % 200 - 100, rand() % 700 - 350), velocity));
	}

}
