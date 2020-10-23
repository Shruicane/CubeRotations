//
// Created by luca on 23.10.20.
//

#ifndef CUBEROTATIONS_CUBE_H
#define CUBEROTATIONS_CUBE_H


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
    unsigned* arr[6];
    void generatePointerArray();

public:
    Cube();
    Cube(bool valid);
    Cube(unsigned int white, unsigned int green, unsigned int red, unsigned int yellow, unsigned int blue,
         unsigned int orange);

    char getSequence(int i);
    void setSequence(int i, unsigned seq);
    unsigned getFace(char i);

    //rotate Funktionen

    Cube rotate(int i);

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
};


#endif //CUBEROTATIONS_CUBE_H
