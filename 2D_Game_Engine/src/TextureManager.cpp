#include "TextureManager.h"

#include <SDL_image.h>
#include <iostream>

TextureManager::~TextureManager()
{
    clear();
}

SDL_Texture* TextureManager::load(const std::string& path, SDL_Renderer* renderer)
{
    if (textureCache.count(path) > 0)
        return textureCache[path];

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface)
    {
        std::cerr << "Failed to load image: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    textureCache[path] = texture;
    return texture;
}

void TextureManager::clear()
{
    for (auto& pair : textureCache)
    {
        SDL_DestroyTexture(pair.second);
    }

    textureCache.clear();
}

void TextureManager::clear(const std::string& path)
{
    if (textureCache.count(path))
    {
        SDL_DestroyTexture(textureCache[path]);
        textureCache.erase(path);
    }
}
