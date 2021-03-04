#include "Cube.h"


Cube Cube::rotateLeft() {

    this->setFace(CubeConstants::FACE_ORANGE, this->rotateFace(CubeConstants::FACE_ORANGE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 0, 3, 6, CubeConstants::FACE_BLUE, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 0, 3, 6, CubeConstants::FACE_WHITE, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 0, 3, 6, CubeConstants::FACE_GREEN, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 0, 3, 6, CubeConstants::FACE_YELLOW, 0, 3, 6);

    return *this;
}

Cube Cube::rotateLeftPrime() {

    this->setFace(CubeConstants::FACE_ORANGE, this->rotateFaceInverted(CubeConstants::FACE_ORANGE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 0, 3, 6, CubeConstants::FACE_YELLOW, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 0, 3, 6, CubeConstants::FACE_GREEN, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 0, 3, 6, CubeConstants::FACE_WHITE, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 0, 3, 6, CubeConstants::FACE_BLUE, 0, 3, 6);
    return *this;
}

Cube Cube::rotateRight() {

    this->setFace(CubeConstants::FACE_RED, this->rotateFace(CubeConstants::FACE_RED));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 2, 5, 8, CubeConstants::FACE_YELLOW, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 2, 5, 8, CubeConstants::FACE_GREEN, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 2, 5, 8, CubeConstants::FACE_WHITE, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 2, 5, 8, CubeConstants::FACE_BLUE, 2, 5, 8);

    return *this;
}

Cube Cube::rotateRightPrime() {

    this->setFace(CubeConstants::FACE_RED, this->rotateFaceInverted(CubeConstants::FACE_RED));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 2, 5, 8, CubeConstants::FACE_BLUE, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 2, 5, 8, CubeConstants::FACE_WHITE, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 2, 5, 8, CubeConstants::FACE_GREEN, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 2, 5, 8, CubeConstants::FACE_YELLOW, 2, 5, 8);
    return *this;
}

Cube Cube::rotateUp() {

    this->setFace(CubeConstants::FACE_YELLOW, this->rotateFace(CubeConstants::FACE_YELLOW));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 0, 1, 2, CubeConstants::FACE_ORANGE, 0, 1, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 0, 1, 2, CubeConstants::FACE_GREEN, 8, 7, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 6, 7, 8, CubeConstants::FACE_RED, 2, 1, 0);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 0, 1, 2, CubeConstants::FACE_BLUE, 0, 1, 2);

    return *this;
}

Cube Cube::rotateUpPrime() {

    this->setFace(CubeConstants::FACE_YELLOW, this->rotateFaceInverted(CubeConstants::FACE_YELLOW));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 0, 1, 2, CubeConstants::FACE_BLUE, 0, 1, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 0, 1, 2, CubeConstants::FACE_RED, 0, 1, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 0, 1, 2, CubeConstants::FACE_GREEN, 8, 7, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 8, 7, 6, CubeConstants::FACE_ORANGE, 0, 1, 2);

    return *this;
}

Cube Cube::rotateDown() {

    this->setFace(CubeConstants::FACE_WHITE, this->rotateFace(CubeConstants::FACE_WHITE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 6, 7, 8, CubeConstants::FACE_BLUE, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 6, 7, 8, CubeConstants::FACE_RED, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 6, 7, 8, CubeConstants::FACE_GREEN, 2, 1, 0);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 2, 1, 0, CubeConstants::FACE_ORANGE, 6, 7, 8);
    return *this;
}

Cube Cube::rotateDownPrime() {

    this->setFace(CubeConstants::FACE_WHITE, this->rotateFaceInverted(CubeConstants::FACE_WHITE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_BLUE), 6, 7, 8, CubeConstants::FACE_ORANGE, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 6, 7, 8, CubeConstants::FACE_GREEN, 2, 1, 0);
    this->copyRow(cube.getFace(CubeConstants::FACE_GREEN), 2, 1, 0, CubeConstants::FACE_RED, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 6, 7, 8, CubeConstants::FACE_BLUE, 6, 7, 8);
    return *this;
}

Cube Cube::rotateFront() {

    this->setFace(CubeConstants::FACE_BLUE, this->rotateFace(CubeConstants::FACE_BLUE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 8, 5, 2, CubeConstants::FACE_YELLOW, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 6, 7, 8, CubeConstants::FACE_RED, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 0, 3, 6, CubeConstants::FACE_WHITE, 2, 1, 0);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 2, 1, 0, CubeConstants::FACE_ORANGE, 8, 5, 2);
    return *this;
}

