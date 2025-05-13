#ifndef I_GAME_SCENE_H
#define I_GAME_SCENE_H

#include "InputManager.h"
#include "TextureManager.h"

#include <SDL.h>
#include <vector>

class GameObject;

class IGameScene
{
public:
    virtual ~IGameScene() = default;

    virtual void init(SDL_Renderer* renderer, TextureManager& textureManager) = 0;
    virtual void update(InputManager& input) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void clean() = 0;

    virtual const std::vector<GameObject*>& getObjects() const = 0;

    virtual int getCameraX() const = 0;
    virtual int getCameraY() const = 0;
    virtual void setCameraPosition(int x, int y) = 0;
};

#endif // I_GAME_SCENE_H