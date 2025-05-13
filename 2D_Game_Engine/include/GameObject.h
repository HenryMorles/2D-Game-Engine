#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class IGameScene;
class TextureManager;

class GameObject
{
public:
    GameObject(int x, int y, int width, int height, SDL_Renderer* renderer, IGameScene* scene);
    virtual ~GameObject();

    virtual void update();
    virtual void render();
    virtual void handleInput();
    virtual bool checkCollision(const SDL_Rect& rect) const;

    bool loadTexture(const std::string& filepath, TextureManager& textureManager);
    void setTexture(SDL_Texture* tex);
    void setPosition(int newX, int newY);

    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;

protected:
    int x, y, width, height;
    SDL_Renderer* renderer;
    IGameScene* scene;
    SDL_Texture* texture;
};

#endif // GAME_OBJECT_H