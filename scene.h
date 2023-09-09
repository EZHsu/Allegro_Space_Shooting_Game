#include "global.h"
#include "charater.h"

void menu_init();
void menu_process(ALLEGRO_EVENT event);
void menu_draw();
void menu_destroy();

void game_scene_init();
void game_scene_draw();
void game_scene_destroy();

void game_scene2_init();
void game_scene2_draw();
void game_scene2_process(ALLEGRO_EVENT event);

void game_scene3_init();
void game_scene3_draw();
void game_scene3_process(ALLEGRO_EVENT event);

void game_Failed_init();
void game_Failed_draw();
void game_Failed_process(ALLEGRO_EVENT event);

void game_Scoreboard_init();
void game_Scoreboard_draw();
void game_Scoreboard_process(ALLEGRO_EVENT event);

void game_Victory_init();
void game_Victory_draw();
void game_Victory_process(ALLEGRO_EVENT event);

void game_TimeUp_init();
void game_TimeUp_draw();
void game_TimeUp_process(ALLEGRO_EVENT event);
