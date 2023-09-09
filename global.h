#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED
#define GAME_TERMINATE -1
#define MAX_MISSILE 3
#define MAX_MISSILE2 10
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <math.h>

// note that you can't assign initial value here!
extern const float FPS;
extern const int WIDTH;
extern const int HEIGHT;
extern const int WIDTH2;
extern const int HEIGHT2;
extern const int WIDTH3;
extern const int HEIGHT3;
extern int HEALTH_BAR;
extern int killcount;
extern bool key_state[ALLEGRO_KEY_MAX];
extern int judge_next_window;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *fps;
extern int Score;
extern const float MAX_COOLDOWN;
extern const int SCENE_MENU, SCENE_SETTINGS, SCENE_START,SCENE_START2,SCENE_START3,SCENE_SCOREBOARD,SCENE_FAIL, SCENE_VICTORY, SCENE_TIMEUP ;
extern double last_shoot_timestamp;
extern double last_shoot_timestamp2;
extern int counter;
extern int active_scene;
extern const float MAX_COOLDOWN2;
extern int mainchara_health;
extern bool BOSS;
extern int History_Score1[105];
extern int History_Score2[105];
extern int History_Score3[105];
extern int time_bonus;
extern double time1;
extern double time2;
extern int MAX_ENEMY_MISSILE;
extern int MAX_ENEMY_MISSILE2;
extern int MAX_ENEMY;
extern int SeiHaiKun_Health;
extern int diff_flag;
extern int game_control;
#endif
