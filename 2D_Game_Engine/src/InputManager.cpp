#include "InputManager.h"

#include <cstring>

InputManager::InputManager()
{
    currentKeys = SDL_GetKeyboardState(nullptr);
    std::memset(previousKeys, 0, SDL_NUM_SCANCODES);
}

void InputManager::update()
{
    SDL_PumpEvents();

    std::memcpy(previousKeys, currentKeys, SDL_NUM_SCANCODES);
    currentKeys = SDL_GetKeyboardState(nullptr);
}

bool InputManager::isKeyDown(SDL_Scancode key) const
{
    return currentKeys && currentKeys[key];
}

bool InputManager::isKeyPressed(SDL_Scancode key) const
{
    return currentKeys && !previousKeys[key] && currentKeys[key];
}

bool InputManager::isKeyReleased(SDL_Scancode key) const
{
    return currentKeys && previousKeys[key] && !currentKeys[key];
}