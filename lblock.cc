#include "coor.h"
#include "block.h"
#include "lblock.h"
#include "board.h"
#include <iostream>


LBlock::LBlock(Board* base): Block{base} {
    phase = 1;
    end = false;
    coordinates[0] = new Coor(5, 1);
    coordinates[1] = new Coor(5, 2);
    coordinates[2] = new Coor(4, 2);
    coordinates[3] = new Coor(3, 2);

}

LBlock::~LBlock() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void LBlock::rotateCC() {
    if (phase == 1) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y+2) == ' ')){
            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y+1;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y+2;
            phase++;
            return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') && 
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x-2, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y-1;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x-2;
            coordinates[3]->y = coordinates[1]->y;
            phase = 1;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y-2) == ' ')){
            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y-1;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y-2;
            phase++;
            return;
        }
        return;

    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x+2, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y+1;

            coordinates[2]->x = coordinates[1]->x+1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x+2;
            coordinates[3]->y = coordinates[1]->y;
            phase++;
            return;
        }
        return;
        
    }
}

void LBlock::rotateC(){
    if (phase == 1) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y-2) == ' ')){
            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y-1;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y-2;
            phase++;
            return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x+2, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y+1;

            coordinates[2]->x = coordinates[1]->x+1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x+2;
            coordinates[3]->y = coordinates[1]->y;
            phase++;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y+2) == ' ')){
            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y+1;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y+2;
            phase++;
            return;
        }
        return;
        
    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') && 
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x-2, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y-1;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x-2;
            coordinates[3]->y = coordinates[1]->y;
            phase = 1;
            return;
        }
        return;
    }
}

void LBlock::down(){
    if(end) {
        return;
    }

    if((phase == 1 || phase == 4) && (coordinates[3]->y == 17)) { //reached the bottom
        end = true;
        return;
    } else if ((phase == 3 || phase == 2) && (coordinates[0]->y == 17)){
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
        if ((charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
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
        if ((charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ') && 
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

void LBlock::left(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 1) {
            return;
        }
    }

    if((phase == 1)&&(charAt(coordinates[3]->x-1, coordinates[3]->y) != ' ')) {
        return;

    } else if((phase == 2)&&((charAt(coordinates[2]->x-1, coordinates[2]->y) != ' ')||
                            (charAt(coordinates[1]->x-1, coordinates[1]->y) != ' ')||
                            (charAt(coordinates[3]->x-1, coordinates[3]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((charAt(coordinates[1]->x-1, coordinates[1]->y) != ' ')||
                            (charAt(coordinates[0]->x-1, coordinates[0]->y) != ' '))) {
        return;
    } else if((phase == 4)&&(charAt(coordinates[0]->x-1, coordinates[0]->y) != ' ')) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void LBlock::right(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 10) {
            return;
        }
    }

    if((phase == 1)&&((charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (charAt(coordinates[1]->x+1, coordinates[1]->y) != ' '))) {
        return;

    } else if((phase == 2)&&((charAt(coordinates[2]->x+1, coordinates[2]->y) != ' ')||
                            (charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (charAt(coordinates[3]->x+1, coordinates[3]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((charAt(coordinates[3]->x+1, coordinates[0]->y) != ' ')||
                            (charAt(coordinates[0]->x+1, coordinates[0]->y) != ' '))) {
        return;
    } else if((phase == 4)&&((charAt(coordinates[2]->x+1, coordinates[2]->y) != ' ')||
                            (charAt(coordinates[1]->x+1, coordinates[1]->y) != ' ')||
                            (charAt(coordinates[3]->x+1, coordinates[3]->y) != ' '))) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x++;
    }
    return;
}

char LBlock::charAt(int col, int row) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'L';
        }
    }
    return base->charAt(col, row);
}

void LBlock::drop(){
    while (!end){
        down();
    }
    end = true;
    return;
}

bool LBlock::done(){
    return end;
}