Cube Cube::rotateFrontPrime() {

    this->setFace(CubeConstants::FACE_BLUE, this->rotateFaceInverted(CubeConstants::FACE_BLUE));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 8, 7, 6, CubeConstants::FACE_ORANGE, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 2, 5, 8, CubeConstants::FACE_WHITE, 0, 1, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 0, 1, 2, CubeConstants::FACE_RED, 6, 3, 0);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 6, 3, 0, CubeConstants::FACE_YELLOW, 8, 7, 6);
    return *this;
}

Cube Cube::rotateBack() {

    this->setFace(CubeConstants::FACE_GREEN, this->rotateFace(CubeConstants::FACE_GREEN));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 2, 1, 0, CubeConstants::FACE_ORANGE, 0, 3, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 0, 3, 6, CubeConstants::FACE_WHITE, 6, 7, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 6, 7, 8, CubeConstants::FACE_RED, 8, 5, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 8, 5, 2, CubeConstants::FACE_YELLOW, 2, 1, 0);
    return *this;
}

Cube Cube::rotateBackPrime() {

    this->setFace(CubeConstants::FACE_GREEN, this->rotateFaceInverted(CubeConstants::FACE_GREEN));
    Cube cube(*this);
    this->copyRow(cube.getFace(CubeConstants::FACE_ORANGE), 6, 3, 0, CubeConstants::FACE_YELLOW, 0, 1, 2);
    this->copyRow(cube.getFace(CubeConstants::FACE_YELLOW), 0, 1, 2, CubeConstants::FACE_RED, 2, 5, 8);
    this->copyRow(cube.getFace(CubeConstants::FACE_RED), 2, 5, 8, CubeConstants::FACE_WHITE, 8, 7, 6);
    this->copyRow(cube.getFace(CubeConstants::FACE_WHITE), 8, 7, 6, CubeConstants::FACE_ORANGE, 6, 3, 0);
    return *this;
}

Cube Cube::rotateXSlice() {
    return *this;
}

Cube Cube::rotateXSlicePrime() {
    return *this;
}

Cube Cube::rotateYSlice() {
    return *this;
}

Cube Cube::rotateYSlicePrime() {
    return *this;
}

Cube Cube::rotateZSlice() {
    return *this;
}

Cube Cube::rotateZSlicePrime() {
    return *this;
}

unsigned Cube::rotateFace(unsigned FACE) {

    //Es werden keine Werte des cubes geändert - eine bestimmte seite wird um 90° im Uhrzeigersinn gedreht
    unsigned face = this->getFace(FACE);
    unsigned faceRes = this->getFace(FACE);

    this->setSequence(0, this->getSequence(6, face), faceRes);
    this->setSequence(1, this->getSequence(3, face), faceRes);
    this->setSequence(2, this->getSequence(0, face), faceRes);
    this->setSequence(3, this->getSequence(7, face), faceRes);
    this->setSequence(5, this->getSequence(1, face), faceRes);
    this->setSequence(6, this->getSequence(8, face), faceRes);
    this->setSequence(7, this->getSequence(5, face), faceRes);
    this->setSequence(8, this->getSequence(2, face), faceRes);

    return faceRes;
}

unsigned Cube::rotateFaceInverted(unsigned FACE) {

    //Es werden keine Werte des cubes geändert - eine bestimmte seite wird um 90° im Uhrzeigersinn gedreht
    unsigned face = this->getFace(FACE);
    unsigned faceRes = this->getFace(FACE);

    this->setSequence(0, this->getSequence(2, face), faceRes);
    this->setSequence(1, this->getSequence(5, face), faceRes);
    this->setSequence(2, this->getSequence(8, face), faceRes);
    this->setSequence(3, this->getSequence(1, face), faceRes);
    this->setSequence(5, this->getSequence(7, face), faceRes);
    this->setSequence(6, this->getSequence(0, face), faceRes);
    this->setSequence(7, this->getSequence(3, face), faceRes);
    this->setSequence(8, this->getSequence(6, face), faceRes);
    return faceRes;
}

void Cube::copyRow(unsigned src, unsigned i1, unsigned i2, unsigned i3, unsigned destFACE, unsigned _i1, unsigned _i2, unsigned _i3){
    /*
     * src = bitstring of Face you want to copy
     * destFACE = ID of the Face you want to replace
     * i1...3 = origin index
     * _i1...3 = destination index
     *
     * */
    unsigned res = this->getFace(destFACE);
    this->setSequence(_i1, this->getSequence(i1, src), res);
    this->setSequence(_i2, this->getSequence(i2, src), res);
    this->setSequence(_i3, this->getSequence(i3, src), res);
    this->setFace(destFACE, res);
}

void Cube::printBinary(unsigned input){

    for (int i = 0; i < 32; ++i) {
        unsigned out = (input << i) >> 31;
        //unsigned out = (input << (32 - i)) >> 31; //use this line for inverted bit order (MSB on the right, LSB on the left hand side)
        cout << out;
    }
    cout << endl;
}




