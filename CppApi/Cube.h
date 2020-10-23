//
// Created by luca on 23.10.20.
//

#ifndef CUBEROTATIONS_CUBE_H
#define CUBEROTATIONS_CUBE_H

#define WHITE_FACE_SOLVED 0
#define RED_FACE_SOLVED 0
#define BLUE_FACE_SOLVED 0
#define ORANGE_FACE_SOLVED 0
#define GREEN_FACE_SOLVED 0
#define YELLOW_FACE_SOLVED 0

#define WHITE_FACE 0
#define RED_FACE 1
#define BLUE_FACE 2
#define ORANGE_FACE 3
#define GREEN_FACE 4
#define YELLOW_FACE 5

#include <iostream>
using namespace std;
/*
 * 3 bit pro Fläche * 9 = 27 * 6 = 162
 * int = 32 bit - 6 Integer (192 bit)
 * long = 64 bit - 3 long (192)
 * long long = 128 bit - 2 long long (256)
 *
 * anderer Ansatz: Mittelstein weglassen, weil er festgelegt ist.
 * 3 * 8 * 6 = 144
 * 5 Integer = 160
 *
 * Cube Farben:
 * 000: reserviert für NULL
 * 001: weiß
 * 010: grün
 * 011: rot
 * 100: gelb
 * 101: blau
 * 110: orange
 *
 * */

class Cube {
private:
    unsigned white;
    unsigned green;
    unsigned red;
    unsigned yellow;
    unsigned blue;
    unsigned orange;
    unsigned* faceArr[6];
    void generateFaceArr();
    unsigned* resolveFaceIndex(unsigned i);

    //Face Rotation (anzahl rotationen im uhrzeigersinn)
    unsigned rotateFace(int turns, unsigned FACE);

    //Rotations
    Cube rotateLeft();
    Cube rotateLeftPrime();
    Cube rotateRight();
    Cube rotateRightPrime();
    Cube rotateUp();
    Cube rotateUpPrime();
    Cube rotateDown();
    Cube rotateDownPrime();
    Cube rotateFront();
    Cube rotateFrontPrime();
    Cube rotateBack();
    Cube rotateBackPrime();
    Cube rotateXSlice();
    Cube rotateXSlicePrime();
    Cube rotateYSlice();
    Cube rotateYSlicePrime();
    Cube rotateZSlice();
    Cube rotateZSlicePrime();

public:
    Cube();
    explicit Cube(bool valid);
    Cube(const Cube &cube);
    Cube(unsigned int white, unsigned int red, unsigned int blue, unsigned int orange, unsigned int green,
         unsigned int yellow);

    bool operator==(Cube &c);

    unsigned getSequence(unsigned i, unsigned source);
    void setSequence(unsigned i, unsigned seq, unsigned &target);

    unsigned getFace(unsigned FACE);
    Cube rotate(int i);
    void setFace(unsigned i, unsigned value);

};


#endif //CUBEROTATIONS_CUBE_H
