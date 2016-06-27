#include <vector>
#include "classes/cube.h"
#include "classes/testsuite.h"
#include <iostream>


void printRotate() {
//    std::cout << "Base cube __c" << std::endl;
//    Cube cube;
//    cube.print();
//
//    std::cout << std::endl;

    std::cout << "Test suite" << std::endl;
    TestSuite testsuite;
    testsuite.execute();
}

int main(int argc, char **argv)
{
    printRotate();
}