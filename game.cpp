#include <game.hpp>
#include <game_object.hpp>

Game::Game(Camera& camera) {
	this->camera = &camera;
	State = GAME_ACTIVE;
	Game::init();
	ll = LevelLoader(objectSet, shader, *(this->camera));
	ship = ll.getShip();
	mouseClick = 1;
}

Game::Game() {}

void Game::init() {
	shader.compileShader("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
	cross.compileShader("shaders/SimpleVertexShader.vs", "shaders/SimpleFragmentShader.fs");
	this->background = SpriteRenderer(shader, *(this->camera), "objects/universe.obj");
}

void Game::tick() {
	int flag = 0;
	for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it) {
		switch ((*it)->tick()) {
		case 1: //if 1 is returned then we the object is destroyed
			flag = 1;
			objectSet.erase(it);
			break;
		default: break;
		}
		if (flag) break;
	}
}

void Game::render() {
	background.DrawSprite();
	renderCrosshair(cross);
	for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it)
		(*it)->render();
}

void Game::mouseClicked() {
	if(mouseClick)
	if (State == GAME_ACTIVE) {
		objectSet.push_back(new Bullet(shader, *camera, camera->Front, objectSet));
	}
	mouseClick = 0;
}

void Game::mouseReleased() {
	mouseClick = 1;
}