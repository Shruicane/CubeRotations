#include <iostream>
//#include <boost/python.hpp>
#include "Cube.h"
#include "CubeConstants.h"

using namespace std;

void printBin(unsigned input){

    for (int i = 0; i < 32; ++i) {
        unsigned out = (input << i) >> 31;
        //unsigned out = (input << (32 - i)) >> 31; //use this line for inverted bit order (MSB on the right, LSB on the left hand side)
        cout << out;
    }
    cout << endl;
}

unsigned getSequence(unsigned i, unsigned source) {
    //index geht in dreier schritten voran
    return source << (32 - ((i+1) * 3)) >> (32 - 3);
}

void setSequence(unsigned i, unsigned seq, unsigned &target) {

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

Cube generateSolvedFaces(){

    Cube solved = Cube(0, 0, 0, 0, 0, 0);

    unsigned res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_WHITE, res);
    }
    solved.setFace(CubeConstants::FACE_WHITE, res);

    res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_RED, res);
    }
    solved.setFace(CubeConstants::FACE_RED, res);

    res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_BLUE, res);
    }
    solved.setFace(CubeConstants::FACE_BLUE, res);

    res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_ORANGE, res);
    }
    solved.setFace(CubeConstants::FACE_ORANGE, res);

    res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_GREEN, res);
    }
    solved.setFace(CubeConstants::FACE_GREEN, res);

    res = 0;
    for (int i = 0; i < 9; ++i) {
        setSequence(i, CubeConstants::COLOR_YELLOW, res);
    }
    solved.setFace(CubeConstants::FACE_YELLOW, res);

    return solved;
}

void printCube(Cube &c){


    cout << "White Face: ";
    printBin(c.getFace(CubeConstants::FACE_WHITE));
    cout << "Red Face: ";
    printBin(c.getFace(CubeConstants::FACE_RED));
    cout << "Blue Face: ";
    printBin(c.getFace(CubeConstants::FACE_BLUE));
    cout << "Orange Face: ";
    printBin(c.getFace(CubeConstants::FACE_ORANGE));
    cout << "Green Face: ";
    printBin(c.getFace(CubeConstants::FACE_GREEN));
    cout << "Yellow Face: ";
    printBin(c.getFace(CubeConstants::FACE_YELLOW));
    cout << "\n" << endl;

    /*cout << "        | 0 1 2 |" << endl;
    cout << "        | 0 1 2 |" << endl;
    cout << "        | 0 1 2 |" << endl;
    cout << "| 0 1 2 | 0 1 2 | 0 1 2 | 0 1 2 |" << endl;
    cout << "| 0 1 2 | 0 1 2 | 0 1 2 | 0 1 2 |" << endl;
    cout << "| 0 1 2 | 0 1 2 | 0 1 2 | 0 1 2 |" << endl;
    cout << "        | 0 1 2 |" << endl;
    cout << "        | 0 1 2 |" << endl;
    cout << "        | 0 1 2 |" << endl;
*/
}

