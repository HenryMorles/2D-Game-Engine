#include "UIElement.h"
#include "TextureManager.h"

#include <SDL_image.h>
#include <iostream>

UIElement::UIElement(int x, int y, int width, int height, SDL_Renderer* renderer)
    : x(x), y(y), width(width), height(height), renderer(renderer)
{
}

UIElement::~UIElement()
{
    if (texture)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
}

bool UIElement::loadTexture(const std::string& path, TextureManager& textureManager)
{
    SDL_Texture* loaded = textureManager.load(path, renderer);
    if (!loaded)
    {
        std::cerr << "Failed to load UI texture from TextureManager\n";
        return false;
    }

    texture = loaded;
    return true;
}

void UIElement::render()
{
    if (texture)
    {
        SDL_Rect dstRect = { x, y, width, height };
        SDL_RenderCopy(renderer, texture, nullptr, &dstRect);
    }
}