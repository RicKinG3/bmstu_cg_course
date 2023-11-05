#ifndef LAB_03_BASE_CONFIG_H
#define LAB_03_BASE_CONFIG_H

#include <memory>
#include <string>


class BaseConfig
{
public:
    BaseConfig() = default;
    virtual ~BaseConfig() = default;

    virtual void getConfigInfo() = 0;
};


class BaseConfigCreator
{
public:
    BaseConfigCreator() = default;
    virtual ~BaseConfigCreator() = default;

    virtual std::shared_ptr<BaseConfig> createConfig() = 0;
};


#endif //LAB_03_BASE_CONFIG_H
