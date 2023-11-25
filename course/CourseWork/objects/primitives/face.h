//
// Created by max on 24.10.23.
//

#ifndef COURSEWORK_FACE_H
#define COURSEWORK_FACE_H

#include <vector>
#include "point.h"
#include <iostream>

#include <array>


class Face {
public:
    Face() = default;

    Face(const std::size_t &point_a, const std::size_t &point_b, const std::size_t &point_c);

    Face(const Face &) = default;

    ~Face() = default;

    std::size_t operator[](std::size_t index) const {
        // Add bounds checking if needed
        return face[index];
    }

    friend std::ostream &operator<<(std::ostream &os, const Face &face) {
        os << face[0] << " " << face[1] << " " << face[2];
        return os;
    }

    std::size_t getFaceX() { return face[0]; }

    std::size_t getFaceY() { return face[1]; }

    std::size_t getFaceZ() { return face[2]; }

private:
    std::size_t face[3];
};


#endif //COURSEWORK_FACE_H
