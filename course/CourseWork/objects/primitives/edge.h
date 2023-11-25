//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_EDGE_H
#define LAB_03_EDGE_H


#include <memory>


class Edge
{
public:
    Edge() = default;
    Edge(const std::size_t &startIndex, const std::size_t &endIndex);

    Edge(const Edge &) = default;

    ~Edge() = default;

    std::size_t getStartIndex() const;
    std::size_t getEndIndex() const;

    void setStartIndex(const std::size_t &srcStartIndex);
    void setEndIndex(const std::size_t &srcEndIndex);

private:
    std::size_t startIndex;
    std::size_t endIndex;
};


#endif //LAB_03_EDGE_H
