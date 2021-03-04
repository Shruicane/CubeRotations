#ifndef CUBEROTATIONS_CUBECONSTANTS_H
#define CUBEROTATIONS_CUBECONSTANTS_H

#include <string>

struct CubeConstants
{
    // colors
    static const int COLOR_EMPTY = 0;
    static const int COLOR_WHITE = 1;
    static const int COLOR_RED = 2;
    static const int COLOR_BLUE = 3;
    static const int COLOR_ORANGE = 4;
    static const int COLOR_GREEN = 5;
    static const int COLOR_YELLOW = 6;

    // Faces
    static const int FACE_WHITE = 0;
    static const int FACE_RED = 1;
    static const int FACE_BLUE = 2;
    static const int FACE_ORANGE = 3;
    static const int FACE_GREEN = 4;
    static const int FACE_YELLOW = 5;


    // Checks
    static const int CHECK_CROSS = 0;

    static const int CHECK_CORNER_1 = 1;
    static const int CHECK_CORNER_2 = 2;
    static const int CHECK_CORNER_3 = 3;
    static const int CHECK_CORNER_4 = 4;

    static const int CHECK_EDGE_1 = 5;
    static const int CHECK_EDGE_2 = 6;
    static const int CHECK_EDGE_3 = 7;
    static const int CHECK_EDGE_4 = 8;

    static const int CHECK_YELLOW_CROSS_POSITIONS = 9;
    static const int CHECK_YELLOW_CROSS_FACES = 10;

    static const int CHECK_YELLOW_CORNER_POSITIONS = 11;
    static const int CHECK_YELLOW_CORNER_FACE_1 = 12;
    static const int CHECK_YELLOW_CORNER_FACE_2 = 13;
    static const int CHECK_YELLOW_CORNER_FACE_3 = 14;
    static const int CHECK_YELLOW_CORNER_FACE_4 = 15;


    // face checks
    static const int WHITE_FACE_SOLVED = 0;
    static const int RED_FACE_SOLVED = 0;
    static const int BLUE_FACE_SOLVED = 0;
    static const int ORANGE_FACE_SOLVED = 0;
    static const int GREEN_FACE_SOLVED = 0;
    static const int YELLOW_FACE_SOLVED = 0;

    // rotates
    static const int ROTATE_LEFT = 0;
    static const int ROTATE_LEFT_PRIME = 1;
    static const int ROTATE_RIGHT = 2;
    static const int ROTATE_RIGHT_PRIME = 3;
    static const int ROTATE_UP = 4;
    static const int ROTATE_UP_PRIME = 5;
    static const int ROTATE_DOWN = 6;
    static const int ROTATE_DOWN_PRIME = 7;
    static const int ROTATE_FRONT = 8;
    static const int ROTATE_FRONT_PRIME = 9;
    static const int ROTATE_BACK = 10;
    static const int ROTATE_BACK_PRIME = 11;
    static const int ROTATE_X_SLICE = 12;
    static const int ROTATE_X_SLICE_PRIME = 13;
    static const int ROTATE_Y_SLICE = 14;
    static const int ROTATE_Y_SLICE_PRIME = 15;
    static const int ROTATE_Z_SLICE = 16;
    static const int ROTATE_Z_SLICE_PRIME = 17;
};
#endif //CUBEROTATIONS_CUBECONSTANTS_H
