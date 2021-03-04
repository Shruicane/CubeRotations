//
// Created by luca on 23.10.20.
//

#include "Cube.h"

//TODO: Richige Farben einfügen sodass würfel gelöst ist
Cube::Cube() : Cube(CubeConstants::WHITE_FACE_SOLVED, CubeConstants::GREEN_FACE_SOLVED, CubeConstants::RED_FACE_SOLVED,
                    CubeConstants::YELLOW_FACE_SOLVED, CubeConstants::BLUE_FACE_SOLVED, CubeConstants::ORANGE_FACE_SOLVED) {
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
    //Maximalwert 9
    i = i % 9;

    //Alles links der niederwertigsten 3 Bit löschen (eigentlich unnötig)
    seq = (seq << 29) >> 29;
    //Verschiebung an den Index
    seq = seq << (i * 3);

    //Linken teil des face extrahieren
    unsigned left = target >> ((i+1) * 3) << ((i+1) * 3);

    //rechten teil des face extrahieren.
    unsigned right = target << ( 29 - (i * 3) ) >> ( 29 - (i * 3) );

    //Alle drei teile zusammenfügen
    unsigned result = left | seq | right;
    target = result;
}

unsigned Cube::getSequence(unsigned i, unsigned source) {
    //index geht in dreier schritten voran
    return source << (32 - ((i+1) * 3)) >> (32 - 3);
}

void Cube::generateFaceArr() {
    this->faceArr[CubeConstants::FACE_WHITE] = &(this->white);
    this->faceArr[CubeConstants::FACE_RED] = &(this->red);
    this->faceArr[CubeConstants::FACE_BLUE] = &(this->blue);
    this->faceArr[CubeConstants::FACE_ORANGE] = &(this->orange);
    this->faceArr[CubeConstants::FACE_GREEN] = &(this->green);
    this->faceArr[CubeConstants::FACE_YELLOW] = &(this->yellow);
}

unsigned *Cube::resolveFaceIndex(unsigned i) {
    switch (i) {
        case CubeConstants::FACE_WHITE:
            return &(this->white);
        case CubeConstants::FACE_BLUE:
            return &(this->blue);
        case CubeConstants::FACE_RED:
            return &(this->red);
        case CubeConstants::FACE_YELLOW:
            return &(this->yellow);
        case CubeConstants::FACE_ORANGE:
            return &(this->orange);
        case CubeConstants::FACE_GREEN:
            return &(this->green);
        default:
            return &(this->white);
    }
}

unsigned Cube::getFace(unsigned FACE) {
    return *(this->faceArr[FACE]);
}

void Cube::setFace(unsigned FACE, unsigned value) {
    *(this->faceArr[FACE]) = value;
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
