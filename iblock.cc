#include "coor.h"
#include "block.h"

IBlock() {
    phase = 1;
    Coor[0] = new Coor(4, 2);
    Coor[1] = new Coor(5, 2);
    Coor[2] = new Coor(6, 2);
    Coor[3] = new Coor(7, 2);

}

~IBlock() {
    Coor.clear();
}

void rotateCC() {
    for(int i = 0; i<3; i++) {
        rotate();
    }
    return;
}

void rotateC(){
    if (phase == 1) {
        Coor[0]->x = Coor[1].x;
        Coor[0]->y = Coor[1].y-1;

        Coor[2]->x = Coor[1].x;
        Coor[2]->y = Coor[1].y+1;

        Coor[3]->x = Coor[1].x;
        Coor[3]->y = Coor[1].y+2;
        phase++;

    } else if (phase == 2) {
        Coor[0]->x = Coor[1].x+1;
        Coor[0]->y = Coor[1].y;

        Coor[2]->x = Coor[1].x-1;
        Coor[2]->y = Coor[1].y;

        Coor[3]->x = Coor[1].x-2;
        Coor[3]->y = Coor[1].y;
        phase++;

    } else if (phase == 3) {
        Coor[0]->x = Coor[1].x;
        Coor[0]->y = Coor[1].y+1;

        Coor[2]->x = Coor[1].x;
        Coor[2]->y = Coor[1].y-1;

        Coor[3]->x = Coor[1].x;
        Coor[3]->y = Coor[1].y-2;
        phase++;
        
    } else if (phase == 4) {
        Coor[0]->x = Coor[1].x-1;
        Coor[0]->y = Coor[1].y;

        Coor[2]->x = Coor[1].x+1;
        Coor[2]->y = Coor[1].y;

        Coor[3]->x = Coor[1].x+2;
        Coor[3]->y = Coor[1].y;
        phase = 1;
    }
}

void down(){
    for(int i = 0; i < 4; i++) {
        Coor[i]->y++;
    }

}

void left(){
    for(int i = 0; i < 4; i++) {
        if(Coor[i]->x == 0) {
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        Coor[i]->x--;
    }
    return;
}

void right(){
    for(int i = 0; i < 4; i++) {
        if(Coor[i]->x == 11) {
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        Coor[i]->x--;
    }
    return;
}

char charAt(int row, int col) override {
    for (int i = 0; i<4; i++){
        if((row == Coor[i]->y) && (col == Coor[i]->x)){
            return 'I';
        }
    }
    return ' ';
}

void drop(){
    if (phase == 1) {
        while (Coor[0]->y+1 == ' ') && (Coor[1]->y+1 == ' ') && (Coor[2]->y+1 == ' ') && (Coor[3]->y+1 == ' ') {
            down();
        }
        return;

    } else if (phase == 2) {
        while (Coor[3]->y+1 == ' '){
            down();
        }
        return;

    } else if (phase == 3) {
        while (Coor[0]->y+1 == ' ') && (Coor[1]->y+1 == ' ') && (Coor[2]->y+1 == ' ') && (Coor[3]->y+1 == ' ') {
            down();
        }
        return;
        
    } else if (phase == 4) {
        while (Coor[0]->y+1 == ' '){
            down();
        }
        return;
    }

}
