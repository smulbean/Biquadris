#include "coor.h"
#include "block.h"
#include "blankblock.h"
#include "board.h"
#include <iostream>


BlankBlock::BlankBlock(Board* base): Block{base} {

}

BlankBlock::~BlankBlock() {
    for (int i = 0; i<4 ; i++){
        delete coordinates[i];
    }
}

void BlankBlock::rotateCC() {
}

void BlankBlock::rotateC(){
    
}

void BlankBlock::down(){
    
}

void BlankBlock::left(){
    
}

void BlankBlock::right(){
   
}

char BlankBlock::charAt(int col, int row) {
    return ' ';
}

void BlankBlock::drop(){

}

bool BlankBlock::done(){
    return end;
}