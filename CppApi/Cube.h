//
// Created by luca on 23.10.20.
//

#ifndef CUBEROTATIONS_CUBE_H
#define CUBEROTATIONS_CUBE_H

#include <iostream>
#include <random>
#include "CubeConstants.h"

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
    void printBinary(unsigned input);


    //Face Rotation (anzahl rotationen im uhrzeigersinn)
    unsigned rotateFace(unsigned FACE);
    unsigned rotateFaceInverted(unsigned FACE);


    //help methoden
    void copyRow(unsigned src, unsigned i1, unsigned i2, unsigned i3, unsigned destFACE, unsigned _i1, unsigned _i2, unsigned _i3);


        //Rotations
    Cube rotateLeft(bool changeOrigin);
    Cube rotateLeftPrime(bool changeOrigin);
    Cube rotateRight(bool changeOrigin);
    Cube rotateRightPrime(bool changeOrigin);
    Cube rotateUp(bool changeOrigin);
    Cube rotateUpPrime(bool changeOrigin);
    Cube rotateDown(bool changeOrigin);
    Cube rotateDownPrime(bool changeOrigin);
    Cube rotateFront(bool changeOrigin);
    Cube rotateFrontPrime(bool changeOrigin);
    Cube rotateBack(bool changeOrigin);
    Cube rotateBackPrime(bool changeOrigin);
    Cube rotateXSlice(bool changeOrigin);
    Cube rotateXSlicePrime(bool changeOrigin);
    Cube rotateYSlice(bool changeOrigin);
    Cube rotateYSlicePrime(bool changeOrigin);
    Cube rotateZSlice(bool changeOrigin);
    Cube rotateZSlicePrime(bool changeOrigin);


public:
    Cube();
    explicit Cube(bool valid);
    Cube(const Cube &cube);
    Cube(unsigned int white, unsigned int red, unsigned int blue, unsigned int orange, unsigned int green,
         unsigned int yellow);
    void printCube(bool showLegend);
    Cube setScrambled();
    bool operator==(Cube &c);

    unsigned getSequence(unsigned i, unsigned source);
    void setSequence(unsigned i, unsigned seq, unsigned &target);

    unsigned getFace(unsigned FACE);
    Cube rotate(int , bool changeOrigin);
    void setFace(unsigned FACE, unsigned value);

};


#endif //CUBEROTATIONS_CUBE_H
