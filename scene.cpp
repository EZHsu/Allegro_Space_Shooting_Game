#include "scene.h"

ALLEGRO_FONT *font = NULL;
ALLEGRO_FONT *font_BIG = NULL;
ALLEGRO_FONT *font_Med;
ALLEGRO_BITMAP *background = NULL;
int key_position = 0;



// function of menu
void menu_init(){
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
    font_BIG = al_load_ttf_font("./font/pirulen.ttf",45,0);
    font_Med = al_load_ttf_font("./font/pirulen.ttf",25,0);
    background = al_load_bitmap("./image/Background.jpg");
}
void menu_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_UP )
        if(event.keyboard.keycode == ALLEGRO_KEY_DOWN){
                key_position ++;
                //printf("%d %d %d %d %d\n",MAX_ENEMY_MISSILE, MAX_ENEMY_MISSILE2, MAX_ENEMY, key_position, game_control);
                if(key_position > 3) key_position = 0;
                }
        else if(event.keyboard.keycode == ALLEGRO_KEY_UP){
                key_position --;
                if(key_position < 0) key_position = 3;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_ENTER && key_position == 0 && game_control == 0){
            judge_next_window = 1;
            key_position = 1;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_ENTER && key_position == 1 &&game_control == 0){
            judge_next_window = 0;
            game_control = 1;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_ENTER && key_position == 2 && game_control == 0){
            judge_next_window = 0;
            game_control = 2;
            key_position = 0;
        }
        else if( event.keyboard.keycode == ALLEGRO_KEY_ENTER && key_position == 3 && game_control == 0){
            judge_next_window = 3;
            key_position = 0;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_SPACE && game_control == 1){
                game_control = 0;
                menu_draw();
            }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE && game_control == 2){
            game_control = 0;
            key_position = 0;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER && game_control == 2 && key_position ==0){
            judge_next_window = 0;
            MAX_ENEMY_MISSILE = 200;
            MAX_ENEMY_MISSILE2 = 50;
            MAX_ENEMY = 10;
            diff_flag = 3;
            game_control = 0;
            menu_draw();
            //printf("%d %d %d\n", MAX_ENEMY_MISSILE, MAX_ENEMY_MISSILE2, MAX_ENEMY);
        }
        else if(event.keyboard.keycode== ALLEGRO_KEY_ENTER && game_control == 2 && key_position == 1){
            judge_next_window = 0;
            MAX_ENEMY_MISSILE = 100;
            MAX_ENEMY_MISSILE2 = 20;
            MAX_ENEMY = 10;
            diff_flag = 2;
            game_control = 0;
            menu_draw();
            //printf("%d %d %d\n", MAX_ENEMY_MISSILE, MAX_ENEMY_MISSILE2, MAX_ENEMY);
        }
        else if(event.keyboard.keycode== ALLEGRO_KEY_ENTER&& game_control == 2 && key_position == 2){
            MAX_ENEMY_MISSILE = 50;
            judge_next_window = 0;
            MAX_ENEMY_MISSILE2 = 10;
            MAX_ENEMY = 10;
            diff_flag = 1;
            game_control = 0;
            menu_draw();
        }
        else if(event.keyboard.keycode== ALLEGRO_KEY_ENTER&& game_control == 2 && key_position == 3){
            judge_next_window = 5;
            game_control = 2;
        }
}
void game_scene2_process(ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE){
                judge_next_window = 2;
                double time_now = al_get_time();
                time1 = time_now;
        }
    }
}
void menu_draw(){
    al_draw_bitmap(background,0,0,0);
    al_draw_text(font_BIG, al_map_rgb(255, 0, 0), WIDTH/2, HEIGHT-800, ALLEGRO_ALIGN_CENTRE, "FINAL PROJECT");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT - 700 , ALLEGRO_ALIGN_CENTRE, "Press Enter to Select");
    al_draw_filled_rectangle(WIDTH/2-150, HEIGHT/2 + 200, WIDTH/2+150, HEIGHT/2+240, al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+210 , ALLEGRO_ALIGN_CENTRE, "Start The Game");
    al_draw_filled_rectangle(WIDTH/2 - 150, HEIGHT/2 + 280, WIDTH/2 + 150, HEIGHT/2 + 320, al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+290 , ALLEGRO_ALIGN_CENTRE, "Game Control&Intro");
    al_draw_filled_rectangle(WIDTH/2 - 150, HEIGHT/2 + 360, WIDTH/2 + 150, HEIGHT/2 + 400, al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+370 , ALLEGRO_ALIGN_CENTRE, "Difficulty");
    al_draw_filled_rectangle(WIDTH/2 - 150, HEIGHT/2 + 440, WIDTH/2 + 150, HEIGHT/2 + 480, al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+450, ALLEGRO_ALIGN_CENTRE, "Quit");
    if(game_control == 0){
    if(key_position == 0) al_draw_line(WIDTH/2-100, HEIGHT/2+230, WIDTH/2+100, HEIGHT/2+230, al_map_rgb(255,0,0), 0);
    if(key_position == 1) al_draw_line(WIDTH/2-100, HEIGHT/2+310, WIDTH/2+100, HEIGHT/2+310, al_map_rgb(255,0,0), 0);
    if(key_position == 2) al_draw_line(WIDTH/2-100, HEIGHT/2+390, WIDTH/2+100, HEIGHT/2+390, al_map_rgb(255,0,0), 0);
    if(key_position == 3) al_draw_line(WIDTH/2-100, HEIGHT/2+470, WIDTH/2+100, HEIGHT/2+470, al_map_rgb(255,0,0), 0);
    }
    if(game_control == 1){
        al_draw_filled_rectangle(WIDTH/2 - 150, HEIGHT/2 + 200, WIDTH/2 +150, HEIGHT/2 +600, al_map_rgb(0,0,0));
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+220 , ALLEGRO_ALIGN_CENTRE, "W/UP = Move Upward");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+240 , ALLEGRO_ALIGN_CENTRE, "A/LEFT = Move Left");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+260 , ALLEGRO_ALIGN_CENTRE, "S/DOWN = Move Downward");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+280 , ALLEGRO_ALIGN_CENTRE, "D/RIGHT = Move Right");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+300 , ALLEGRO_ALIGN_CENTRE, "Space = Fire Missiles");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+440 , ALLEGRO_ALIGN_CENTRE, "Press Space to Go Back");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+340 , ALLEGRO_ALIGN_CENTRE, "Score = 2xSeconds");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+360 , ALLEGRO_ALIGN_CENTRE,"in Front of SeiHaiKun+ Bullet Hit");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+380 , ALLEGRO_ALIGN_CENTRE," + Health if Survived");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT - 600 , ALLEGRO_ALIGN_CENTRE, "Game Control");
    }
    if(game_control == 2){
        al_draw_filled_rectangle(WIDTH/2 - 150, HEIGHT/2 + 200, WIDTH/2 +150, HEIGHT/2 +600, al_map_rgb(0,0,0));
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+210 , ALLEGRO_ALIGN_CENTRE, "Hard");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+290 , ALLEGRO_ALIGN_CENTRE, "Normal");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+370 , ALLEGRO_ALIGN_CENTRE, "Easy");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT/2+450 , ALLEGRO_ALIGN_CENTRE, "Scoreboard");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT - 600 , ALLEGRO_ALIGN_CENTRE, "Difficulty");
        al_draw_text(font, al_map_rgb(255,0,0), WIDTH/2, HEIGHT - 650 , ALLEGRO_ALIGN_CENTRE, "Press ESC to Leave");
    }
    if(game_control == 2){
        if(key_position == 0) al_draw_line(WIDTH/2-100, HEIGHT/2+230, WIDTH/2+100, HEIGHT/2+230, al_map_rgb(255,0,0),0);
        if(key_position == 1) al_draw_line(WIDTH/2-100, HEIGHT/2+310, WIDTH/2+100, HEIGHT/2+310, al_map_rgb(255,0,0),0);
        if(key_position == 2) al_draw_line(WIDTH/2-100, HEIGHT/2+390, WIDTH/2+100, HEIGHT/2+390, al_map_rgb(255,0,0),0);
        if(key_position == 3) al_draw_line(WIDTH/2-100, HEIGHT/2+470, WIDTH/2+100, HEIGHT/2+470, al_map_rgb(255,0,0),0);
    }
}
void menu_destroy(){
    al_destroy_font(font);
}