int main() {

    Cube cube = generateSolvedFaces();
    printCube(cube);
    cube.rotate(10);
    printCube(cube);
    cube.rotate(11);
    printCube(cube);
    cube.getSequence(0, cube.getFace(CubeConstants::FACE_GREEN));


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/*
BOOST_PYTHON_MODULE(cube) {
    using namespace boost::python;

    class_<Cube>("Cube")
            .def("rotate", &Cube::rotate)
            ;

    class_<CubeConstants>("CubeConstants")
            .def_readonly("COLOR_EMPTY", &CubeConstants::COLOR_EMPTY)
            .def_readonly("COLOR_WHITE", &CubeConstants::COLOR_WHITE)
            .def_readonly("COLOR_RED", &CubeConstants::COLOR_RED)
            .def_readonly("COLOR_BLUE", &CubeConstants::COLOR_BLUE)
            .def_readonly("COLOR_ORANGE", &CubeConstants::COLOR_ORANGE)
            .def_readonly("COLOR_GREEN", &CubeConstants::COLOR_GREEN)
            .def_readonly("COLOR_YELLOW", &CubeConstants::COLOR_YELLOW)
            .def_readonly("FACE_WHITE", &CubeConstants::FACE_WHITE)
            .def_readonly("FACE_RED", &CubeConstants::FACE_RED)
            .def_readonly("FACE_BLUE", &CubeConstants::FACE_BLUE)
            .def_readonly("FACE_ORANGE", &CubeConstants::FACE_ORANGE)
            .def_readonly("FACE_GREEN", &CubeConstants::FACE_GREEN)
            .def_readonly("FACE_YELLOW", &CubeConstants::FACE_YELLOW)
            .def_readonly("CHECK_CROSS", &CubeConstants::CHECK_CROSS)
            .def_readonly("CHECK_CORNER_1", &CubeConstants::CHECK_CORNER_1)
            .def_readonly("CHECK_CORNER_2", &CubeConstants::CHECK_CORNER_2)
            .def_readonly("CHECK_CORNER_3", &CubeConstants::CHECK_CORNER_3)
            .def_readonly("CHECK_CORNER_4", &CubeConstants::CHECK_CORNER_4)
            .def_readonly("CHECK_EDGE_1", &CubeConstants::CHECK_EDGE_1)
            .def_readonly("CHECK_EDGE_2", &CubeConstants::CHECK_EDGE_2)
            .def_readonly("CHECK_EDGE_3", &CubeConstants::CHECK_EDGE_3)
            .def_readonly("CHECK_EDGE_4", &CubeConstants::CHECK_EDGE_4)
            .def_readonly("CHECK_YELLOW_CROSS_POSITIONS", &CubeConstants::CHECK_YELLOW_CROSS_POSITIONS)
            .def_readonly("CHECK_YELLOW_CROSS_FACES", &CubeConstants::CHECK_YELLOW_CROSS_FACES)
            .def_readonly("CHECK_YELLOW_CORNER_POSITIONS", &CubeConstants::CHECK_YELLOW_CORNER_POSITIONS)
            .def_readonly("CHECK_YELLOW_CORNER_FACE_1", &CubeConstants::CHECK_YELLOW_CORNER_FACE_1)
            .def_readonly("CHECK_YELLOW_CORNER_FACE_2", &CubeConstants::CHECK_YELLOW_CORNER_FACE_2)
            .def_readonly("CHECK_YELLOW_CORNER_FACE_3", &CubeConstants::CHECK_YELLOW_CORNER_FACE_3)
            .def_readonly("CHECK_YELLOW_CORNER_FACE_4", &CubeConstants::CHECK_YELLOW_CORNER_FACE_4)
            .def_readonly("ROTATE_LEFT", &CubeConstants::ROTATE_LEFT)
            .def_readonly("ROTATE_LEFT_PRIME", &CubeConstants::ROTATE_LEFT_PRIME)
            .def_readonly("ROTATE_RIGHT", &CubeConstants::ROTATE_RIGHT)
            .def_readonly("ROTATE_RIGHT_PRIME", &CubeConstants::ROTATE_RIGHT_PRIME)
            .def_readonly("ROTATE_UP", &CubeConstants::ROTATE_UP)
            .def_readonly("ROTATE_UP_PRIME", &CubeConstants::ROTATE_UP_PRIME)
            .def_readonly("ROTATE_DOWN", &CubeConstants::ROTATE_DOWN)
            .def_readonly("ROTATE_DOWN_PRIME", &CubeConstants::ROTATE_DOWN_PRIME)
            .def_readonly("ROTATE_FRONT", &CubeConstants::ROTATE_FRONT)
            .def_readonly("ROTATE_FRONT_PRIME", &CubeConstants::ROTATE_FRONT_PRIME)
            .def_readonly("ROTATE_BACK", &CubeConstants::ROTATE_BACK)
            .def_readonly("ROTATE_BACK_PRIME", &CubeConstants::ROTATE_BACK_PRIME)
            .def_readonly("ROTATE_X_SLICE", &CubeConstants::ROTATE_X_SLICE)
            .def_readonly("ROTATE_X_SLICE_PRIME", &CubeConstants::ROTATE_X_SLICE_PRIME)
            .def_readonly("ROTATE_Y_SLICE", &CubeConstants::ROTATE_Y_SLICE)
            .def_readonly("ROTATE_Y_SLICE_PRIME", &CubeConstants::ROTATE_Y_SLICE_PRIME)
            .def_readonly("ROTATE_Z_SLICE", &CubeConstants::ROTATE_Z_SLICE)
            .def_readonly("ROTATE_Z_SLICE_PRIME", &CubeConstants::ROTATE_Z_SLICE_PRIME)
            ;
}
*/
