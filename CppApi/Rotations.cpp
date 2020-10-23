#include "Cube.h"

Cube Cube::rotateLeft() {

    this->setFace(CubeConstants::FACE_ORANGE, this->rotateFace(CubeConstants::FACE_ORANGE));

    return *this;
}

Cube Cube::rotateLeftPrime() {
    return *this;
}

Cube Cube::rotateRight() {
    return *this;
}

Cube Cube::rotateRightPrime() {
    return *this;
}

Cube Cube::rotateUp() {
    return *this;
}

Cube Cube::rotateUpPrime() {
    return *this;
}

Cube Cube::rotateDown() {
    return *this;
}

Cube Cube::rotateDownPrime() {
    return *this;
}

Cube Cube::rotateFront() {
    return *this;
}

Cube Cube::rotateFrontPrime() {
    return *this;
}

Cube Cube::rotateBack() {
    return *this;
}

Cube Cube::rotateBackPrime() {
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



