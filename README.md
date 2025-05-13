# ⚙️ 2D Game Engine (C++ / SDL2)

A lightweight and modular 2D game engine written in modern C++ using SDL2.  
Designed with **clean architecture**, **scene management**, and **real-time input/resource handling**.

---

## ✨ Features

- 🎮 Entity-based architecture (`GameObject`, `Player`, `Obstacle`, `UIElement`)
- 🎥 Smooth camera system that follows the player
- 📦 TextureManager with automatic texture caching
- 🎯 InputManager with per-frame key state tracking (`isKeyDown`, `isKeyPressed`, `isKeyReleased`)
- 🧱 Scene system via `IGameScene` interface
- 🖼 UI rendering support (e.g., static screen-space icons)
- 🧹 Automatic memory/resource cleanup (`SDL_Texture`, etc.)
- ✅ Ready to extend into ECS, tilemaps, animation, etc.

---

## 📁 Project Structure

```
src/
├── engine/
│   ├── GameEngine.h/.cpp
│   ├── InputManager.h/.cpp
│   ├── TextureManager.h/.cpp
│   └── Camera.h/.cpp
├── objects/
│   ├── GameObject.h/.cpp
│   ├── Player.h/.cpp
│   ├── Obstacle.h/.cpp
│   └── UIElement.h/.cpp
├── scenes/
│   ├── IGameScene.h
│   └── MyGameScene.h/.cpp
└── main.cpp
```

---

## 🛠 Requirements

- **C++17**
- **SDL2**
- **SDL2_image**

Install via package manager:

```bash
# Ubuntu
sudo apt install libsdl2-dev libsdl2-image-dev

# macOS
brew install sdl2 sdl2_image
```

---

## 🚀 Build & Run

Using CMake:

```bash
mkdir build
cd build
cmake ..
make
./GameEngineApp
```

Manual compile:

```bash
g++ -std=c++17 -Iinclude src/**/*.cpp -lSDL2 -lSDL2_image -o GameEngineApp
```

---

## 🖼 Demo

![screenshot](assets/images/demo_preview.png)

---

## 🧠 Design Notes

- Fully instance-based architecture (no global/singleton managers)
- Separated engine code from game logic
- Proper use of RAII and memory management
- Easily extendable for tilemaps, events, particles, etc.

---

## 📌 Roadmap

- [ ] DeltaTime & frame rate independence
- [ ] Animation system (spritesheets)
- [ ] Tilemap loader + editor support
- [ ] AudioManager (SDL_mixer)
- [ ] JSON scene config

---

## 📄 License

MIT — free to use for any purpose.