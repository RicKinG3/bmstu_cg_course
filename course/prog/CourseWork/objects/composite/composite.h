
#ifndef LAB_03_COMPOSITE_H
#define LAB_03_COMPOSITE_H

#include <vector>
#include "../object.h"
#include <algorithm>

class Composite : public Object
{
public:
    Composite() = default;

    explicit Composite(std::shared_ptr <Object> &object);

    explicit Composite(const std::vector <std::shared_ptr<Object>> &vector);

    ~Composite() = default;


    bool add(const std::shared_ptr <Object> &element) override;

    bool remove(const Iterator &iter) override;

    virtual Point getCenter() override;

    void accept(std::shared_ptr<Visitor> visitor, Eigen::Matrix4f mtr, std::shared_ptr<Light> light, size_t bufW, size_t bufH) override;

    Iterator begin() override;

    Iterator end() override;

private:
    void updateCenter();

    Point center;
    std::vector <std::shared_ptr<Object>> objects;
};

#endif //LAB_03_COMPOSITE_H
