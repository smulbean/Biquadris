#include "coor.h"
#include "block.h"
#include "tblock.h"
#include "board.h"
#include <iostream>


TBlock::TBlock(Board* base): Block{base} {
    phase = 1;
    end = false;
    coordinates[0] = new Coor(4, 2);
    coordinates[1] = new Coor(5, 2);
    coordinates[2] = new Coor(5, 3);
    coordinates[3] = new Coor(6, 2);

}

TBlock::~TBlock() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void TBlock::rotateCC() {
    if (phase == 1) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ')){
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y+1;

        coordinates[2]->x = coordinates[1]->x+1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y-1;
        phase=4;
        return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') &&
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y+1;

            coordinates[3]->x = coordinates[1]->x+1;
            coordinates[3]->y = coordinates[1]->y;
            phase--;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') && 
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y-1;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y+1;
            phase--;
            return;
        }
        return;

    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') &&
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y-1;

            coordinates[3]->x = coordinates[1]->x-1;
            coordinates[3]->y = coordinates[1]->y;
            phase--;
            return;
        }
        return;
        
    }
}

void TBlock::rotateC(){
    if (phase == 1) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') && 
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ')){
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y-1;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y+1;
            phase++;
            return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ') &&
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y-1;

            coordinates[3]->x = coordinates[1]->x-1;
            coordinates[3]->y = coordinates[1]->y;
            phase++;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') &&
            (base->charAt(coordinates[1]->x, coordinates[1]->y-1) == ' ')){
        coordinates[0]->x = coordinates[1]->x;
        coordinates[0]->y = coordinates[1]->y+1;

        coordinates[2]->x = coordinates[1]->x+1;
        coordinates[2]->y = coordinates[1]->y;

        coordinates[3]->x = coordinates[1]->x;
        coordinates[3]->y = coordinates[1]->y-1;
        phase++;
        return;
        }
        return;
        
    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') &&
            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ')){
            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y+1;

            coordinates[3]->x = coordinates[1]->x+1;
            coordinates[3]->y = coordinates[1]->y;
            phase = 1;
            return;
        }
        return;
    }
}

void TBlock::down(){
    if(end) {
        return;
    }

    if((phase == 1) && (coordinates[2]->y == 17)) { //reached the bottom
        end = true;
        return;
    } else if ((phase == 2) && (coordinates[3]->y == 17)) {
        end = true;
        return;
    } else if ((phase == 3 || phase == 4) && (coordinates[0]->y == 17)){
        end = true;
        return;
    }

    if (phase == 1) {
        if ((base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
            (base->charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') && 
            (base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ') && 
            (base->charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
            (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;
        
    } else if (phase == 4) {
        if ((base->charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') && 
            (base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;
    }
}

void TBlock::left(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 0) {
            return;
        }
    }

    if((phase == 1)&&((base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[2]->x-1, coordinates[2]->y) != ' '))) {
        return;

    } else if((phase == 2)&&((base->charAt(coordinates[2]->x-1, coordinates[2]->y) != ' ')||
                            (base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[2]->x-1, coordinates[2]->y) != ' '))) {
        return;
    } else if((phase == 4)&&((base->charAt(coordinates[1]->x-1, coordinates[1]->y) != ' ')||
                            (base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' '))) {
        return;
    }


    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void TBlock::right(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 10) {
            return;
        }
    }

    if((phase == 1)&&((base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[2]->x+1, coordinates[2]->y) != ' '))) {
        return;

    } else if((phase == 2)&&((base->charAt(coordinates[1]->x+1, coordinates[1]->y) != ' ')||
                            (base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[2]->x+1, coordinates[2]->y) != ' '))) {
        return;
    } else if((phase == 4)&&((base->charAt(coordinates[2]->x+1, coordinates[2]->y) != ' ')||
                            (base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' '))) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x++;
    }
    return;
}

char TBlock::charAt(int col, int row) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'T';
        }
    }
    return base->charAt(col, row);
}

void TBlock::drop(){
    while (!end){
        down();
    }
    end = true;
    return;
}

bool TBlock::done(){
    return end;
}


void TBlock::clear(int row) {
    for (int i=0; i<4; i++){
        if (this->coordinates[i]->y == row){
            this->coordinates[i]->x = -1;
            this->coordinates[i]->y = -1;
            continue;
        } else if (this->coordinates[i]->y < row){
            this->coordinates[i]->y++;
            continue;
        }
    }
    return;
}

bool TBlock::lose(){
    return lost;
}
