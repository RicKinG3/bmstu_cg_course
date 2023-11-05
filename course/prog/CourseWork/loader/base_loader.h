#ifndef LAB_03_BASE_LOADER_H
#define LAB_03_BASE_LOADER_H

#include <string>
#include <fstream>
#include "../builder/base_builder.h"
#include "../objects/object.h"


class BaseLoader {
public:
    BaseLoader() = default;

    virtual ~BaseLoader() = default;

    virtual void open() = 0;

    virtual void close() = 0;

    virtual std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> builder) = 0;
};


class LoaderCreator {
public:
    LoaderCreator() = default;

    virtual ~LoaderCreator() = default;

    virtual std::shared_ptr<BaseLoader> createLoader(const std::string &name) = 0;
};


#endif //LAB_03_BASE_LOADER_H
