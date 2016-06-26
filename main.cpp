#include <vector>
#include "classes/cube.h"
#include <iostream>


void printRotate() {
    Cube cube;
    cube.print();

    std::cout << std::endl << std::endl;

//    Cube cube2;
//    cube2.rotateX(1);
//    cube2.print();
//
//    std::cout << std::endl << std::endl;
//
//    Cube cube3;
//    cube3.rotateX(-1);
//    cube3.print();
}

int main(int argc, char **argv)
{
    printRotate();
}