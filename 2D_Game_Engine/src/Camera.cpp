#include "Camera.h"

Camera::Camera(int screenWidth, int screenHeight, int worldWidth, int worldHeight)
    : x(0), y(0),
    screenWidth(screenWidth),
    screenHeight(screenHeight),
    worldWidth(worldWidth),
    worldHeight(worldHeight),
    target(nullptr)
{
}

void Camera::follow(GameObject* target)
{
    this->target = target;
}

void Camera::update()
{
    if (!target)
        return;

    // Center the camera on the target
    x = target->getX() + target->getWidth() / 2 - screenWidth / 2;
    y = target->getY() + target->getHeight() / 2 - screenHeight / 2;

    // Clamp the camera to world boundaries
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > worldWidth - screenWidth) x = worldWidth - screenWidth;
    if (y > worldHeight - screenHeight) y = worldHeight - screenHeight;
}

void Camera::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;

    // Clamp manually-set position to world bounds
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x > worldWidth - screenWidth) x = worldWidth - screenWidth;
    if (y > worldHeight - screenHeight) y = worldHeight - screenHeight;
}

void Camera::setWorldBounds(int width, int height)
{
    worldWidth = width;
    worldHeight = height;
}

int Camera::getX() const
{
    return x;
}

int Camera::getY() const
{
    return y;
}