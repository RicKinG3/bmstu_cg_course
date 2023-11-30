#ifndef SRC_POLYGON_H
#define SRC_POLYGON_H

#include <iostream>
#include <vector>

class Polygon {
public:
    Polygon() {}

    Polygon(std::vector<size_t> polygon_vertices_) : polygon_vertices{polygon_vertices_} {}

    const std::vector<size_t> getUsedVertices();

//    void setUsedVertices(std::vector<size_t> usedVertices_);

private:
    std::vector<size_t> polygon_vertices;
};


#endif //SRC_POLYGON_H
