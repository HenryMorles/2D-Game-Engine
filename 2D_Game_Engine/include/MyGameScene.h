#ifndef MY_GAME_SCENE_H
#define MY_GAME_SCENE_H

#include "IGameScene.h"
#include "Player.h"
#include "Obstacle.h"
#include "Camera.h"
#include "UIElement.h"

#include <vector>

class MyGameScene : public IGameScene
{
public:
    MyGameScene();

    void init(SDL_Renderer* renderer, TextureManager& textureManager) override;
    void update(InputManager& input) override;
    void render(SDL_Renderer* renderer) override;
    void clean() override;

    const std::vector<GameObject*>& getObjects() const override;

    int getCameraX() const override { return camera.getX(); }
    int getCameraY() const override { return camera.getY(); }
    void setCameraPosition(int x, int y) override { camera.setPosition(x, y); }

private:
    // Constants for screen and UI layout
    static constexpr int screenWidth = 800;
    static constexpr int screenHeight = 600;
    static constexpr int worldWidthDefault = 2400;
    static constexpr int iconSize = 64;
    static constexpr int iconMargin = 16;

    int worldWidth;
    int worldHeight;

    std::vector<GameObject*> gameObjects;
    Player* player;
    Camera camera;
    SDL_Texture* backgroundTexture;
    UIElement* iconUI;
};

#endif // MY_GAME_SCENE_H