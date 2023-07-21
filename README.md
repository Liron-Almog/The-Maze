# The Maze - A Puzzle Game
https://github.com/Liron-Almog/The-Maze/assets/100926289/cb254015-2ecf-40dc-b093-88d4a7af7751

## Description
The game's objective is to collect four coins while avoiding enemies that can kill the player. Once the player collects all four coins,
the DFS algorithm will activate and draw the path to the exit door, advancing the player to the next level 
and the player must complete the level before the time runs out. If the time runs out, the level will restart.

## Design Patterns Used

1. Singleton Pattern:
   - `textureGame`, `fontGame`, and `SoundGame` classes are implemented using the Singleton pattern.

2. Command Pattern:
   - The menu system.

3. Observer Pattern:
   - The navbar game uses the Observer pattern.

4. Multimethod Pattern:
   - Used for handling collisions between game entities.

5. Factory Pattern:
   - Implemented to create game objects, such as coins, enemies, and power-ups.
6. Strategy Pattern:
   - Used for object movement in the game.

## How to Play

1. Use the arrow keys to move the player up, down, left, or right.
2. Collect all four coins without getting caught by enemies.
3. Once all coins are collected, the DFS algorithm will draw the path to the exit door.
4. Reach the exit door to advance to the next level.
5. Be mindful of the time limit for each level. When the time runs out, the level restarts.

## Installation

1. Clone this repository.
2. Download the necessary SFML library from their documentation (https://www.sfml-dev.org/download.php) according to your operating system and compiler.
3. Place the downloaded SFML directory in the project's root folder.
4. Compile the C++ code using your compiler, linking it with the SFML library.
5. Run the executable file to start the game.
