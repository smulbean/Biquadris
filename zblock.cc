#include "coor.h"
#include "block.h"
#include "zblock.h"
#include "board.h"
#include <iostream>


ZBlock::ZBlock(Board* base): Block{base} {
    phase = 1;
    end = false;
    coordinates[0] = new Coor(6, 2);
    coordinates[1] = new Coor(5, 2);
    coordinates[2] = new Coor(5, 1);
    coordinates[3] = new Coor(4, 1);

}

ZBlock::~ZBlock() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void ZBlock::rotateCC() {
    for(int i = 0; i<3; i++) {
        rotateC();
    }
    return;
}

void ZBlock::rotateC(){
    if (phase == 1) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y+1;

        coordinates[2]->x = coordinates[1]->x+1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x+1;
        coordinates[3]->y = coordinates[1]->y-1;
        phase++;

    } else if (phase == 2) {
        coordinates[0]->x = coordinates[1]->x-1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y+1;

        coordinates[3]->x = coordinates[1]->x+1;
        coordinates[3]->y = coordinates[1]->y+1;
        phase++;

    } else if (phase == 3) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y-1;

        coordinates[2]->x = coordinates[1]->x-1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x-1;
        coordinates[3]->y = coordinates[1]->y+1;
        phase++;
        
    } else if (phase == 4) {
        coordinates[0]->x = coordinates[1]->x+1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y-1;

        coordinates[3]->x = coordinates[1]->x-1;
        coordinates[3]->y = coordinates[1]->y-1;
        phase = 1;
    }
}

void ZBlock::down(){
    if(end) {
        return;
    }

    if(coordinates[0]->y == 17) { //reached the bottom
        end = true;
        return;
    }

    if (phase == 1) {
        if ((charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
                (charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
                (charAt(coordinates[3]->x,coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 2) {
        if ((charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
            (charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 3) {
        if ((charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
            (charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') &&
            (charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;
        
    } else if (phase == 4) {
        if ((charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ') && 
            (charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;
    }
}

void ZBlock::left(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 1) {
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void ZBlock::right(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 10) {
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x++;
    }
    return;
}

char ZBlock::charAt(int col, int row) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'Z';
        }
    }
    return ' ';
}

void ZBlock::drop(){
    while (!end){
        down();
    }
    end = true;
    return;
}

bool ZBlock::done(){
    return end;
}
