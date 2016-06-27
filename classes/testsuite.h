#ifndef RUBIKS_SOLVER_TESTS_H
#define RUBIKS_SOLVER_TESTS_H

#include "cube.h"

class TestSuite {
    public:
        Cube cube;

    private:
        void rotateFront();

    public:
        TestSuite();
        void execute();
};


#endif //RUBIKS_SOLVER_TESTS_H
