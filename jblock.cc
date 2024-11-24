#include "coor.h"
#include "block.h"
#include "JBLOCK.h"
#include "board.h"
#include <iostream>


JBLOCK::JBLOCK(Board* base): Block{base} {
    phase = 1;
    end = false;
    coordinates[0] = new Coor(5, 1);
    coordinates[1] = new Coor(5, 2);
    coordinates[2] = new Coor(6, 2);
    coordinates[3] = new Coor(7, 2);

}

JBLOCK::~JBLOCK() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void JBLOCK::rotateCC() {
    for(int i = 0; i<3; i++) {
        rotateC();
    }
    return;
}

void JBLOCK::rotateC(){
    if (phase == 1) {
        coordinates[0]->x = coordinates[1]->x+1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y+1;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y+2;
        phase++;

    } else if (phase == 2) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y+1;

        coordinates[2]->x = coordinates[1]->x-1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x-2;
        coordinates[3]->y = coordinates[1]->y;
        phase++;

    } else if (phase == 3) {
        coordinates[0]->x = coordinates[1]->x-1;
        coordinates[0]->y = coordinates[1]->y;

        coordinates[2]->x = coordinates[1]->x;
        coordinates[2]->y = coordinates[1]->y-1;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y-2;
        phase++;
        
    } else if (phase == 4) {
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y-1;

        coordinates[2]->x = coordinates[1]->x+1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x+2;
        coordinates[3]->y = coordinates[1]->y;
        phase = 1;
    }
}

void JBLOCK::down(){
    if(end) {
        return;
    }

    if(coordinates[0]->y == 17) { //reached the bottom
        end = true;
        return;
    }

    if (phase == 1) {
        if ((charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') && 
            (charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 2) {
        if ((charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ') && 
            (charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ')) {
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
        if ((charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;
    }
}

void JBLOCK::left(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 1) {
            return;
        }
    }
    std::cout << "Here" << std::endl;

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void JBLOCK::right(){
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

char JBLOCK::charAt(int col, int row) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'J';
        }
    }
    return ' ';
}

void JBLOCK::drop(){
    while (!end){
        down();
    }
    end = true;
    return;
}

bool JBLOCK::done(){
    return end;
}
