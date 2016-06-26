#include <vector>
#include "classes/cube.h"
#include <iostream>


void printRotate() {
    Cube cube;
    cube.print();

    std::cout << std::endl << std::endl;

    Cube cube2;
    cube2.rotate(Cube::FRONT, 1);
    cube2.print();
}

int main(int argc, char **argv)
{
    printRotate();
}