//
// Created by luca on 23.10.20.
//

#include "Cube.h"

//TODO: Richige Farben einfügen sodass würfel gelöst ist
Cube::Cube() : Cube(0, 0, 0, 0, 0, 0) {

}

void Cube::setSequence(int i, unsigned seq) {
    //Alles links der niederwertigsten 3 Bit löschen
    seq = (seq << 29) >> 27;
}

char Cube::getSequence(int i) {
    //index geht in dreier schritten voran

    return 0;
}

Cube::Cube(bool valid) : Cube(){
    if(!valid){
        this->white = 0;
        this->blue = 0;
        this->green = 0;
        this->orange = 0;
        this->red = 0;
        this->yellow = 0;
    }
}

Cube::Cube(unsigned white, unsigned green, unsigned red, unsigned yellow, unsigned blue,
           unsigned orange) : white(white), green(green), red(red), yellow(yellow), blue(blue), orange(orange)
{
    generatePointerArray();
}

unsigned[6] Cube::generatePointerArray() {
    this->arr[0] = &(this->white);
    this->arr[1] = &(this->red);
    this->arr[2] = &(this->blue);
    this->arr[3] = &(this->orange);
    this->arr[4] = &(this->green);
    this->arr[5] = &(this->yellow);

}

unsigned Cube::getFace(char i) {
    return *(this->arr[i]);
}

Cube Cube::rotate(int i) {
    switch (i) {
        case 0:
            return this->rotateLeft();
        case 1:
            return this->rotateLeftPrime();
        case 2:
            return this->rotateRight();
        case 3:
            return this->rotateRightPrime();
        case 4:
            return this->rotateUp();
        case 5:
            return this->rotateUpPrime();
        case 6:
            return this->rotateDown();
        case 7:
            return this->rotateDownPrime();
        case 8:
            return this->rotateFront();
        case 9:
            return this->rotateFrontPrime();
        case 10:
            return this->rotateBack();
        case 11:
            return this->rotateBackPrime();
        case 12:
            return this->rotateXSlice();
        case 13:
            return this->rotateXSlicePrime();
        case 14:
            return this->rotateYSlice();
        case 15:
            return this->rotateYSlicePrime();
        case 16:
            return this->rotateZSlice();
        case 17:
            return this->rotateZSlicePrime();
        default:
            return *this;
    }
}


