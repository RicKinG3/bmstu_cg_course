//
// Created by max on 30.11.23.
//

#ifndef SRC_POLYGON_H
#define SRC_POLYGON_H

#include <iostream>
#include <vector>

class Polygon {
public:
    Polygon() {}

    Polygon(std::vector <size_t> usedVertices_) : usedVertices(usedVertices_) {}

    const std::vector <size_t> getUsedVertices();

    void setUsedVertices(std::vector <size_t> usedVertices_);

private:
    std::vector <size_t> usedVertices;
};


#endif //SRC_POLYGON_H
