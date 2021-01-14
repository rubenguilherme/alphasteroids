#include <game.hpp>
#include <game_object.hpp>
#include <text_renderer.hpp>

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
	shader.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/vertex_shader.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/fragment_shader.fs");
	cross.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/SimpleVertexShader.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/SimpleFragmentShader.fs");
	this->background = SpriteRenderer(shader, *(this->camera), "/Users/pauloduarte/Documents/cg_project/cg_project/objects/universe.obj");
    this->menu_background = SpriteRenderer(shader, *(this->camera), "/Users/pauloduarte/Documents/cg_project/cg_project/objects/universe.obj");
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
    if (State == GAME_ACTIVE) {
        background.DrawSprite();
        renderCrosshair(cross);
        for (GAMEOBJECTS::iterator it = objectSet.begin(); it != objectSet.end(); ++it)
            (*it)->render();
        TextRenderer score, health;
        Shader shader;
        shader.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.fs");
        score.setupShader(shader, 800, 600);
        health.setupShader(shader, 800, 600);
        score.loadFont();
        health.loadFont();
        score.render(shader, "Score: " + std::to_string(21), 25.0f, 25.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        score.render(shader, "HP: " + std::to_string(21), 25.0f, 45.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
    if (State == GAME_MAIN_MENU) {
        menu_background.DrawSprite();
        TextRenderer title, option1, option2;
        Shader shader;
        shader.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.fs");
        title.setupShader(shader, 800, 600);
        option1.setupShader(shader, 800, 600);
        option2.setupShader(shader, 800, 600);
        title.loadFont();
        option1.loadFont();
        option2.loadFont();
        title.render(shader, "Asteroids - Alpha Defense Team", 200.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option1.render(shader, "Start", 350.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option2.render(shader, "Exit", 360.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
    if (State == GAME_PAUSED) {
        menu_background.DrawSprite();
        TextRenderer title, option1, option2;
        Shader shader;
        shader.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.fs");
        title.setupShader(shader, 800, 600);
        option1.setupShader(shader, 800, 600);
        option2.setupShader(shader, 800, 600);
        title.loadFont();
        option1.loadFont();
        option2.loadFont();
        title.render(shader, "Pause", 370.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option1.render(shader, "Continue", 350.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option2.render(shader, "Exit", 360.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
    }
    if (State == GAME_OVER) {
        menu_background.DrawSprite();
        TextRenderer title, option1, option2;
        Shader shader;
        shader.compileShader("/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.vs", "/Users/pauloduarte/Documents/cg_project/cg_project/shaders/text.fs");
        title.setupShader(shader, 800, 600);
        option1.setupShader(shader, 800, 600);
        option2.setupShader(shader, 800, 600);
        title.loadFont();
        option1.loadFont();
        option2.loadFont();
        title.render(shader, "GAME OVER", 330.0f, 500.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option1.render(shader, "Try again", 340.0f, 350.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
        option2.render(shader, "Exit", 365.0f, 300.0f, 0.5f, glm::vec3(0.5, 0.8f, 0.2f));
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
