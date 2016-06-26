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

void printFace(Face &value);

class Cube
{
    public:
        std::array<Face, 6> structure;
        enum Side {
            UP,
            LEFT,
            DOWN,
            RIGHT,
            BACK,
            FRONT
        };

    private:
        void rotateX(int n);
        void rotateY(int n);
        void rotateZ(int n);
        void rotateUp();
        void rotateLeft();
        void rotateDown();
        void rotateRight();
        void rotateBack();
        void rotateFront();

    public:
        Cube();
        void print();
        void rotate(Side side);
};

inline std::ostream &operator<<(std::ostream &out, const Cube &value)
{
    return out << value.structure;
}

#endif
