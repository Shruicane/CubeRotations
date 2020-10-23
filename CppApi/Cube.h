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
 * Cube Seiten reihenfolge:
 *
 * */

class Cube {
private:
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
public:
    Cube();
    char getSequence(int i){

    }
};


#endif //CUBEROTATIONS_CUBE_H
