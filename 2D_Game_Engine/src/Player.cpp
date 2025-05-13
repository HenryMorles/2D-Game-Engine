#include "Player.h"
#include "IGameScene.h"
#include "GameObject.h"
#include "InputManager.h"

#include <SDL.h>

Player::Player(int x, int y, int width, int height, SDL_Renderer* renderer, IGameScene* scene)
    : GameObject(x, y, width, height, renderer, scene),
    velocityY(0.0f), isOnGround(false), moveSpeed(3.5f)
{
}

void Player::update()
{
    const float gravity = 0.5f;
    const float maxFallSpeed = 10.0f;

    velocityY += gravity;
    if (velocityY > maxFallSpeed)
        velocityY = maxFallSpeed;

    int newY = y + static_cast<int>(velocityY);
    SDL_Rect testRect = { x, newY, width, height };

    if (!isCollidingAt(testRect))
    {
        y = newY;
        isOnGround = false;
    }
    else
    {
        velocityY = 0.0f;
        isOnGround = true;
    }
}

void Player::handleInput(InputManager& input)
{
    int newX = x;

    // Move left
    if (input.isKeyDown(SDL_SCANCODE_A))
        newX -= static_cast<int>(moveSpeed);

    // Move right
    if (input.isKeyDown(SDL_SCANCODE_D))
        newX += static_cast<int>(moveSpeed);

    // Jump if on ground
    if (input.isKeyDown(SDL_SCANCODE_SPACE) && isOnGround && velocityY == 0.0f)
    {
        velocityY = -10.0f;
        isOnGround = false;
    }

    // Test horizontal movement with collision
    SDL_Rect testRect = { newX, y, width, height };

    if (!isCollidingAt(testRect))
    {
        x = newX;
    }
}

bool Player::isCollidingAt(const SDL_Rect& rect)
{
    // Check collision with all other game objects in the scene
    for (GameObject* obj : scene->getObjects())
    {
        if (obj != this && obj->checkCollision(rect))
            return true;
    }
    return false;
}