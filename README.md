# Space Shooting Game on Allegro
## Introduction
This is a shooting game that is, even though under the filename of .cpp, by C programming and Allegro game development library.The concept behind the game is straightforward. By creating various in-game objects such as airplanes, missiles, and bosses, the Allegro system facilitated interactions between these objects and the player's actions, dynamically refreshing the canvas within the game window. The game comprises two stages, three distinct difficulty levels, and incorporates features like a scoreboard. Players have the capability to maneuver the in-game character using keyboard inputs. By employing agile character movements to evade obstacles and eliminating adversaries through missile attacks, the game system records a final score on the scoreboard. This scoreboard enables players to assess their individual performance in this session against the previous records achieved by other players.

## Dependencies
Allegro version 5.2.0

![Allegro-logo](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/7044c18a-6881-4d99-9402-096742f56bc4)

CodeBlocks 20.03

![Cb_splash](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/20cfd25a-740f-4cc2-9bcf-666d1cae226e)


## Build
`final_project.cpp` is the project file for the whole game.

`character.cpp` and `character.h` include the logic, interaction and properties of every object in the game.

`GameWindow.cpp` and `GameWindow.h` include the orders and the condition that the game is drawing on the canvas of the game window.

`global.cpp` and `global.h` contain the universal properties that are often being used in the game.

`scene.cpp` and `scene.h` include all the logic that reacts to player's operation.

## Run

Method I
1. Open the Project File with Code Block
   
![螢幕擷取畫面 2023-09-08 172555](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/afb77fd1-6c23-4ecd-af1f-b9d65634621f)

2. Compile
   
![螢幕擷取畫面 2023-09-08 173325](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/bbc85e5f-be66-465e-acb7-f06b9f01f1dc)

The full installation process are shown in `Allegro_turorial.pdf`.

Method II (Windows OS only)

Directly Execute `final_project.exe

![螢幕擷取畫面 2023-09-08 195350](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/2d5e655e-bacf-442d-8390-ee09e05ffa93)

## Expected Results
Home Screen

![螢幕擷取畫面 2023-09-08 173755](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/18737b1d-6eb1-4f29-9fc1-892ce969db8f)

First Stage

![螢幕擷取畫面 2023-09-08 173851](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/f761bca2-26f3-4ee5-8bf0-0bfb0ac11bdf)

Boss Stage

![螢幕擷取畫面 2023-09-08 174033](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/38b39dce-1744-4949-9b87-65e62695bf75)

Score Board

![螢幕擷取畫面 2023-09-08 174130](https://github.com/EZHsu/Allegro_Shooting_Game/assets/101862861/c1a1f900-d500-4f4a-a364-17c11fbf4a56)
