#include <game.hpp>
#include <game_object.hpp>
#include <asteroid.hpp>
#include <glad/glad.h>

Game::Game(Camera& camera) {
	this->camera = &camera;
	State = GAME_MAIN_MENU;
	shader.compileShader("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
	text.compileShader("shaders/text.vs", "shaders/text.fs");
	textRenderer.setupShader(text, 800, 600);
	textRenderer.loadFont();
	this->menu_background = SpriteRenderer(shader, *(this->camera), "objects/universe.obj");
}

Game::Game() {}

void Game::init() {
	shader.compileShader("shaders/vertex_shader.vs", "shaders/fragment_shader.fs");
	text.compileShader("shaders/text.vs", "shaders/text.fs");
	textRenderer.setupShader(text, 800, 600);
	textRenderer.loadFont();
	this->menu_background = SpriteRenderer(shader, *(this->camera), "objects/universe.obj");
	warningFlag = 0;
	difficulty = 1;
	objectSet.clear();
	ll = LevelLoader(objectSet, shader, *(this->camera));
	ship = ll.getShip();
	mouseClick = 1;
	score = 0;
	cross.compileShader("shaders/SimpleVertexShader.vs", "shaders/SimpleFragmentShader.fs");
	this->background = SpriteRenderer(shader, *(this->camera), "objects/universe.obj");
}

void Game::tick() {
	if (difficulty % 20 == 0) {
		difficulty = 1;
		ll.addDifficulty();
	}
	int flag = 0;
	for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it) {
		if (((*it)->objectType == "asteroid")) {
			Asteroid* aux = dynamic_cast<Asteroid*>(*it);
			if (aux->objectSet != &this->objectSet) {
				aux->objectSet = &objectSet;
			}
		}
		if ((*it)->deleteFlag) {
			if (((*it)->objectType == "asteroid")) difficulty += 1;
			objectSet.erase(it);
			break;
		}
		switch ((*it)->tick()) {
		case 1: //if 1 is returned then the object is destroyed
			flag = 1;
			objectSet.erase(it);
			break;
		case 2: //if 2 is returned then 
			ship->healthpoints += 2;
			score += 10;
			difficulty += 1;
			it = objectSet.begin();
			break;
		case 3:
			flag = 1;
			objectSet.erase(it);
			ship->healthpoints -= 30;
			difficulty += 1;
			break;
		case 4:
			State = GAME_OVER;
			break;
		case 5:
			warningFlag = 1;
			break;
		case 6:
			warningFlag = 0;
			break;
		default: 
			break;
		}
		if (flag) break;
	}
}

void Game::render() {
    if (State == GAME_ACTIVE) {
        background.DrawSprite();
        for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it)
            (*it)->render();
        textRenderer.render(text, "Score: " + std::to_string(score), 25.0f, 25.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        textRenderer.render(text, "HP: " + std::to_string(ship->healthpoints), 25.0f, 45.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
		if(warningFlag) textRenderer.render(text, "WARNING - LEAVING GAME ZONE", 200.0f, 500.0f, 0.5f, glm::vec3(1.0f, 0.0f, 0.0f));
		glDisable(GL_BLEND);
		renderCrosshair(cross);
		glEnable(GL_BLEND);
    }
    if (State == GAME_MAIN_MENU) {
        menu_background.DrawSprite();
        textRenderer.render(text, "Asteroids - Alpha Defense Team", 200.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        textRenderer.render(text, "Start", 350.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        textRenderer.render(text, "Exit", 360.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
    if (State == GAME_PAUSED) {
        menu_background.DrawSprite();
        textRenderer.render(text, "Pause", 370.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        textRenderer.render(text, "Continue", 350.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        textRenderer.render(text, "Exit", 360.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
    if (State == GAME_OVER) {
        menu_background.DrawSprite();
		textRenderer.render(text, "GAME OVER", 330.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
		textRenderer.render(text, "Try again", 340.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
		textRenderer.render(text, "Exit", 365.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
}

void Game::mouseClicked() {
    if(mouseClick) {
        if (State == GAME_ACTIVE) {
            objectSet.push_back(new Bullet(shader, *camera, camera->Front, objectSet));
        }
    }
	mouseClick = 0;
}

void Game::mouseReleased() {
	mouseClick = 1;
}
