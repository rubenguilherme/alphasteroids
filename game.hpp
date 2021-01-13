#ifndef GAME_H
#define GAME_H
#include <learnopengl/camera.h>
#include <learnopengl/shader_m.h>
#include <level_loader.hpp>

enum GameState
{
    GAME_ACTIVE,
    GAME_MAIN_MENU,
    GAME_PAUSED,
    GAME_OVER
};

class Game {
public:
    Game(Camera& camera);
    Game();
    GameState State;
    void init();
    void tick();
    void render();

private:
    //Shader cross = Shader();
    Shader shader = Shader();
    Camera* camera;
    GAMEOBJECTS objectSet;
    LevelLoader ll;
};

#endif GAME_H