// function of game_scene
void game_scene_init(){
    character_init();

    background = al_load_bitmap("./image/stage.jpg");
}
void game_scene_draw(){
    al_draw_bitmap(background, 0, 0, 0);
    character_draw();
    al_flip_display();
    al_draw_filled_rectangle(WIDTH2 - HEALTH_BAR, 0 ,WIDTH2,30, al_map_rgb(255,0,0));
    al_draw_rectangle(WIDTH2 - 500, 0 ,WIDTH2,30, al_map_rgb(0,0,0), 5);
    al_draw_filled_rectangle(WIDTH2-HEALTH_BAR-5, 0, WIDTH2-mainchara_health,30, al_map_rgb(0,0,0));
}
void game_scene2_draw()
{
    al_draw_filled_rectangle(0, 0, WIDTH2, HEIGHT2, al_map_rgb(0,0,0));
    al_draw_text(font_BIG, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2/2, ALLEGRO_ALIGN_CENTRE, "GET READY FOR THE BOSS");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2 -80, ALLEGRO_ALIGN_CENTRE, "Now You Got Upgraded Missiles but You're Facing the Strongest Opponent");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2-20, ALLEGRO_ALIGN_CENTRE, "Press Space to Continue");
}
void game_scene2_init()
{
    font = al_load_ttf_font("./font/pirulen.ttf",12,0);
}
void game_scene_destroy(){
    al_destroy_bitmap(background);
    character_destory();
}
void game_Failed_draw()
{
    al_draw_filled_rectangle(0, 0, WIDTH2, HEIGHT2, al_map_rgb(0,0,0));
    al_draw_text(font_BIG, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2/2, ALLEGRO_ALIGN_CENTRE, "YOU DIED");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2-20, ALLEGRO_ALIGN_CENTRE, "Press Space to Continue");
}
void game_Failed_process(ALLEGRO_EVENT event)
{
     if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                judge_next_window = 5;
                //printf("%d\n", Score);
        }
    }
}
void game_scene3_draw()
{
    al_draw_bitmap(background, 0, 0, 0);
    character_draw();
    al_flip_display();
    al_draw_filled_rectangle(WIDTH3 - HEALTH_BAR, 0 ,WIDTH3,30, al_map_rgb(255,0,0));
    al_draw_rectangle(WIDTH3 - 500, 5 ,WIDTH3,30, al_map_rgb(0,0,0), 5);
    al_draw_filled_rectangle(WIDTH3-HEALTH_BAR-5, 0, WIDTH3-mainchara_health,30, al_map_rgb(0,0,0));
}
void game_scene3_init()
{
    character_init();
    background = al_load_bitmap("./image/Stage_Boss.jpg");
    al_flip_display();

}
void game_Scoreboard_process(ALLEGRO_EVENT event)
{
     if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
            judge_next_window = 3;
        }
        else if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
            judge_next_window = 1;
        }
     }
}
int cmpfunc (const void * a, const void * b);
void game_Scoreboard_draw()
{
    if(diff_flag == 1){
    qsort(History_Score1, 105, sizeof(int), cmpfunc);
    al_draw_filled_rectangle(0,0, WIDTH, HEIGHT,al_map_rgb(0,166,0));
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2,HEIGHT/2+360,ALLEGRO_ALIGN_CENTRE, "Press Enter to Go Back to Main Menu");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+320, ALLEGRO_ALIGN_CENTRE,"Press ESC to End");
    al_draw_text(font_BIG, al_map_rgb(255,255,255), WIDTH/2, 50, ALLEGRO_ALIGN_CENTRE, "E     Z");
    for(int i = 0; i < 10; i++){
        al_draw_textf(font_Med, al_map_rgb(255,255,255), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score1[i]);
        if(Score == History_Score1[i]&&Score != 0){
            al_draw_textf(font_Med, al_map_rgb(255,0,0), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score1[i]);
        }
        Score == 0;
        }
    FILE *pFile1;
    pFile1 = fopen("History_Record1.txt", "w");
    fwrite(History_Score1, sizeof(int), 105, pFile1);
    fclose(pFile1);
    }
    else if(diff_flag == 2){
    qsort(History_Score2, 105, sizeof(int), cmpfunc);
    FILE *pFile2;
    pFile2 = fopen("History_Record2.txt", "w");
    al_draw_filled_rectangle(0,0, WIDTH, HEIGHT,al_map_rgb(0,166,0));
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2,HEIGHT/2+360,ALLEGRO_ALIGN_CENTRE, "Press Enter to Go Back to Main Menu");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+320, ALLEGRO_ALIGN_CENTRE,"Press ESC to End");
    al_draw_text(font_BIG, al_map_rgb(255,255,255), WIDTH/2, 50, ALLEGRO_ALIGN_CENTRE, "NO     ML");
    for(int i = 0; i < 10; i++){
        al_draw_textf(font_Med, al_map_rgb(255,255,255), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score2[i]);
        if(Score == History_Score2[i]&&Score != 0){
        al_draw_textf(font_Med, al_map_rgb(255,0,0), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score2[i]);
        }
        Score == 0;}
    fwrite(History_Score2, sizeof(int), 105, pFile2);
    fclose(pFile2);
    }
    if(diff_flag == 3){
    FILE *pFile3;
    pFile3 = fopen("History_Record3.txt", "w");
    qsort(History_Score3, 105, sizeof(int), cmpfunc);
    al_draw_filled_rectangle(0,0, WIDTH, HEIGHT,al_map_rgb(0,166,0));
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2,HEIGHT/2+360,ALLEGRO_ALIGN_CENTRE, "Press Enter to Go Back to Main Menu");
    al_draw_text(font, al_map_rgb(255,255,255), WIDTH/2, HEIGHT/2+320, ALLEGRO_ALIGN_CENTRE,"Press ESC to End");
    al_draw_text(font_BIG, al_map_rgb(255,255,255), WIDTH/2, 50, ALLEGRO_ALIGN_CENTRE, "HA     RD");
    for(int i = 0; i < 10; i++){
        al_draw_textf(font_Med, al_map_rgb(255,255,255), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score3[i]);
        if(Score == History_Score3[i]&& Score != 0){
            al_draw_textf(font_Med, al_map_rgb(255,0,0), WIDTH/2, 50+80*(i), ALLEGRO_ALIGN_CENTRE, "%d. %d", i+1, History_Score3[i]);
        }
        Score == 0;}
    fwrite(History_Score3, sizeof(int), 105, pFile3);
    fclose(pFile3);
    }
}

