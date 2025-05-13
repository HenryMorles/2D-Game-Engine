#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <string>
#include <unordered_map>

class TextureManager
{
public:
    TextureManager() = default;
    ~TextureManager();

    SDL_Texture* load(const std::string& path, SDL_Renderer* renderer);
    void clear();
    void clear(const std::string& path);

private:
    std::unordered_map<std::string, SDL_Texture*> textureCache;
};

#endif // TEXTURE_MANAGER_H