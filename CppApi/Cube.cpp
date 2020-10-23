//
// Created by luca on 23.10.20.
//

#include "Cube.h"

//TODO: Richige Farben einfügen sodass würfel gelöst ist
Cube::Cube() : Cube(WHITE_FACE_SOLVED, GREEN_FACE_SOLVED, RED_FACE_SOLVED,
                    YELLOW_FACE_SOLVED, BLUE_FACE_SOLVED, ORANGE_FACE_SOLVED) {
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

Cube::Cube(unsigned white, unsigned red, unsigned blue, unsigned orange, unsigned green,
           unsigned yellow) : white(white), green(green), red(red), yellow(yellow), blue(blue), orange(orange)
{
    generateFaceArr();
}

Cube::Cube(const Cube &cube) {
    this->white = cube.white;
    this->red = cube.red;
    this->blue = cube.blue;
    this->orange = cube.orange;
    this->green = cube.green;
    this->yellow = cube.yellow;
    this->generateFaceArr();
}

void Cube::setSequence(unsigned i, unsigned seq, unsigned &target) {
    //Alles links der niederwertigsten 3 Bit löschen
    seq = (seq << 29) >> 29;
    //Verschiebung an den Index
    seq = seq << (i * 3);
    //Linken teil des face extrahieren
    unsigned left = target >> ((i+1) * 3) << ((i+1) * 3);
    //rechten teil des face extrahieren. +2 addieren weil int laenge
    unsigned right = 0;
    if( i != 0){
        right = target << ( 2 + ((i+1) * 3) ) >> ( 2 + ((i+1) * 3) );
    }
    //Alle drei teile zusammenfügen
    unsigned result = left | seq | right;
    target = result;
}

unsigned Cube::getSequence(unsigned i, unsigned source) {
    //index geht in dreier schritten voran
    return source << (32 - ((i+1) * 3)) >> (32 - 3);
}

void Cube::generateFaceArr() {
    this->faceArr[WHITE_FACE] = &(this->white);
    this->faceArr[RED_FACE] = &(this->red);
    this->faceArr[BLUE_FACE] = &(this->blue);
    this->faceArr[ORANGE_FACE] = &(this->orange);
    this->faceArr[GREEN_FACE] = &(this->green);
    this->faceArr[YELLOW_FACE] = &(this->yellow);
}

unsigned *Cube::resolveFaceIndex(unsigned i) {
    switch (i) {
        case WHITE_FACE:
            return &(this->white);
        case BLUE_FACE:
            return &(this->blue);
        case RED_FACE:
            return &(this->red);
        case YELLOW_FACE:
            return &(this->yellow);
        case ORANGE_FACE:
            return &(this->orange);
        case GREEN_FACE:
            return &(this->green);
        default:
            return &(this->white);
    }
}



unsigned Cube::getFace(unsigned FACE) {
    return *(this->faceArr[FACE]);
}

void Cube::setFace(unsigned i, unsigned value) {
    *(this->faceArr[i]) = value;
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


bool Cube::operator==(Cube &c) {
    return (c.green == this->green
            && c.red == this->red
            && c.white == this->white
            && c.blue == this->blue
            && c.orange == this->orange
            && c.yellow == this->yellow);
}
