#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <SDL.h>
#include <string>

class TextureManager;

class UIElement
{
public:
    UIElement(int x, int y, int width, int height, SDL_Renderer* renderer);
    virtual ~UIElement();

    virtual void render();

    bool loadTexture(const std::string& path, TextureManager& textureManager);

protected:
    int x, y, width, height;
    SDL_Renderer* renderer;
    SDL_Texture* texture = nullptr;
};

#endif // UI_ELEMENT_H