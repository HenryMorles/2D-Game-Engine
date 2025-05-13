#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL.h>

class InputManager
{
public:
    InputManager();

    void update();

    bool isKeyDown(SDL_Scancode key) const;
    bool isKeyPressed(SDL_Scancode key) const;
    bool isKeyReleased(SDL_Scancode key) const;

private:
    const Uint8* currentKeys;
    Uint8 previousKeys[SDL_NUM_SCANCODES];
};

#endif // INPUT_MANAGER_H