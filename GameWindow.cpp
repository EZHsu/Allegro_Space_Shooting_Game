#include "GameWindow.h"

bool draw = false;

const char *title = "Final Project";

// ALLEGRO Variables
ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_SAMPLE *song=NULL;
ALLEGRO_SAMPLE *song2=NULL;
ALLEGRO_SAMPLE *song3=NULL;
ALLEGRO_SAMPLE *song4=NULL;
ALLEGRO_SAMPLE *song5=NULL;
ALLEGRO_SAMPLE *song6=NULL;
ALLEGRO_SAMPLE *song7=NULL;
ALLEGRO_SAMPLE *song8=NULL;
ALLEGRO_SAMPLE_INSTANCE *sample_instance;
ALLEGRO_SAMPLE_INSTANCE *sample_instance2;
ALLEGRO_SAMPLE_INSTANCE *Transition;
ALLEGRO_SAMPLE_INSTANCE *Final_Stage;
ALLEGRO_SAMPLE_INSTANCE *Scoreboard;
ALLEGRO_SAMPLE_INSTANCE *Failed;
ALLEGRO_SAMPLE_INSTANCE *TimeUp;
ALLEGRO_SAMPLE_INSTANCE *Victory;

int Game_establish() {
    int msg = 0;
    game_init();
    game_begin();

    while ( msg != GAME_TERMINATE ) {
        msg = game_run();
        if ( msg == GAME_TERMINATE )
            printf( "Game Over\n" );
    }

    game_destroy();
    return 0;
}

void game_init() {
    printf( "Game Initializing...\n" );
    al_init();
    // init audio
    al_install_audio();
    al_init_acodec_addon();
    // Create display
    display = al_create_display(WIDTH, HEIGHT);
    // create event queue
    event_queue = al_create_event_queue();
    // Initialize Allegro settings
    al_set_window_position(display, 0, 0);
    al_set_window_title(display, title);
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon
    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event
    // Register event
    al_register_event_source(event_queue, al_get_display_event_source( display ));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    fps  = al_create_timer( 1.0 / FPS );
    al_register_event_source(event_queue, al_get_timer_event_source( fps )) ;
    // initialize the icon on the display
    ALLEGRO_BITMAP *icon = al_load_bitmap("./image/icon.png");
    al_set_display_icon(display, icon);
    mainchara_health = 500;
}

