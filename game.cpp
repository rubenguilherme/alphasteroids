#include <game.hpp>
#include <game_object.hpp>

Game::Game(Camera& camera) {
	this->camera = &camera;
	State = GAME_ACTIVE;
	Game::init();
	ll = LevelLoader(objectSet, shader, *(this->camera));
}

Game::Game() {}

void Game::init() {
	shader.compileShader("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
	//cross.compileShader("shaders/SimpleVertexShader.vs", "shaders/SimpleFragmentShader.fs");
}

void Game::tick() {

}

void Game::render() {

	for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it)
		(*it)->render();
}