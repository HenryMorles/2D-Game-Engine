#include "MyGameScene.h"
#include <iostream>
#include <SDL_image.h>

MyGameScene::MyGameScene()
    : worldWidth(worldWidthDefault),
    worldHeight(screenHeight),
    player(nullptr),
    camera(screenWidth, screenHeight, worldWidthDefault, screenHeight),
    backgroundTexture(nullptr),
    iconUI(nullptr)
{
}

void MyGameScene::init(SDL_Renderer* renderer, TextureManager& textureManager)
{
    // Load background texture
    SDL_Surface* bgSurface = IMG_Load("assets/images/background.png");
    if (!bgSurface)
    {
        std::cerr << "Failed to load background: " << IMG_GetError() << std::endl;
    }
    else
    {
        backgroundTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
        SDL_FreeSurface(bgSurface);

        if (!backgroundTexture)
        {
            std::cerr << "Failed to create background texture: " << SDL_GetError() << std::endl;
        }
    }

    // Create player
    player = new Player(100, 100, 31, 63, renderer, this);
    if (!player->loadTexture("assets/images/deidara.png", textureManager))
    {
        std::cerr << "Failed to load player texture\n";
        return;
    }
    gameObjects.push_back(player);

    // Create fixed-position UI icon (top-right corner)
    iconUI = new UIElement(screenWidth - iconSize - iconMargin, iconMargin, iconSize, iconSize, renderer);
    if (!iconUI->loadTexture("assets/images/deidara_icon.png", textureManager))
    {
        std::cerr << "Failed to load UI icon\n";
    }

    // Create elevated obstacles (platforms)
    std::vector<SDL_Point> obstacleCoords = {
        {300, 450}, {400, 400}, {500, 350},
        {600, 300}, {700, 250}, {800, 200}
    };

    for (const auto& pos : obstacleCoords)
    {
        auto* obs = new Obstacle(pos.x, pos.y, 100, 20, renderer, this);
        if (!obs->loadTexture("assets/images/obstacle.png", textureManager))
        {
            std::cerr << "Failed to load obstacle texture\n";
            continue;
        }
        gameObjects.push_back(obs);
    }

    // Create ground tiles
    for (int i = 0; i < worldWidth; i += 64)
    {
        auto* tile = new Obstacle(i, screenHeight - 64, 64, 64, renderer, this);
        tile->loadTexture("assets/images/ground.png", textureManager);
        gameObjects.push_back(tile);
    }

    camera.follow(player);
    camera.setWorldBounds(worldWidth, worldHeight);
}

void MyGameScene::update(InputManager& input)
{
    player->handleInput(input);

    for (auto* obj : gameObjects)
    {
        obj->update();
    }

    camera.update();
}


void MyGameScene::render(SDL_Renderer* renderer)
{
    // Render background
    if (backgroundTexture)
    {
        int camX = camera.getX();
        int camY = camera.getY();
        SDL_Rect dstRect = { -camX, -camY, worldWidth, worldHeight };
        SDL_RenderCopy(renderer, backgroundTexture, nullptr, &dstRect);
    }

    // Render all game objects
    for (auto* obj : gameObjects)
    {
        obj->render();
    }

    // Render UI overlay
    if (iconUI)
    {
        iconUI->render();
    }
}

void MyGameScene::clean()
{
    // Clean up game objects
    for (auto* obj : gameObjects)
    {
        delete obj;
    }
    gameObjects.clear();

    // Clean up background texture
    if (backgroundTexture)
    {
        SDL_DestroyTexture(backgroundTexture);
        backgroundTexture = nullptr;
    }

    // Clean up UI icon
    if (iconUI)
    {
        delete iconUI;
        iconUI = nullptr;
    }

    player = nullptr;
}

const std::vector<GameObject*>& MyGameScene::getObjects() const
{
    return gameObjects;
}