void game_Scoreboard_init()
{

}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)b - *(int*)a );
}
void game_TimeUp_draw()
{
    al_draw_filled_rectangle(0, 0, WIDTH2, HEIGHT2, al_map_rgb(0,0,0));
    al_draw_text(font_BIG, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2/2, ALLEGRO_ALIGN_CENTRE, "TIME'S UP");
    al_draw_text(font, al_map_rgb(255,0,0), WIDTH2/2, HEIGHT2-20, ALLEGRO_ALIGN_CENTRE, "Press Space to Continue");
}
void game_TimeUp_process(ALLEGRO_EVENT event)
{
     if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE) judge_next_window = 5;
    }
}
void game_Victory_draw()
{
al_draw_filled_rectangle(0, 0, WIDTH2, HEIGHT2, al_map_rgb(255,0,0));
    al_draw_text(font_BIG, al_map_rgb(255,255,0), WIDTH2/2, HEIGHT2/2, ALLEGRO_ALIGN_CENTRE, "VICTORY");
    al_draw_text(font, al_map_rgb(255,255,0), WIDTH2/2, HEIGHT2-20, ALLEGRO_ALIGN_CENTRE, "Press Space to Continue");
}
void game_Victory_process(ALLEGRO_EVENT event)
{
     if(event.type == ALLEGRO_EVENT_KEY_UP){
        if(event.keyboard.keycode == ALLEGRO_KEY_SPACE) judge_next_window = 5;
    }
}
