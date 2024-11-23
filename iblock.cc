#include "coor.h"
#include "block.h"
#include "iblock.h"
#include "board.h"
#include <iostream>


IBlock::IBlock(Board* base): Block{base} {
    phase = 1;
    coordinates[0] = new Coor(4, 2);
    coordinates[1] = new Coor(5, 2);
    coordinates[2] = new Coor(6, 2);
    coordinates[3] = new Coor(7, 2);

}

IBlock::~IBlock() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void IBlock::rotateCC() {
    for(int i = 0; i<3; i++) {
        rotateC();
    }
    return;
}

void IBlock::rotateC(){
    if (phase == 1) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y-1;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y+1;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y+2;
        phase++;

    } else if (phase == 2) {
        coordinates[0]->x = coordinates[1]->x+1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x-1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x-2;
        coordinates[3]->y = coordinates[1]->y;
        phase++;

    } else if (phase == 3) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y+1;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y-1;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y-2;
        phase++;
        
    } else if (phase == 4) {
        coordinates[0]->x = coordinates[1]->x-1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x+1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x+2;
        coordinates[3]->y = coordinates[1]->y;
        phase = 1;
    }
}

void IBlock::down(){
    for(int i = 0; i < 4; i++) {
        coordinates[i]->y++;
    }

}

void IBlock::left(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 0) {
            return;
        }
    }
    std::cout << "Here" << std::endl;

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void IBlock::right(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 11) {
            return;
        }
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x++;
    }
    return;
}

char IBlock::charAt(int row, int col) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'I';
        }
    }
    return ' ';
}

void IBlock::drop(){
    if (phase == 1) {
        while ((coordinates[0]->y+1 == ' ') && (coordinates[1]->y+1 == ' ') && (coordinates[2]->y+1 == ' ') && (coordinates[3]->y+1 == ' ')) {
            down();
        }
        return;

    } else if (phase == 2) {
        while (coordinates[3]->y+1 == ' '){
            down();
        }
        return;

    } else if (phase == 3) {
        while ((coordinates[0]->y+1 == ' ') && (coordinates[1]->y+1 == ' ') && (coordinates[2]->y+1 == ' ') && (coordinates[3]->y+1 == ' ')) {
            down();
        }
        return;
        
    } else if (phase == 4) {
        while (coordinates[0]->y+1 == ' '){
            down();
        }
        return;
    }

}
