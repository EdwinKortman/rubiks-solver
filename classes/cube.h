#ifndef RUBIKS_SOLVER_CUBE_H
#define RUBIKS_SOLVER_CUBE_H

#include <array>
#include <ostream>

template <typename T, std::size_t n>
std::ostream &operator<<(std::ostream &out, const std::array<T, n> &value)
{
    out << "[ ";
    for (const auto &x : value)
        out << x << " ";
    return out << "]";
}

using Face = std::array<std::array<int, 3>, 3>;
Face makeFace(int value);

Face makeTestFace();


void rotateFace(Face &value);
void printFace(Face &value);

class Cube
{
    public:
        std::array<Face, 6> structure;
        enum Side {
            TOP,
            LEFT,
            BOTTOM,
            RIGHT,
            REAR,
            FRONT
        };

    public:
        Cube();
        void print();
};

inline std::ostream &operator<<(std::ostream &out, const Cube &value)
{
    return out << value.structure;
}

#endif
