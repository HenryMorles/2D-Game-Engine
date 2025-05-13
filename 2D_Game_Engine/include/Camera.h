#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

class Camera
{
public:
    Camera(int screenWidth, int screenHeight, int worldWidth, int worldHeight);

    void follow(GameObject* target);
    void update();

    int getX() const;
    int getY() const;

    void setPosition(int x, int y);
    void setWorldBounds(int width, int height);

private:
    int x, y;
    int screenWidth, screenHeight;
    int worldWidth, worldHeight;

    GameObject* target;
};

#endif // CAMERA_H