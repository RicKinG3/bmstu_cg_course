//
// Created by max on 29.10.23.
//

#ifndef COURSEWORK_BASELIGHT_H
#define COURSEWORK_BASELIGHT_H

#include "object.h"

class BaseLight : public InvisibleObject
{
public:
    BaseLight() = default;
    virtual ~BaseLight() = default;
};


class BaseLightFactory
{
public:
    BaseLightFactory() = default;
    virtual ~BaseLightFactory() = default;

    virtual std::shared_ptr<BaseLight> create() = 0;
};



#endif //COURSEWORK_BASELIGHT_H
