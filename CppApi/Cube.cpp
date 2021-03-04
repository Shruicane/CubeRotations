//
// Created by luca on 23.10.20.
//

#include "Cube.h"

//TODO: Richige Farben einfügen sodass würfel gelöst ist
Cube::Cube() : Cube(CubeConstants::WHITE_FACE_SOLVED, CubeConstants::RED_FACE_SOLVED, CubeConstants::BLUE_FACE_SOLVED, CubeConstants::ORANGE_FACE_SOLVED,
                    CubeConstants::GREEN_FACE_SOLVED, CubeConstants::YELLOW_FACE_SOLVED) {
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
    this->generateFaceArr();
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
    unsigned right = 0;
    if(i != 0){
        right = target << ( 32 - (i * 3) ) >> ( 32 - (i * 3) );
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

    unsigned *val = this->faceArr[FACE];
    unsigned valOfVal = *val;

    return valOfVal;
}

void Cube::setFace(unsigned FACE, unsigned value) {
    this->faceArr[FACE];

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

void Cube::printCube(bool showLegend){

    unsigned faceWhite = getFace(CubeConstants::FACE_WHITE);
    unsigned faceRed = getFace(CubeConstants::FACE_RED);
    unsigned faceBlue = getFace(CubeConstants::FACE_BLUE);
    unsigned faceOrange = getFace(CubeConstants::FACE_ORANGE);
    unsigned faceGreen = getFace(CubeConstants::FACE_GREEN);
    unsigned faceYellow = getFace(CubeConstants::FACE_YELLOW);

    if(showLegend) {
        cout << "White  := 1" << endl;
        cout << "Red    := 2" << endl;
        cout << "Blue   := 3" << endl;
        cout << "Orange := 4" << endl;
        cout << "Green  := 5" << endl;
        cout << "Yellow := 6 \n" << endl;
    }

    cout << "        | " << getSequence(0, faceGreen) << " " << getSequence(1, faceGreen) << " " << getSequence(2, faceGreen) << " |" << endl;
    cout << "        | " << getSequence(3, faceGreen) << " " << getSequence(4, faceGreen) << " " << getSequence(5, faceGreen) << " |" << endl;
    cout << "        | " << getSequence(6, faceGreen) << " " << getSequence(7, faceGreen) << " " << getSequence(8, faceGreen) << " |" << endl;
    //Mittelzeile 1
    cout << "| " << getSequence(6, faceOrange) << " " << getSequence(3, faceOrange) << " " << getSequence(0, faceOrange) << " |"
            << " " << getSequence(0, faceYellow) << " " << getSequence(1, faceYellow) << " " << getSequence(2, faceYellow) << " |"
            << " " << getSequence(2, faceRed) << " " << getSequence(5, faceRed) << " " << getSequence(8, faceRed) << " |"
            << " " << getSequence(8, faceWhite) << " " << getSequence(7, faceWhite) << " " << getSequence(6, faceWhite) << " |" << endl;

    //Mittelzeile 2
    cout << "| " << getSequence(7, faceOrange) << " " << getSequence(4, faceOrange) << " " << getSequence(1, faceOrange) << " |"
         << " " << getSequence(3, faceYellow) << " " << getSequence(4, faceYellow) << " " << getSequence(5, faceYellow) << " |"
         << " " << getSequence(1, faceRed) << " " << getSequence(4, faceRed) << " " << getSequence(7, faceRed) << " |"
         << " " << getSequence(5, faceWhite) << " " << getSequence(4, faceWhite) << " " << getSequence(3, faceWhite) << " |" << endl;
    //Mittelzeile 3
    cout << "| " << getSequence(8, faceOrange) << " " << getSequence(5, faceOrange) << " " << getSequence(2, faceOrange) << " |"
         << " " << getSequence(6, faceYellow) << " " << getSequence(7, faceYellow) << " " << getSequence(8, faceYellow) << " |"
         << " " << getSequence(0, faceRed) << " " << getSequence(3, faceRed) << " " << getSequence(6, faceRed) << " |"
         << " " << getSequence(2, faceWhite) << " " << getSequence(1, faceWhite) << " " << getSequence(0, faceWhite) << " |" << endl;

    cout << "        | " << getSequence(0, faceBlue) << " " << getSequence(0, faceBlue) << " " << getSequence(0, faceBlue) << " |" << endl;
    cout << "        | " << getSequence(3, faceBlue) << " " << getSequence(4, faceBlue) << " " << getSequence(5, faceBlue) << " |" << endl;
    cout << "        | " << getSequence(6, faceBlue) << " " << getSequence(7, faceBlue) << " " << getSequence(8, faceBlue) << " |" << endl;

}

bool Cube::operator==(Cube &c) {
    return (c.green == this->green
            && c.red == this->red
            && c.white == this->white
            && c.blue == this->blue
            && c.orange == this->orange
            && c.yellow == this->yellow);
}
