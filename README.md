# 🏰 Dungeon Escape (C++ Console Game)

## 📢 Author's Note
> **Topic:** C++ Arrays (2D) & Game Logic
>
> - 🌏 **I'm not good at English!**
> - 🤖 Gemini only helped me complete the comments and translation.
> - 👨‍💻 **All code is mine, no copy.**
> - ⏱️ This project took me **30min** to complete.

## 📝 About The Project
**Dungeon Escape** is a simple survival puzzle game running on the Console/Terminal.
The goal of this project was to practice **2D Arrays**, coordinate management `(x, y)`, and basic Game Loop logic in C++.

## 🎮 How to Play
You control the character **P** (Player) inside a dark dungeon.
* **Goal:** Reach the **E** (Exit) to win.
* **Danger:** Avoid the **X** (Traps). If you step on them, Game Over.
* **Controls:**
    * `W` : Move Up
    * `S` : Move Down
    * `A` : Move Left
    * `D` : Move Right
    * `Q` : Quit Game

## 🛠️ Tech Stack & Concepts
* **Language:** C++
* **Data Structure:** 2D Array (`map[5][5]`)
* **Logic:**
    * Boundary Checking (Prevent falling off the map).
    * Collision Detection (Check for Traps/Walls).
    * Input Handling (`cin` & `switch-case`).

## 📸 Preview
```text
=== DUNGEON ESCAPE ===
----------------
 P  .  .  X  . 
 .  X  .  .  . 
 .  .  .  X  . 
 X  X  .  X  . 
 .  .  .  X  E 
----------------
Enter move (WASD): ...
