#ifndef SRC_VERTEX_H
#define SRC_VERTEX_H
#include "Point.h"

class Vertex
{
public:
    Vertex() {}
    Vertex(Point &position_, std::vector<size_t> &used_facets_)
            : position{position_}, facets_poligon{used_facets_} { }

    Vertex(Point &position_) : position(position_) { }

    const Point &getPosition() const;
    void setPosition(Point &position_);
//    const std::vector<size_t> getUsedFacets();
//    void setUsedFacets(std::vector<size_t> used_facets_);

private:
    Point position;
    std::vector<size_t> facets_poligon;
};


#endif //SRC_VERTEX_H
