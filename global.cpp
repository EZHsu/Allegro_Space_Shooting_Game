#include "global.h"

// variables for global usage
const float FPS = 60.0;
const int WIDTH = 516;
const int HEIGHT = 1000;
const int WIDTH2 = 1300;
const int HEIGHT2 = 550;
const int WIDTH3 = 1200;
const int HEIGHT3 = 900;
int HEALTH_BAR = 500;
int killcount = 0;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *fps = NULL;
bool key_state[ALLEGRO_KEY_MAX] = {false};
int judge_next_window = 0;
int Score = 0;
const float MAX_COOLDOWN = 0.2;
const float MAX_COOLDOWN2 = 3;
double last_shoot_timestamp;
double last_shoot_timestamp2 = 6;
const int	SCENE_MENU = 1,
	SCENE_START = 2,
    SCENE_START2 = 3,
	SCENE_START3 = 4,
	SCENE_SCOREBOARD = 5,
    SCENE_FAIL = 6,
    SCENE_TIMEUP = 7,
    SCENE_VICTORY =8;
int counter = 0;
int active_scene = SCENE_MENU;
int mainchara_health;
bool BOSS = false;
int History_Score1[105];
int History_Score2[105];
int History_Score3[105];
int time_bonus = 0;
double time1;
double time2;
int MAX_ENEMY_MISSILE2;
int MAX_ENEMY_MISSILE;
int MAX_ENEMY;
int SeiHaiKun_Health = 100;
int diff_flag;
int game_control = 0;
