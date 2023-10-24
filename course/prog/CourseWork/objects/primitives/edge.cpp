#include "edge.h"

Edge::Edge(const std::size_t &startIndex_, const std::size_t &endIndex_): startIndex(startIndex_), endIndex(endIndex_)
{
}

std::size_t Edge::getStartIndex() const
{
    return startIndex;
}

std::size_t Edge::getEndIndex() const
{
    return endIndex;
}

void Edge::setStartIndex(const size_t &srcStartIndex)
{
    startIndex = srcStartIndex;
}

void Edge::setEndIndex(const size_t &srcEndIndex)
{
    endIndex = srcEndIndex;
}
