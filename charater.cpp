#include "charater.h"

// the state of character
enum {STOP = 0, MOVE, ATK, HIT};
typedef struct character
{
    float x, y; // the position of image
    float vx, vy;
    int width, height; // the width and height of image
    bool dir; // left: false, right: true
    int state; // the state of character
    ALLEGRO_BITMAP *img_move;
    ALLEGRO_SAMPLE_INSTANCE *atk_Sound;
    int health;
    bool hidden;
    int anime;
    int anime_time;
    int hit;
}character;
void draw_moveable_object(character);
void Health_Check(character);
character chara;
character missile[50];
character missile2[50];
character Enemy[50];
character Enemy_Missile[500];
character missile3[50];
character SeiHaiKun;
ALLEGRO_TIMER *Timer = NULL;
ALLEGRO_SAMPLE *sample = NULL;
ALLEGRO_SAMPLE *sample2 = NULL;
ALLEGRO_SAMPLE *sample3 = NULL;
void character_init(){
    // load character images
    int i;
    chara.img_move = al_load_bitmap("./image/char_move_1.png");
    // load effective sound
    sample = al_load_sample("./sound/missile.mp3");
    chara.atk_Sound  = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(chara.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(chara.atk_Sound, al_get_default_mixer());

    // initial the geometric information of character
    chara.width = al_get_bitmap_width(chara.img_move);
    chara.height = al_get_bitmap_height(chara.img_move);
    if(active_scene == SCENE_START){
    chara.x = WIDTH2/2;
    chara.y = HEIGHT2-154;
    }
    else if(active_scene == SCENE_START3){
        chara.x = WIDTH3/2;
        chara.y = HEIGHT3-154;
    }
    chara.dir = false;
    chara.health = mainchara_health;
    chara.vx = 0;
    chara.vy = 0;
    chara.anime = 0;
    chara.anime_time = 30;
    chara.state = STOP;

    SeiHaiKun.img_move = al_load_bitmap("./image/Seihaikun_Resized.png");
    sample2 = al_load_sample("./sound/Seihaikun_Hit.wav");
    SeiHaiKun.atk_Sound  = al_create_sample_instance(sample2);
    al_set_sample_instance_playmode(SeiHaiKun.atk_Sound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(SeiHaiKun.atk_Sound, al_get_default_mixer());
    SeiHaiKun.width = al_get_bitmap_width(SeiHaiKun.img_move);
    SeiHaiKun.height = al_get_bitmap_height(SeiHaiKun.img_move);
    SeiHaiKun.vx = 3;
    SeiHaiKun.vy = 0;
    SeiHaiKun.x = WIDTH3/2;
    SeiHaiKun.y = SeiHaiKun.height;
    if(active_scene == SCENE_START) SeiHaiKun.hidden = true;
    else if(active_scene == SCENE_START3) SeiHaiKun.hidden = false;
    SeiHaiKun.health = 100;
    // initial the animation component
    for(int i = 0; i < MAX_ENEMY; i++){
            Enemy[i].x =(rand()%WIDTH2)+1;
			Enemy[i].y = 80;
			Enemy[i].img_move = al_load_bitmap("./image/resized.png");
			Enemy[i].width = al_get_bitmap_width(Enemy[i].img_move);
			Enemy[i].height = al_get_bitmap_height(Enemy[i].img_move);
			Enemy[i].health = (rand()%5)+1;
			Enemy[i].vx = ((rand()%20)+5);
			if(active_scene == SCENE_START){
			Enemy[i].hidden = false;
			}
			else if(active_scene == SCENE_START3){
                Enemy[i].hidden == true;
			}

    }
    for (i=0;i<MAX_MISSILE;i++) {
            missile[i].img_move = al_load_bitmap("./image/image_bullet_1.png");
			missile[i].width = al_get_bitmap_width(missile[i].img_move);
			missile[i].height = al_get_bitmap_height(missile[i].img_move);
			missile[i].vx = 0;
			missile[i].vy = -5;
			missile[i].hidden = true;
			missile[i].health = 1;
		}
    for (i=0;i<MAX_MISSILE2;i++) {
            missile2[i].img_move = al_load_bitmap("./image/image_bullet_1.png");
			missile2[i].width = al_get_bitmap_width(missile2[i].img_move);
			missile2[i].height = al_get_bitmap_height(missile2[i].img_move);
			missile2[i].vx = 0;
			missile2[i].vy = -5;
			missile2[i].hidden = true;
			missile2[i].health = 1;
		}
    for (i=0;i<MAX_MISSILE2;i++) {
            missile3[i].img_move = al_load_bitmap("./image/image_bullet_1.png");
			missile3[i].width = al_get_bitmap_width(missile3[i].img_move);
			missile3[i].height = al_get_bitmap_height(missile3[i].img_move);
			missile3[i].vx = 0;
			missile3[i].vy = -5;
			missile3[i].hidden = true;
			missile3[i].health = 1;
		}
    for(i = 0; i < MAX_ENEMY_MISSILE; i++){
        Enemy_Missile[i].img_move = al_load_bitmap("./image/image_bullet_flipped.png");
        Enemy_Missile[i].width = al_get_bitmap_width(Enemy_Missile[i].img_move);
        Enemy_Missile[i].height = al_get_bitmap_height(Enemy_Missile[i].img_move);
        if(active_scene == SCENE_START){
        Enemy_Missile[i].y = -17;
        Enemy_Missile[i].x = (rand()%WIDTH2)+1;
        Enemy_Missile[i].vx = (rand()%5)+1;
        Enemy_Missile[i].vy = (rand()%5)+1;
        }
        else if(active_scene == SCENE_START3){
            Enemy_Missile[i].y = SeiHaiKun.y;
            Enemy_Missile[i].x = SeiHaiKun.x;
            Enemy_Missile[i].vx = ((rand()%60)+10)/10;
            Enemy_Missile[i].vy = ((rand()%60)+20)/10;
        }
        Enemy_Missile[i].hidden = false;
        Enemy_Missile[i].health = 1;
        Enemy_Missile[i].hit = 0;
    }


}
void charater_process(ALLEGRO_EVENT event){
    if( event.type == ALLEGRO_EVENT_KEY_DOWN ){
        key_state[event.keyboard.keycode] = true;
    }else if( event.type == ALLEGRO_EVENT_KEY_UP ){
        key_state[event.keyboard.keycode] = false;
    }
}
void charater_update(){
    // use the idea of finite state machine to deal with different state
    chara.vx = chara.vy = 0;
    double now = al_get_time();
    if( key_state[ALLEGRO_KEY_W]|| key_state[ALLEGRO_KEY_UP]){
        chara.vy = -2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_A] || key_state[ALLEGRO_KEY_LEFT]){
        chara.dir = false;
        chara.vx = -2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_S]|| key_state[ALLEGRO_KEY_DOWN]){
        chara.vy = 2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_D]|| key_state[ALLEGRO_KEY_RIGHT]){
        chara.dir = true;
        chara.vx = 2;
        chara.state = MOVE;
    }
    else if( key_state[ALLEGRO_KEY_SPACE] && now - last_shoot_timestamp >= MAX_COOLDOWN){
        chara.state = ATK;
        int i;
        for ( i=0;i<4;i++) {
            //printf("%d", chara.x);
				if (missile[i].hidden )
				break;
			}
			if (i == MAX_MISSILE)
				return;
			last_shoot_timestamp = now;
			missile[i].hidden = false;
			missile[i].x = chara.x;
			missile[i].y = chara.y-0.71;
    }
    else if(chara.anime == chara.anime_time-1){
        chara.anime = 0;
        chara.state = STOP;
    }
    else if(chara.anime == 0) chara.state = STOP;
        chara.y += chara.vy * 4 * (chara.vx ? 0.71f : 1);
		chara.x += chara.vx * 4 * (chara.vy ? 0.71f : 1);
		if (chara.x-(chara.width)/2 < 0)
			chara.x = (chara.width)/2 ;
		else if (chara.x+(chara.width)/2 > WIDTH2)
			chara.x = WIDTH2-(chara.width)/2 ;
		if (chara.y-(chara.height)/2  < 0)
			chara.y =(chara.height)/2 ;
		else if (chara.y+(chara.height)/2 > HEIGHT2)
			chara.y = HEIGHT2-(chara.height)/2;
        for (int i=0;i<MAX_MISSILE;i++) {
			if (missile[i].hidden)
				continue;
			missile[i].x += missile[i].vx;
			missile[i].y += missile[i].vy;
			for(int j = 0; j <= MAX_ENEMY; j++){
                    if(missile[i].y >= Enemy[j].y-150 && missile[i].y <= Enemy[j].y && Enemy[j].health > 0){
                            if(missile[i].x <= Enemy[j].x+75 && missile[i].x >= Enemy[j].x-75 ){
                                missile[i].hidden = true;
                                Score++;
                                Enemy[j].health --;
                                //printf("%d", Score);
                                    if(Enemy[j].health == 0) {
                                        Enemy[j].hidden = true;
                                        counter++;
                                        //printf("%d", counter);
                                        }
                            }
                    }
			}
			if (missile[i].y  < 0 )
				missile[i].hidden = true;
			}
		for( int i = 0; i < MAX_ENEMY;i++){
            int flag = (rand()%2)+1;
            if(flag == 1){
                Enemy[i].x += Enemy[i].vx*1;
                Enemy[i].x +=0;
                Enemy[i].x -= Enemy[i].vx*1;
                Enemy[i].x -= 0;
                Enemy[i].x += Enemy[i].vx*1;
                if(Enemy[i].x >= WIDTH2){
                    Enemy[i].x -=Enemy[i].vx*2;
                }
                else if(Enemy[i].x <= 0){
                    Enemy[i].x += Enemy[i].vx*2;
                }
            }
            else{
                Enemy[i].x -= Enemy[i].vx*1;
                Enemy[i].x -= 0;
                Enemy[i].x += Enemy[i].vx*1;
                Enemy[i].x +=0;
                Enemy[i].x -= Enemy[i].vx*1;
                if(Enemy[i].x >= WIDTH2){
                    Enemy[i].x -=Enemy[i].vx*2;
                }
                else if(Enemy[i].x <= 0){
                    Enemy[i].x += Enemy[i].vx*2;
                }
            }
		}
		for(int i = 0; i < MAX_ENEMY_MISSILE2+1; i++){
                Enemy_Missile[i].y+=Enemy_Missile[i].vy;
                if(Enemy_Missile[i].x >= chara.x -65 && Enemy_Missile[i].x <= chara.x+65 && Enemy_Missile[i].hit == 0){
                    if(Enemy_Missile[i].y >= chara.y-50&&Enemy_Missile[i].y <= chara.y+50){
                        Enemy_Missile[i].hit = 1;
                        Enemy_Missile[i].hidden = true;
                        if(chara.state == ATK)chara.health -= 10;
                        else chara.health -=10;
                        //printf("%d", chara.health);
                        mainchara_health = chara.health;
                    }
                }
            }
		for(int i = 0; i < MAX_ENEMY_MISSILE2+1; i++){
            if(Enemy_Missile[i].y > HEIGHT2){
                Enemy_Missile[i].hidden = false;
                Enemy_Missile[i].hit = 0;
                Enemy_Missile[i].y = -17;
                Enemy_Missile[i].x = (rand()%WIDTH2)+1;
                Enemy_Missile[i].vy =(rand()%3)+1;
            }
		}
}
void charater_update_2()
{
    // use the idea of finite state machine to deal with different state
    chara.vx = chara.vy = 0;
    double now = al_get_time();
    if( key_state[ALLEGRO_KEY_W]|| key_state[ALLEGRO_KEY_UP]){
        chara.vy = -2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_A] || key_state[ALLEGRO_KEY_LEFT]){
        chara.dir = false;
        chara.vx = -2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_S]|| key_state[ALLEGRO_KEY_DOWN]){
        chara.vy = 2;
        chara.state = MOVE;
    }else if( key_state[ALLEGRO_KEY_D]|| key_state[ALLEGRO_KEY_RIGHT]){
        chara.dir = true;
        chara.vx = 2;
        chara.state = MOVE;
    }
     if( key_state[ALLEGRO_KEY_SPACE] && now - last_shoot_timestamp >= MAX_COOLDOWN){
        chara.state = ATK;
        int i;
        for ( i=0;i<MAX_MISSILE2+1;i++) {
            //printf("%d", chara.x);
				if (missile3[i].hidden )
				break;
				else if (missile2[i].hidden )
				break;
				}
			if (i == MAX_MISSILE2)
				return;
			last_shoot_timestamp = now;
			missile3[i].hidden = false;
			missile2[i].hidden = false;
			missile3[i].x = chara.x-30;
			missile2[i].x = chara.x + 30;
			missile3[i].y = chara.y-0.71;
			missile2[i].y = chara.y-0.71;
    }
    else if(chara.anime == chara.anime_time-1){
        chara.anime = 0;
        chara.state = STOP;
    }
    else if(chara.anime == 0) chara.state = STOP;
        chara.y += chara.vy * 4 * (chara.vx ? 0.71f : 1);
		chara.x += chara.vx * 4 * (chara.vy ? 0.71f : 1);
		if (chara.x-(chara.width)/2 < 0)
			chara.x = (chara.width)/2 ;
		else if (chara.x+(chara.width)/2 > WIDTH3)
			chara.x = WIDTH3-(chara.width)/2 ;
		if (chara.y-(chara.height)/2  < 0)
			chara.y =(chara.height)/2 ;
		else if (chara.y+(chara.height)/2 > HEIGHT3)
			chara.y = HEIGHT3-(chara.height)/2;
        for (int i=0;i<MAX_MISSILE2+1;i++) {
			if (missile3[i].hidden)
				continue;
			missile3[i].x += missile3[i].vx;
			missile3[i].y += missile3[i].vy;
                    if(missile3[i].y >= SeiHaiKun.y-SeiHaiKun.height/2 && missile3[i].y <= SeiHaiKun.y+SeiHaiKun.height/2 && SeiHaiKun.health > 0){
                            if(missile3[i].x <= SeiHaiKun.x+SeiHaiKun.width/2 && missile3[i].x >= SeiHaiKun.x-(SeiHaiKun.width/2) ){
                                missile3[i].hidden = true;
                                al_play_sample_instance(SeiHaiKun.atk_Sound);
                                Score+=5;
                                SeiHaiKun.health --;
                                SeiHaiKun_Health = SeiHaiKun.health;
                                //printf("%d ", Score);
                                    if(SeiHaiKun.health == 0) {
                                        Score+=10000;
                                        SeiHaiKun.hidden = true;
                                        BOSS = true;
                                        }
                    }

			}
			if (missile3[i].y  < 0 )
				missile3[i].hidden = true;
			}
			for (int i=0;i<MAX_MISSILE2;i++) {
			if (missile2[i].hidden)
				continue;
			missile2[i].x += missile2[i].vx;
			missile2[i].y += missile2[i].vy;
                    if(missile2[i].y >= SeiHaiKun.y-SeiHaiKun.height/2 && missile2[i].y <= SeiHaiKun.y+SeiHaiKun.height/2 && SeiHaiKun.health > 0){
                            if(missile2[i].x <= SeiHaiKun.x+SeiHaiKun.width/2 && missile2[i].x >= SeiHaiKun.x-(SeiHaiKun.width/2) ){
                                missile2[i].hidden = true;
                                al_play_sample_instance(SeiHaiKun.atk_Sound);
                                Score +=5;
                                SeiHaiKun.health --;
                                SeiHaiKun_Health = SeiHaiKun.health;
                                //printf("%d ", Score);
                                    if(SeiHaiKun.health == 0) {
                                        Score+=10000;
                                        SeiHaiKun.hidden = true;
                                        BOSS = true;
                                        }
                    }

			}
			if (missile2[i].y  < 0 )
				missile2[i].hidden = true;
			}
            for(int i = 0; i < MAX_ENEMY_MISSILE+1; i++){
                if(i%2 == 0){
                Enemy_Missile[i].y += Enemy_Missile[i].vy-1;
                Enemy_Missile[i].x += Enemy_Missile[i].vx-1;
                }
                else{
                Enemy_Missile[i].y += Enemy_Missile[i].vy-1;
                Enemy_Missile[i].x -= Enemy_Missile[i].vx-1;
                }
                if(Enemy_Missile[i].x >= chara.x -65 && Enemy_Missile[i].x <= chara.x+65 && Enemy_Missile[i].hit == 0){
                    if(Enemy_Missile[i].y >= chara.y-50&&Enemy_Missile[i].y <= chara.y+50){
                        Enemy_Missile[i].hit = 1;
                        Enemy_Missile[i].hidden = true;
                        if(chara.state == ATK)chara.health -=10;
                        else chara.health -=10;
                        //printf("%d", chara.health);
                        mainchara_health = chara.health;
                        if(mainchara_health == 0){
                            BOSS = true;
                        }
                    }
			}
			for(int i = 0; i < MAX_ENEMY_MISSILE+1; i++){
            if(Enemy_Missile[i].y >= HEIGHT3||Enemy_Missile[i].y <= 0||Enemy_Missile[i].x <= 0||Enemy_Missile[i].x >= WIDTH3){
                Enemy_Missile[i].hidden = false;
                Enemy_Missile[i].hit = 0;
                Enemy_Missile[i].y = SeiHaiKun.y;
                Enemy_Missile[i].x = SeiHaiKun.x;
                Enemy_Missile[i].vy =((rand()%60)+20)/10;
                Enemy_Missile[i].vx =((rand()%60)+10)/10;
		}
			}
            }
            if(now - time1 >= 20)SeiHaiKun.x += SeiHaiKun.vx;
            if(SeiHaiKun.x == WIDTH3 || SeiHaiKun.x == 0) {
                    int temp =  SeiHaiKun.vx;
                    SeiHaiKun.vx = temp*(-1);
            }
            if(now - time1 >= 100)SeiHaiKun.vx = 5;
            if(now - time1 >= 180   ) BOSS = true;
            if(BOSS == true){
                double end_time = al_get_time();
                time2 = end_time;
                time_bonus = (int)((time2 -time1));
            }
}

