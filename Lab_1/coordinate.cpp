#include <iostream>

#include "coordinate.h"


Coordinate::Coordinate(int x, int y) {
    xco = x;
    yco = y;
};


void Coordinate::display() {
    std::cout << xco << "," << yco << std::endl;
}

bool Coordinate::isEqual(Coordinate c1, Coordinate c2) {
    return (c1.xco == c2.xco && c1.yco == c2.yco);
}