void game_begin() {
    // Load sound
    song = al_load_sample("./sound/Login.mp3");
    song2= al_load_sample("./sound/Battle.mp3");
    song3 = al_load_sample("./sound/Transition.mp3");
    song4 = al_load_sample("./sound/Finals.mp3");
    song5 = al_load_sample("./sound/Scoreboard.mp3");
    song6 = al_load_sample("./sound/Failed.mp3");
    song7 = al_load_sample("./sound/TimeUp.mp3");
    song8 = al_load_sample("./sound/Victory.mp3");
    al_reserve_samples(20);
    sample_instance = al_create_sample_instance(song);
    sample_instance2 = al_create_sample_instance(song2);
    Transition  = al_create_sample_instance(song3);
    Final_Stage = al_create_sample_instance(song4);
    Scoreboard = al_create_sample_instance(song5);
    Failed = al_create_sample_instance(song6);
    TimeUp = al_create_sample_instance(song7);
    Victory = al_create_sample_instance(song8);
    // Loop the song until the display closes
    al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
    // set the volume of instance
    al_set_sample_instance_gain(sample_instance, 1) ;
    al_play_sample_instance(sample_instance);
    al_start_timer(fps);
    // initialize the menu before entering the loop
    menu_init();

}
void game_update(){
    if(draw){
    if( judge_next_window == 1){
        if( active_scene == SCENE_MENU ){
            // not back menu anymore, therefore destroy it
            active_scene = SCENE_START;
            menu_destroy();
            // initialize next scene
            game_scene_init();
            al_resize_display(display,WIDTH2, HEIGHT2);
            al_stop_sample_instance(sample_instance);
            al_set_sample_instance_playmode(sample_instance2, ALLEGRO_PLAYMODE_LOOP);
            al_attach_sample_instance_to_mixer(sample_instance2, al_get_default_mixer());
            al_set_sample_instance_gain(sample_instance2, 1) ;
            al_play_sample_instance(sample_instance2);
            judge_next_window = 0;
        }
    }
    if(active_scene == SCENE_MENU&&game_control == 2&&judge_next_window == 5){
        game_Scoreboard_init();
        al_stop_sample_instance(sample_instance);
        al_set_sample_instance_playmode(Scoreboard, ALLEGRO_PLAYMODE_LOOP);
        al_attach_sample_instance_to_mixer(Scoreboard, al_get_default_mixer());
        al_set_sample_instance_gain(Scoreboard,1);
        al_play_sample_instance(Scoreboard);
        active_scene = SCENE_SCOREBOARD;
        judge_next_window = 0;
        game_control = 0;
    }
    if( active_scene == SCENE_START && mainchara_health > 0){
        charater_update();
            if(counter == MAX_ENEMY){
                counter = 0;
                game_scene2_init();
                active_scene = SCENE_START2;
                al_stop_sample_instance(sample_instance2);
                al_set_sample_instance_playmode(Transition, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(Transition, al_get_default_mixer());
                al_set_sample_instance_gain(Transition, 1) ;
                al_play_sample_instance(Transition);
            }
            else if(mainchara_health == 0){
                Score += 2*time_bonus;
                if(diff_flag == 1) History_Score1[100] = Score;
                else if(diff_flag == 2) History_Score2[100] = Score;
                else if(diff_flag == 3) History_Score3[100] = Score;
                game_scene2_init();
                mainchara_health = 500;
                active_scene = SCENE_FAIL;
                al_stop_sample_instance(sample_instance2);
                al_set_sample_instance_playmode(Failed, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(Failed, al_get_default_mixer());
                al_set_sample_instance_gain(Failed, 1) ;
                al_play_sample_instance(Failed);
            }
        }
    if(active_scene == SCENE_START2){
        if(judge_next_window == 2 && mainchara_health > 0){
                // not back menu anymore, therefore destroy it
            active_scene = SCENE_START3;
            game_scene_destroy();
            // initialize next scene
            game_scene3_init();
            al_resize_display(display,WIDTH3,HEIGHT3);
            al_stop_sample_instance(Transition);
            al_set_sample_instance_playmode(Final_Stage, ALLEGRO_PLAYMODE_LOOP);
            al_attach_sample_instance_to_mixer(Final_Stage, al_get_default_mixer());
            al_set_sample_instance_gain(Final_Stage, 1) ;
            al_play_sample_instance(Final_Stage);
            judge_next_window = 0;
            }
        }
    if(active_scene == SCENE_START3 && mainchara_health > 0){
            charater_update_2();
                    if(mainchara_health <= 0){
                        Score += 2*time_bonus+mainchara_health;
                        if(diff_flag == 1) History_Score1[100] = Score;
                        else if(diff_flag == 2) History_Score2[100] = Score;
                        else if(diff_flag == 3) History_Score3[100] = Score;
                        game_scene2_init();
                        mainchara_health = 500;
                        time_bonus = 0;
                        SeiHaiKun_Health = 1000;
                        al_resize_display(display,WIDTH2,HEIGHT2);
                        active_scene = SCENE_FAIL;
                        al_stop_sample_instance(Final_Stage);
                        al_set_sample_instance_playmode(Failed, ALLEGRO_PLAYMODE_LOOP);
                        al_attach_sample_instance_to_mixer(Failed, al_get_default_mixer());
                        al_set_sample_instance_gain(Failed, 1) ;
                        al_play_sample_instance(Failed);
                    }
                    else if(SeiHaiKun_Health <= 0){
                        Score += 2*time_bonus+mainchara_health;
                        if(diff_flag == 1) History_Score1[100] = Score;
                        else if(diff_flag == 2) History_Score2[100] = Score;
                        else if(diff_flag == 3) History_Score3[100] = Score;
                        game_scene2_init();
                        mainchara_health = 500;
                        time_bonus = 0;
                        SeiHaiKun_Health = 1000;
                        al_resize_display(display,WIDTH2,HEIGHT2);
                        active_scene = SCENE_VICTORY;
                        al_stop_sample_instance(Final_Stage);
                        al_set_sample_instance_playmode(Victory, ALLEGRO_PLAYMODE_LOOP);
                        al_attach_sample_instance_to_mixer(Victory, al_get_default_mixer());
                        al_set_sample_instance_gain(Victory, 1) ;
                        al_play_sample_instance(Victory);
                    }
                    else if(time_bonus >= 180){
                        Score += 2*time_bonus+mainchara_health;
                        //printf("%d %d %lf %lf", Score, time_bonus, time2, time1);
                        if(diff_flag == 1) History_Score1[100] = Score;
                        else if(diff_flag == 2) History_Score2[100] = Score;
                        else if(diff_flag == 3) History_Score3[100] = Score;
                        game_scene2_init();
                        mainchara_health = 50;
                        time_bonus = 0;
                        SeiHaiKun_Health = 1000;
                        al_resize_display(display,WIDTH2,HEIGHT2);
                        active_scene = SCENE_TIMEUP;
                        al_stop_sample_instance(Final_Stage);
                        al_set_sample_instance_playmode(TimeUp, ALLEGRO_PLAYMODE_LOOP);
                        al_attach_sample_instance_to_mixer(TimeUp, al_get_default_mixer());
                        al_set_sample_instance_gain(TimeUp, 1) ;
                        al_play_sample_instance(TimeUp);
                }
        }
        if(active_scene == SCENE_FAIL){
            if(judge_next_window == 5){
                game_Scoreboard_init();
                al_resize_display(display, WIDTH, HEIGHT);
                al_stop_sample_instance(Failed);
                al_set_sample_instance_playmode(Scoreboard, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(Scoreboard, al_get_default_mixer());
                al_set_sample_instance_gain(Scoreboard,1);
                al_play_sample_instance(Scoreboard);
                active_scene = SCENE_SCOREBOARD;
                judge_next_window = 0;
            }
        }
        if(active_scene == SCENE_VICTORY){
            if(judge_next_window==5){
                game_Scoreboard_init();
                al_resize_display(display, WIDTH, HEIGHT);
                al_stop_sample_instance(Victory);
                al_set_sample_instance_playmode(Scoreboard, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(Scoreboard, al_get_default_mixer());
                al_set_sample_instance_gain(Scoreboard,1);
                al_play_sample_instance(Scoreboard);
                active_scene = SCENE_SCOREBOARD;
                judge_next_window = 0;
            }
        }
        if(active_scene == SCENE_TIMEUP){
            if(judge_next_window == 5){
                game_Scoreboard_init();
                al_resize_display(display, WIDTH, HEIGHT);
                al_stop_sample_instance(TimeUp);
                al_set_sample_instance_playmode(Scoreboard, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(Scoreboard, al_get_default_mixer());
                al_set_sample_instance_gain(Scoreboard,1);
                al_play_sample_instance(Scoreboard);
                active_scene = SCENE_SCOREBOARD;
                judge_next_window = 0;
            }
        }
        if(active_scene == SCENE_SCOREBOARD){
            if(judge_next_window == 1){
                menu_init();
                al_stop_sample_instance(Scoreboard);
                al_set_sample_instance_playmode(sample_instance, ALLEGRO_PLAYMODE_LOOP);
                al_attach_sample_instance_to_mixer(sample_instance, al_get_default_mixer());
                al_set_sample_instance_gain(sample_instance,1);
                al_play_sample_instance(sample_instance);
                judge_next_window = 0;
                active_scene = SCENE_MENU;
                judge_next_window = 0;
            }
        }
    }
}

int process_event(){
    // Request the event
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    // process the event of other component
    if( active_scene == SCENE_MENU ){
        menu_process(event);
    }else if( active_scene == SCENE_START){
        charater_process(event);
    }
    else if(active_scene == SCENE_START2){
        game_scene2_process(event);
    }
    else if(active_scene == SCENE_FAIL){
        game_Failed_process(event);
    }
    else if(active_scene == SCENE_START3){
        charater_process(event);
    }
    else if(active_scene == SCENE_SCOREBOARD){
        game_Scoreboard_process(event);
    }
    else if(active_scene == SCENE_VICTORY){
        game_Victory_process(event);
    }
    else if(active_scene == SCENE_TIMEUP){
        game_TimeUp_process(event);
    }
    // Shutdown our program
    if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || judge_next_window == 3)
        return GAME_TERMINATE;
    else if(event.type == ALLEGRO_EVENT_TIMER)
        if(event.timer.source == fps)
            draw = true;
    game_update();
    return 0;
}
void game_draw(){
    if( active_scene == SCENE_MENU ){
        menu_draw();
    }else if( active_scene == SCENE_START ){
        game_scene_draw();
    }
    else if(active_scene == SCENE_START2){
        game_scene2_draw();
    }
    else if(active_scene == SCENE_FAIL){
        game_Failed_draw();
    }
    else if(active_scene == SCENE_START3){
        game_scene3_draw();
    }
    else if(active_scene == SCENE_SCOREBOARD){
        game_Scoreboard_draw();
    }
    else if(active_scene == SCENE_VICTORY){
        game_Victory_draw();
    }
    else if(active_scene == SCENE_TIMEUP){
        game_TimeUp_draw();
    }
    al_flip_display();
}
int game_run() {
    int error = 0;
    if( draw ){
        game_draw();
        draw = false;
    }
    if ( !al_is_event_queue_empty(event_queue) ) {
        error = process_event();
    }
    return error;
}

void game_destroy() {
    // Make sure you destroy all things
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_sample(song);
    al_destroy_sample(song2);
    al_destroy_sample(song3);
    al_destroy_sample(song4);
    al_destroy_sample(song5);
    al_destroy_sample(song6);
    game_scene_destroy();
}
