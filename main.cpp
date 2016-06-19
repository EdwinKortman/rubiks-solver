#include <iostream>
#include <vector>

class Cube
{
    private:
        int edgeSize;

    public:
        void setEdge(int size);
        int getEdge(void);
        Cube(int size);
};


Cube::Cube(int size)
{
    edgeSize = size;
}

void Cube::setEdge(int size)
{
    edgeSize = size;
}

int Cube::getEdge(void)
{
    return edgeSize;
}


int main(int argc, char **argv)
{
    Cube Cube(3);
    std::cout << "Size of edge: " << Cube.getEdge() << std::endl;
}