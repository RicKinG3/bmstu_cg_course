#ifndef LAB_03_BASE_LOAD_DIRECTOR_H
#define LAB_03_BASE_LOAD_DIRECTOR_H

#include <string>

#include "../builder/base_builder.h"
#include "../loader/base_loader.h"


class BaseLoadDirector {
public:
    // TODO: + const with param +  builder inside

    virtual ~BaseLoadDirector() = default;

    virtual std::shared_ptr<Object> create() = 0;

    virtual void setLoader(std::shared_ptr<BaseLoader> loaderArg) = 0;
};

class BaseDirectorCreator {
public:

    virtual ~BaseDirectorCreator() = default;

    virtual std::shared_ptr<BaseLoadDirector> getDirector(const std::string &fname) = 0;
};


#endif //LAB_03_BASE_LOAD_DIRECTOR_H
