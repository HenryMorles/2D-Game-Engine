#include "GameEngine.h"
#include <iostream>

GameEngine::GameEngine()
    : window(nullptr), renderer(nullptr), running(false), currentScene(nullptr)
{
}

GameEngine::~GameEngine()
{
    clean();
}

void GameEngine::run(const char* title, int x, int y, int width, int height, bool fullscreen, IGameScene* scene)
{
    currentScene = scene;

    if (!init(title, x, y, width, height, fullscreen)) {
        return;
    }

    // Initialize the active scene
    if (currentScene) {
        currentScene->init(renderer, textureManager);
    }

    // Main game loop
    while (isRunning()) {
        handleEvents();  // Process SDL events
        update();        // Update input and game logic
        render();        // Render everything
        SDL_Delay(16);   // Cap to ~60 FPS
    }

    // Clean up the scene
    if (currentScene) {
        currentScene->clean();
    }

    clean(); // Final engine cleanup
}

bool GameEngine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                running = true;
                return true;
            }
        }
    }

    std::cerr << "SDL Initialization failed: " << SDL_GetError() << std::endl;
    return false;
}

void GameEngine::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false; // Exit on window close
        }
    }
}

void GameEngine::update()
{
    input.update(); // Use instance-based InputManager

    if (currentScene) {
        currentScene->update(input); // Delegate update logic to the scene
    }
}

void GameEngine::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    if (currentScene) {
        currentScene->render(renderer); // Delegate rendering to the scene
    }

    SDL_RenderPresent(renderer); // Display the frame
}

void GameEngine::clean()
{
    std::cout << "Cleaning up SDL\n";

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    IMG_Quit();  // Shutdown SDL_image
    SDL_Quit();  // Shutdown SDL
}

bool GameEngine::isRunning() const
{
    return running;
}