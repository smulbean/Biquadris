#include "coor.h"
#include "block.h"
#include "sblock.h"
#include "board.h"
#include <iostream>
#include <memory>


SBlock::SBlock(std::shared_ptr<Board> base): Block{base} {
    if ((base->charAt(4, 2) == ' ')&&
        (base->charAt(5, 2) == ' ')&&
        (base->charAt(5, 1) == ' ')&&
        (base->charAt(6, 1) == ' ')) {
        phase = 1;
        end = false;
        coordinates[0] = std::make_shared<Coor>(4, 2);
        coordinates[1] = std::make_shared<Coor>(5, 2);
        coordinates[2] = std::make_shared<Coor>(5, 1);
        coordinates[3] = std::make_shared<Coor>(6, 1);
    } else {
        lost = true;
        coordinates[0] = std::make_shared<Coor>(-1, -1);
        coordinates[1] = std::make_shared<Coor>(-1, -1);
        coordinates[2] = std::make_shared<Coor>(-1, -1);
        coordinates[3] = std::make_shared<Coor>(-1, -1);
    }

}

void SBlock::storeold()
{
    for (int i = 0; i < 4; i++)
    {
        arrX[i] = coordinates[i]->x;
        arrY[i] = coordinates[i]->y;
    }
}

void SBlock::rotateCC() {
    storeold();
    if (phase == 1) {
        if ((base->charAt(coordinates[2]->x-1, coordinates[2]->y) == ' ') && (coordinates[2]->x-1 >= 0) && (coordinates[2]->x-1 <=10) &&  
            (base->charAt(coordinates[2]->x-1, coordinates[2]->y-1) == ' ')) {
            coordinates[0]->x = coordinates[1]->x;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[1]->x = coordinates[2]->x;
            coordinates[1]->y = coordinates[2]->y;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x-1;
            coordinates[3]->y = coordinates[1]->y-1;
            phase=4;
            return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[2]->x+1, coordinates[2]->y) == ' ') && (coordinates[2]->x+1 >= 0) && (coordinates[2]->x+1 <=10) &&  
            (base->charAt(coordinates[2]->x-1, coordinates[2]->y+1) == ' ') && (coordinates[2]->x-1 >= 0) && (coordinates[2]->x-1 <=10)){
            coordinates[1]->x = coordinates[3]->x;
            coordinates[1]->y = coordinates[3]->y;

            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[2]->x+1;
            coordinates[3]->y = coordinates[2]->y;
            phase--;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && (coordinates[1]->x-1 >= 0) && (coordinates[1]->x-1 <=10) &&  
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y-1) == ' ')){
            coordinates[3]->x = coordinates[2]->x;
            coordinates[3]->y = coordinates[2]->y;

            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[1]->x = coordinates[2]->x-1;
            coordinates[1]->y = coordinates[2]->y;

            coordinates[0]->x = coordinates[2]->x-1;
            coordinates[0]->y = coordinates[2]->y-1;
            phase--;
            return;
        }
        return;

    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && (coordinates[1]->x+1 >= 0) && (coordinates[1]->x+1 <=10) &&  
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y+1) == ' ') && (coordinates[1]->x-1 >= 0) && (coordinates[1]->x-1 <=10)){
            
            coordinates[2]->x = coordinates[0]->x;
            coordinates[2]->y = coordinates[0]->y;
            
            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[2]->x-1;
            coordinates[3]->y = coordinates[2]->y;
        phase--;
        return;
        }
        return;
    }
}

void SBlock::rotateC(){
    storeold();
    if (phase == 1) {
        if ((base->charAt(coordinates[2]->x-1, coordinates[2]->y) == ' ') && (coordinates[2]->x-1 >= 0) && (coordinates[2]->x-1 <=10) &&  
            (base->charAt(coordinates[2]->x-1, coordinates[2]->y-1) == ' ') ){
            coordinates[3]->x = coordinates[1]->x;
            coordinates[3]->y = coordinates[1]->y;

            coordinates[1]->x = coordinates[2]->x-1;
            coordinates[1]->y = coordinates[2]->y;

            coordinates[0]->x = coordinates[2]->x-1;
            coordinates[0]->y = coordinates[2]->y-1;
            phase++;
            return;
        }
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[2]->x+1, coordinates[2]->y) == ' ') && (coordinates[2]->x+1 >= 0) && (coordinates[2]->x+1 <=10) &&  
            (base->charAt(coordinates[2]->x-1, coordinates[2]->y+1) == ' ') && (coordinates[2]->x-1 >= 0) && (coordinates[2]->x-1 <=10) ) {
            coordinates[1]->x = coordinates[2]->x;
            coordinates[1]->y = coordinates[2]->y;
            
            coordinates[2]->x = coordinates[3]->x;
            coordinates[2]->y = coordinates[3]->y;

            coordinates[0]->x = coordinates[1]->x+1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[2]->x-1;
            coordinates[3]->y = coordinates[2]->y;
            phase++;
            return;
        }
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[1]->x-1, coordinates[1]->y) == ' ') && (coordinates[1]->x-1 >= 0) && (coordinates[1]->x-1 <=10) &&  
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y-1) == ' ')) {
            coordinates[0]->x = coordinates[2]->x;
            coordinates[0]->y = coordinates[2]->y;

            coordinates[2]->x = coordinates[1]->x-1;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[1]->x-1;
            coordinates[3]->y = coordinates[1]->y-1;
            phase++;
            return;
        }
        return;
        
    } else if (phase == 4) {
        if ((base->charAt(coordinates[1]->x+1, coordinates[1]->y) == ' ') && (coordinates[1]->x+1 >= 0) && (coordinates[1]->x+1 <=10) &&  
            (base->charAt(coordinates[1]->x-1, coordinates[1]->y+1) == ' ') && (coordinates[1]->x-1 >= 0) && (coordinates[1]->x-1 <=10) ){
            coordinates[2]->x = coordinates[1]->x;
            coordinates[2]->y = coordinates[1]->y;

            coordinates[1]->x = coordinates[0]->x;
            coordinates[1]->y = coordinates[0]->y;

            coordinates[0]->x = coordinates[1]->x-1;
            coordinates[0]->y = coordinates[1]->y;

            coordinates[3]->x = coordinates[2]->x+1;
            coordinates[3]->y = coordinates[2]->y;
            phase = 1;
            return;
        }
        return;
    }
}

