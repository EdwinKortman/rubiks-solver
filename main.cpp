#include <vector>
#include "classes/cube.h"
#include <iostream>


int main(int argc, char **argv)
{
    Cube cube;
//    cube.print();

    Face face = makeTestFace();
    printFace(face);
    rotateFace(face);
    printFace(face);
}