#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "IGameScene.h"
#include "InputManager.h"
#include "TextureManager.h"

#include <SDL.h>
#include <SDL_image.h>

class GameEngine
{
public:
    GameEngine();
    ~GameEngine();

    void run(const char* title, int x, int y, int width, int height, bool fullscreen, IGameScene* scene);

    bool isRunning() const;

private:
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

    // Core loop functions
    void handleEvents();
    void update();
    void render();
    void clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    IGameScene* currentScene;

    TextureManager textureManager;
    InputManager input;
};

#endif // GAME_ENGINE_H