void character_draw(){
    // with the state, draw corresponding image
		int i;
		for (i=0;i<MAX_MISSILE;i++){
			draw_moveable_object(missile[i]);
		}
		for(i = 0; i < MAX_MISSILE2;i++){
			draw_moveable_object(missile2[i]);
			draw_moveable_object(missile3[i]);
		}
		draw_moveable_object(chara);
		for (i = 0; i < MAX_ENEMY; i++)
			draw_moveable_object(Enemy[i]);
        if( chara.state == ATK ){
        {
            al_play_sample_instance(chara.atk_Sound);
            }
        }
        for(i = 0; i < MAX_ENEMY_MISSILE;i++){
            draw_moveable_object(Enemy_Missile[i]);
        }
        draw_moveable_object(SeiHaiKun);
}
void character_destory(){
    al_destroy_bitmap(chara.img_move);
    al_destroy_bitmap(SeiHaiKun.img_move);
    for(int i = 0; i <50; i++){
        al_destroy_bitmap(Enemy[i].img_move);
        al_destroy_bitmap(Enemy_Missile[i].img_move);
        al_destroy_bitmap(missile2[i].img_move);
        al_destroy_bitmap(missile3[i].img_move);
        al_destroy_bitmap(missile[i].img_move);
    }
    al_destroy_sample_instance(chara.atk_Sound);
    al_destroy_sample_instance(SeiHaiKun.atk_Sound);
}
void draw_moveable_object(character obj) {
	if (obj.hidden){
		return;}
	al_draw_bitmap(obj.img_move, round(obj.x - obj.width / 2), round(obj.y - obj.height / 2), 0);
}
