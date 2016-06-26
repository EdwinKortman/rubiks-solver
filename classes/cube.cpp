#include "cube.h"
#include <iostream>

int modulo(int x, int y) {
    int r = x % y;
    if (r < 0) {
        return r + y;
    }
    return r;
}

Face makeFace(int i) {
    int j = i * 10;

    return {{
        {1 + j, 2 + j, 3 + j},
        {4 + j, 5 + j, 6 + j},
        {7 + j, 8 + j, 9 + j},
    }};
}

void rotateFace(Face &value, int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
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
}

void printFace(Face &value) {
    for (int i = 0; i < 3; ++i) {
        std::cout <<
        value[i] << std::endl;
    }
}

Cube::Cube() {
    for (int i = 0; i < 6; ++i) {
        structure[i] = makeFace(i + 1);
    }
}

void Cube::rotateX(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        Face holder = structure[BACK];

        structure[BACK] = structure[UP];
        structure[UP] = structure[FRONT];
        structure[FRONT] = structure[DOWN];
        structure[DOWN] = holder;
        rotateFace(structure[RIGHT], 1);
        rotateFace(structure[LEFT], -1);
    }
}

void Cube::rotateY(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        Face holder = structure[UP];

        structure[UP] = structure[LEFT];
        structure[LEFT] = structure[DOWN];
        structure[DOWN] = structure[RIGHT];
        structure[RIGHT] = holder;
        rotateFace(structure[FRONT], 1);
        rotateFace(structure[BACK], -1);
    }
}

void Cube::rotateZ(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        Face holder = structure[FRONT];

        structure[FRONT] = structure[RIGHT];
        structure[RIGHT] = structure[BACK];
        structure[BACK] = structure[LEFT];
        structure[LEFT] = holder;
        rotateFace(structure[UP], 1);
        rotateFace(structure[DOWN], -1);
    }
}

void Cube::rotateUp(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        rotateX(-1);
        rotateFront(+1);
        rotateX(+1);
    }
}

void Cube::rotateLeft(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        rotateZ(-1);
        rotateFrontInverse(+1);
        rotateZ(+1);
    }
}

void Cube::rotateDown(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        rotateX(+1);
        rotateFrontInverse(+1);
        rotateX(-1);
    }
}

void Cube::rotateRight(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        rotateZ(+1);
        rotateFront(+1);
        rotateZ(-1);
    }
}

void Cube::rotateBack(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        rotateX(+2);
        rotateFrontInverse(+1);
        rotateX(-2);
    }
}

void Cube::rotateFront(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        std::array<int, 3> holder = structure[UP][2];

        structure[UP][2] = structure[LEFT][2];
        structure[LEFT][2] = structure[DOWN][2];
        structure[DOWN][2] = structure[RIGHT][2];
        structure[RIGHT][2] = holder;


        rotateFace(structure[FRONT], -1);
    }
}

void Cube::rotateFrontInverse(int n) {
    for (int i = 0; i < modulo(n, 4); ++i) {
        std::array<int, 3> holder = structure[UP][2];

        structure[UP][2] = structure[RIGHT][2];
        structure[RIGHT][2] = structure[DOWN][2];
        structure[DOWN][2] = structure[LEFT][2];
        structure[LEFT][2] = holder;


        rotateFace(structure[FRONT], -1);
    }
}


void Cube::rotate(Side side, int n) {
    switch(side) {
        case UP:
            rotateUp(n);
            break;
        case LEFT:
            rotateLeft(n);
            break;
        case DOWN:
            rotateDown(n);
            break;
        case RIGHT:
            rotateRight(n);
            break;
        case BACK:
            rotateBack(n);
            break;
        case FRONT:
            rotateFront(n);
            break;
    }
}

void Cube::print()
{
    for (int i = 0; i < 3; ++i) {
        std::cout << std::string(24, ' ') << structure[BACK][i] << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout <<
            structure[UP][i] <<
            structure[LEFT][i] <<
            structure[DOWN][i] <<
            structure[RIGHT][i] << std::endl;
    }

    for (int i = 0; i < 3; ++i) {
        std::cout << std::string(24, ' ') << structure[FRONT][i] << std::endl;
    }
}