void SBlock::down(){
    storeold();
    if(end) {
        return;
    }

    if((phase == 1 || phase == 4) && (coordinates[0]->y == 17)) { //reached the bottom
        end = true;
        return;
    } else if ((phase == 3 || phase == 2) && (coordinates[3]->y == 17)){
        end = true;
        return;
    }

    if (phase == 1) {
        if ((base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
                (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
                (base->charAt(coordinates[3]->x,coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            return;
        }
        end = true;
        return;

    } else if (phase == 3) {
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

void SBlock::left(){
    storeold();
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 0) {
            return;
        }
    }

    if((phase == 1)&&((base->charAt(coordinates[2]->x-1, coordinates[2]->y) != ' ')||
                    (base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' '))) {
        return;

    } else if((phase == 2)&&((base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[1]->x-1, coordinates[1]->y) != ' ')||
                            (base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((base->charAt(coordinates[1]->x-1, coordinates[1]->y) != ' ')||
                            (base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' '))) {
        return;
    } else if((phase == 4)&&((base->charAt(coordinates[3]->x-1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[2]->x-1, coordinates[2]->y) != ' ')||
                            (base->charAt(coordinates[0]->x-1, coordinates[0]->y) != ' '))) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x--;
    }
    return;
}

void SBlock::right(){
    for(int i = 0; i < 4; i++) {
        if(coordinates[i]->x == 10) {
            return;
        }
    }

    if((phase == 1)&&((base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' ')||
                    (base->charAt(coordinates[1]->x+1, coordinates[1]->y) != ' '))) {
        return;

    } else if((phase == 2)&&((base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[2]->x+1, coordinates[2]->y) != ' ')||
                            (base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' '))) {
        return;

    } else if((phase == 3)&&((base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' ')||
                            (base->charAt(coordinates[2]->x+1, coordinates[2]->y) != ' '))) {
        return;
    } else if((phase == 4)&&((base->charAt(coordinates[3]->x+1, coordinates[3]->y) != ' ')||
                            (base->charAt(coordinates[1]->x+1, coordinates[1]->y) != ' ')||
                            (base->charAt(coordinates[0]->x+1, coordinates[0]->y) != ' '))) {
        return;
    }

    for(int i = 0; i < 4; i++) {
        coordinates[i]->x++;
    }
    return;
}

char SBlock::charAt(int col, int row) {
    for (int i = 0; i<4; i++){
        if((row == coordinates[i]->y) && (col == coordinates[i]->x)){
            return 'S';
        }
    }
    return base->charAt(col, row);
}

void SBlock::drop(){
    storeold();
    while (!end){
        if(end) {
        return;
    }

    if((phase == 1 || phase == 4) && (coordinates[0]->y == 17)) { //reached the bottom
        end = true;
        return;
    } else if ((phase == 3 || phase == 2) && (coordinates[3]->y == 17)){
        end = true;
        return;
    }

    if (phase == 1) {
        if ((base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
                (base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
                (base->charAt(coordinates[3]->x,coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            continue;
        }
        end = true;
        return;

    } else if (phase == 2) {
        if ((base->charAt(coordinates[1]->x, coordinates[1]->y+1) == ' ') && 
            (base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            continue;
        }
        end = true;
        return;

    } else if (phase == 3) {
        if ((base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ') && 
            (base->charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') &&
            (base->charAt(coordinates[3]->x, coordinates[3]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            continue;
        }
        end = true;
        return;
        
    } else if (phase == 4) {
        if ((base->charAt(coordinates[2]->x, coordinates[2]->y+1) == ' ') && 
            (base->charAt(coordinates[0]->x, coordinates[0]->y+1) == ' ')) {
            for (int i=0; i<4; i++){
                coordinates[i]->y++;
            }
            continue;
        }
        end = true;
        return;
    }
    }
    end = true;
    return;
}

bool SBlock::done(){
    return end;
}

void SBlock::clear(int row) {
    storeold();
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

bool SBlock::lose(){
    return lost;
}

bool SBlock::exceeded() {
    for (int i=0; i<4; i++){
        if (this->coordinates[i]->y < 2 && this->coordinates[i]->y > -1){
            return true;
        }
    }
    return false;
}

int SBlock::blockdone(){
    for (int i=0; i<4; i++){
        if (this->coordinates[i]->y != -1 || this->coordinates[i]->x != -1){
            return 0;
        }
    }
    return 1;
}

int SBlock::getX(int num){
    return arrX[num];
}

int SBlock::getY(int num){
    return arrY[num];
}

