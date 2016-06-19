#include "cube.h"
#include <iostream>

Face makeFace(int value) {
    return {{
        {value, value, value},
        {value, value, value},
        {value, value, value}
    }};
}

Face makeTestFace() {
    return {{
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    }};
}

void rotateFace(Face &value) {

    // Corners
    int holder = value[0][0];

    value[0][0] = value[2][0];
    value[2][0] = value[2][2];
    value[2][2] = value[0][2];
    value[0][2] = holder;

    // Edges
    holder = value[0][1];
    value[0][1] = value[1][0];
    value[1][0] = value[2][1];
    value[2][1] = value[1][2];
    value[1][2] = holder;

}

void printFace(Face &value) {
    for (int i = 0; i < 3; ++i) {
        std::cout <<
        value[i] << std::endl;
    }
}

Cube::Cube()
{
    for (int i = 0; i < 6; ++i) {
        structure[i] = makeFace(i + 1);
    }
}

void Cube::print()
{
    for (int i = 0; i < 3; ++i) {
        std::cout << std::string(18, ' ') << structure[REAR][i] << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout <<
            structure[TOP][i] <<
            structure[LEFT][i] <<
            structure[BOTTOM][i] <<
            structure[RIGHT][i] << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << std::string(18, ' ') << structure[FRONT][i] << std::endl;
    }
}