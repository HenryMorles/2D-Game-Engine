#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"

class Obstacle : public GameObject
{
public:
    Obstacle(int x, int y, int width, int height, SDL_Renderer* renderer, IGameScene* scene)
        : GameObject(x, y, width, height, renderer, scene) {
    }
};

#endif // OBSTACLE_H