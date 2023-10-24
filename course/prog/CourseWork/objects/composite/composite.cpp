#include "composite.h"

#include <iostream>


Composite::Composite(std::shared_ptr<Object> &object) {
    objects.push_back(object);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &vector) {
    objects = vector;
}


bool Composite::add(const std::shared_ptr<Object> &object) {
    if (object->isVisible()) {
        auto iter = objects.begin();
        while ((*iter)->isVisible())
            iter++;
        objects.insert(iter, object);
    } else
        objects.push_back(object);

    updateCenter();
    return true;
}

bool Composite::remove(const Iterator &iter) {
    objects.erase(iter);
    updateCenter();
    return true;
}


void Composite::updateCenter() {
    Point temp = Point{0, 0, 0};
    size_t count = 0;

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> z;


    for (const auto &object: objects) {
        temp = object->getCenter();
        x.push_back(temp.getX());
        y.push_back(temp.getY());
        z.push_back(temp.getZ());
    }

    if (x.empty() || y.empty() || z.empty())
        center = temp;
    else {
        double newX = *std::max_element(x.begin(), x.end()) + *std::min_element(x.begin(), x.end());
        double newY = *std::max_element(y.begin(), y.end()) + *std::min_element(y.begin(), y.end());
        double newZ = *std::max_element(z.begin(), z.end()) + *std::min_element(z.begin(), z.end());

        center = Point(newX / 2, newY / 2, newZ / 2);
    }
}

Point Composite::getCenter() {
    return center;
}

void Composite::accept(std::shared_ptr<Visitor> visitor) {
    for (const auto &object: objects) {
        object->accept(visitor);
    }
}


Iterator Composite::begin() {
    return objects.begin();
}

Iterator Composite::end() {
    return objects.end();
}
