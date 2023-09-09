# Space Shooting Game on Allegro
## Introduction
This is a shooting game that is, even though under the filename of .cpp, by C programming and Allegro game development library.The concept behind the game is straightforward. By creating various in-game objects such as airplanes, missiles, and bosses, the Allegro system facilitated interactions between these objects and the player's actions, dynamically refreshing the canvas within the game window. The game comprises two stages, three distinct difficulty levels, and incorporates features like a scoreboard. Players have the capability to maneuver the in-game character using keyboard inputs. By employing agile character movements to evade obstacles and eliminating adversaries through missile attacks, the game system records a final score on the scoreboard. This scoreboard enables players to assess their individual performance in this session against the previous records achieved by other players.

## Dependencies
Allegro version 5.2.0

![Allegro-logo](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/7ef13d9d-4db1-4a7a-be4b-a34ed20c8f67)

CodeBlocks 20.03

![Cb_splash](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/ef8c20cc-6135-4f40-a732-7ba24315d185)

## Build
`final_project.cpp` is the project file for the whole game.

`character.cpp` and `character.h` include the logic, interaction and properties of every object in the game.

`GameWindow.cpp` and `GameWindow.h` include the orders and the condition that the game is drawing on the canvas of the game window.

`global.cpp` and `global.h` contain the universal properties that are often being used in the game.

`scene.cpp` and `scene.h` include all the logic that reacts to player's operation.

## Run

Method I
1. Open the Project File with Code Block

![螢幕擷取畫面 2023-09-08 172555](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/6320b5ff-9335-4e66-88d2-570bef7a5197)

2. Compile
   
![螢幕擷取畫面 2023-09-08 173325](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/13cf6a2f-b242-48c0-a4b8-1da715c81ee7)

The full installation process are shown in `Allegro_turorial.pdf`.

Method II (Windows OS only)

Directly Execute `final_project.exe`

![螢幕擷取畫面 2023-09-08 195350](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/774063a2-cc15-4081-a84f-dea376b4547b)

## Expected Results
Home Screen

![螢幕擷取畫面 2023-09-08 173755](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/1dc53f8a-85a4-49d2-af89-ba92319ee835)

First Stage

![螢幕擷取畫面 2023-09-08 173851](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/e937e738-ac9a-443f-b987-9fa906baa4de)

Boss Stage

![螢幕擷取畫面 2023-09-08 174033](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/baa5c01d-0376-4f2f-ada5-8b7b4842312e)

Score Board

![螢幕擷取畫面 2023-09-08 174130](https://github.com/EZHsu/Allegro_Space_Shooting_Game/assets/101862861/9c45525a-d707-4228-85d0-b0f339b11f3f)
