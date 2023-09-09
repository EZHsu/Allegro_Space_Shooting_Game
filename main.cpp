#include "GameWindow.h"

int main(){
    MAX_ENEMY_MISSILE2 = 20;
    MAX_ENEMY_MISSILE = 100;
    MAX_ENEMY = 10;
    diff_flag = 2;
    FILE *Input1 = fopen("History_Record1.txt","r");
    FILE *Input2 = fopen("History_Record2.txt","r");
    FILE *Input3 = fopen("History_Record3.txt","r");
    for(int i = 0; i < 105; i++){
        fread(&History_Score1[i], sizeof(int), 105,Input1);
        fread(&History_Score2[i], sizeof(int), 105,Input2);
        fread(&History_Score3[i], sizeof(int), 105,Input3);
    }
    fclose(Input1);
    fclose(Input2);
    fclose(Input3);
    Game_establish();
}
