# Snake Game using SDL2 (C)

## Overview

This project is a **basic implementation of the classic Snake game written in C using SDL2**. The primary goal of this project was to learn **SDL2 fundamentals**, including window creation, rendering, event handling, and real-time game loops, rather than to build a fully polished game.

The game uses a simple grid-based positioning system and a fixed-timestep loop to update game state.

---

## Features

* Written in **C** using the **SDL2** library
* Real-time game loop with continuous rendering
* Keyboard input handling for snake movement
* Custom coordinate-based positioning logic with screen-edge wraparound
* Basic collision detection (snake body) with screen-edge wraparound instead of hard boundaries
* Simple food spawning mechanism
* Stable execution (runs without crashing)

---

## Screenshot

![image](https://github.com/user-attachments/assets/09f11183-439f-4b2a-b572-91008e47bf8a)

---

## Controls

* **WASD** – Move the snake
* **Q** – Exit the game

---

## How It Works (High-Level)

* The game runs in a loop that:

  1. Clears screen to prepare it for rendering
  2. Draws food and the snake
  3. Move snake by one unit (the size of each snake part in pixels)
  4. Check for collisions either with food or the snake itself
  5. Change the direction snake moves in based on user input
  6. Draw the scene
  7. Process user input
  8. Sleep for 144ms before looping

* Snake movement is implemented using a **simple fixed-delay approach**, prioritizing clarity and correctness over smooth animation.

* The playfield does not use a tile-based map; instead, the snake’s position is updated using direct screen coordinates with wraparound at screen edges.

---

## Compilation & Execution

```bash
cd build
cmake ..
make
./snake
```

---

## Known Limitations

* Movement is **pixel-based and not smoothly animated**
* No input buffering (rapid direction changes may be ignored)
* No score display or difficulty scaling
* Minimal visual effects and UI

These limitations are intentional, as the focus of the project was on understanding SDL2 fundamentals and real-time program structure in C.

---

## Learning Objectives & Takeaways

Through this project, I learned:

* Basics of **SDL2 rendering and window management**
* Event-driven programming and keyboard input handling
* Structure of a **real-time game loop** in C
* Managing game state and simple collision logic
* Debugging graphical applications in a low-level language

---

## Future Improvements

* Delta-time based movement for smoother animation
* Input buffering for better control responsiveness
* Score tracking and UI elements
* Adjustable speed / difficulty levels
* Improved rendering and visual polish

---

## Disclaimer

This project was created **for learning purposes** by a student new to game development and SDL2. The emphasis was on understanding concepts rather than producing a feature-complete game.
