#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class InputManager;

class Player : public GameObject
{
public:
    Player(int x, int y, int width, int height, SDL_Renderer* renderer, IGameScene* scene);

    void update() override;

    void handleInput(InputManager& input);

private:
    float velocityY;
    bool isOnGround;
    float moveSpeed;

    bool isCollidingAt(const SDL_Rect& rect);
};

#endif // PLAYER_H