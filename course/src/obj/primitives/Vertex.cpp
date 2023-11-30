#include "Vertex.h"


const Point &Vertex::getPosition() const { return position; }

void Vertex::setPosition(Point &position_) { position = position_; }

//
//const std::vector<size_t> Vertex::getUsedFacets() { return facets_poligon; }
//
//void Vertex::setUsedFacets(std::vector<size_t> used_facets_) { facets_poligon = used_facets_; }