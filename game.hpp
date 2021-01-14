#ifndef GAME_H
#define GAME_H
#include <learnopengl/camera.h>
#include <learnopengl/shader_m.h>
#include <sprite_renderer.hpp>
#include <level_loader.hpp>
#include <crosshair.h>
#include <ship.hpp>
#include <bullet.hpp>

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
    void mouseClicked();
    void mouseReleased();

private:
    int mouseClick;
    Shader cross = Shader();
    Shader shader = Shader();
    SpriteRenderer background;
    Camera* camera;
    Ship* ship;
    GAMEOBJECTS objectSet;
    LevelLoader ll;
};

#endif GAME_H