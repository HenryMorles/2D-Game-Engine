#include "GameObject.h"
#include "IGameScene.h"
#include "TextureManager.h"

#include <iostream>

GameObject::GameObject(int x, int y, int width, int height, SDL_Renderer* renderer, IGameScene* scene)
    : x(x), y(y), width(width), height(height), renderer(renderer), scene(scene), texture(nullptr)
{
}

GameObject::~GameObject()
{
    // Note: We don't destroy the texture because it may be managed by TextureManager
    texture = nullptr;
}

void GameObject::update()
{
    // Default: does nothing. To be overridden by subclasses.
}

void GameObject::render()
{
    // Get camera offset from scene
    int camX = scene ? scene->getCameraX() : 0;
    int camY = scene ? scene->getCameraY() : 0;

    SDL_Rect destRect = { x - camX, y - camY, width, height };

    if (texture)
    {
        SDL_RenderCopy(renderer, texture, nullptr, &destRect);
    }
    else
    {
        // Fallback: draw a green rectangle if no texture is set
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &destRect);
    }
}

void GameObject::handleInput()
{
    // Default: no input handled
}

int GameObject::getX() const
{
    return x;
}

int GameObject::getY() const
{
    return y;
}

int GameObject::getWidth() const
{
    return width;
}

int GameObject::getHeight() const
{
    return height;
}

void GameObject::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}

bool GameObject::loadTexture(const std::string& filepath, TextureManager& textureManager)
{
    SDL_Texture* loaded = textureManager.load(filepath, renderer);
    if (!loaded)
        return false;

    setTexture(loaded);
    return true;
}

void GameObject::setTexture(SDL_Texture* tex)
{
    // If previously assigned manually, destroy it to avoid memory leak
    if (texture)
    {
        SDL_DestroyTexture(texture);
    }

    texture = tex;
}

bool GameObject::checkCollision(const SDL_Rect& rect) const
{
    SDL_Rect thisRect = { x, y, width, height };

    // Axis-Aligned Bounding Box collision detection
    return thisRect.x < rect.x + rect.w &&
        thisRect.x + thisRect.w > rect.x &&
        thisRect.y < rect.y + rect.h &&
        thisRect.y + thisRect.h > rect.y;
}