#define SDL_MAIN_HANDLED

#include <SDL.h>
#include "GameEngine.h"
#include "MyGameScene.h"


int main()
{
    GameEngine engine;
    MyGameScene scene;
    engine.run("2D Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false, &scene);
    return 0;
}