# 2D Game Engine — C++ & SDL2

A modular 2D game engine built using modern C++ and SDL2. The project is designed around a clean architecture with full support for input, camera control, resource management, UI, and scene abstraction.

---

## 🚀 Features

- **Scene-based engine** (`IGameScene`) with encapsulated game logic
- **Camera system** that follows the player and clamps to world bounds
- **InputManager** for per-frame input handling (pressed, held, released)
- **TextureManager** with caching to avoid duplicate loads
- **Flexible GameObject hierarchy** with extensible components
- **UI support** for static screen-space elements (e.g. icons)
- **Fully dynamic level setup** from code
- **Separation of engine/game code** for maintainability

---

## 🧱 Project Layout

```
2D_Game_Engine/
├── include/             # Header files
├── src/                 # Source files
├── assets/              # Images and textures
├── libs/                # External dependencies (SDL2, SDL_image)
```

---

## 🛠 Requirements

- C++17
- SDL2
- SDL2_image

---

## 🎮 How It Works

- The `GameEngine` class initializes SDL, manages the main loop and delegates work to the active scene.
- `MyGameScene` defines game logic, sets up objects, and controls the camera and UI.
- `Player` and `Obstacle` extend `GameObject` and implement game-specific behavior.
- All textures are loaded through a centralized `TextureManager`.
- Input is tracked per-frame via `InputManager`.

---

## 📄 License

MIT — free to use, modify and share.
