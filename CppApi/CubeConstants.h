#ifndef CUBE_CONSTANTS_H
#define CUBE_CONSTANTS_H

namespace CubeConstants
{
    // colors
    const int COLOR_EMPTY = 0;
    const int COLOR_WHITE = 0;

    // Faces
    const int FACE_WHITE = 0;
    const int FACE_RED = 1;
    const int FACE_BLUE = 2;
    const int FACE_ORANGE = 3;
    const int FACE_GREEN = 4;
    const int FACE_YELLOW = 5;


    // Checks
    const int CHECK_CROSS = 0;

    const int CHECK_CORNER_1 = 1;
    const int CHECK_CORNER_2 = 2;
    const int CHECK_CORNER_3 = 3;
    const int CHECK_CORNER_4 = 4;

    const int CHECK_EDGE_1 = 5;
    const int CHECK_EDGE_2 = 6;
    const int CHECK_EDGE_3 = 7;
    const int CHECK_EDGE_4 = 8;

    const int CHECK_YELLOW_CROSS_POSITIONS = 9;
    const int CHECK_YELLOW_CROSS_FACES = 10;

    const int CHECK_YELLOW_CORNER_POSITIONS = 11;
    const int CHECK_YELLOW_CORNER_FACE_1 = 12;
    const int CHECK_YELLOW_CORNER_FACE_2 = 13;
    const int CHECK_YELLOW_CORNER_FACE_3 = 14;
    const int CHECK_YELLOW_CORNER_FACE_4 = 15;


    // face checks
    const int WHITE_FACE_SOLVED = 0;
    const int RED_FACE_SOLVED = 0;
    const int BLUE_FACE_SOLVED = 0;
    const int ORANGE_FACE_SOLVED = 0;
    const int GREEN_FACE_SOLVED = 0;
    const int YELLOW_FACE_SOLVED = 0;

    // rotates
    const int ROTATE_LEFT = 0;
    const int ROTATE_LEFT_PRIME = 1;
    const int ROTATE_RIGHT = 2;
    const int ROTATE_RIGHT_PRIME = 3;
    const int ROTATE_UP = 4;
    const int ROTATE_UP_PRIME = 5;
    const int ROTATE_DOWN = 6;
    const int ROTATE_DOWN_PRIME = 7;
    const int ROTATE_FRONT = 8;
    const int ROTATE_FRONT_PRIME = 9;
    const int ROTATE_BACK = 10;
    const int ROTATE_BACK_PRIME = 11;
    const int ROTATE_X_SLICE = 12;
    const int ROTATE_X_SLICE_PRIME = 13;
    const int ROTATE_Y_SLICE = 14;
    const int ROTATE_Y_SLICE_PRIME = 15;
    const int ROTATE_Z_SLICE = 16;
    const int ROTATE_Z_SLICE_PRIME = 17;


} // namespace CubeConstants

#endif //CUBE_CONSTANTS_H
