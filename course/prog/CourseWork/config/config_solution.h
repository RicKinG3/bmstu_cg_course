#ifndef LAB_03_CONFIG_SOLUTION_H
#define LAB_03_CONFIG_SOLUTION_H

#include "base_config.h"


class ConfigSolution
{
public:
    ConfigSolution() = default;
    ~ConfigSolution() = default;

    std::shared_ptr<BaseConfig> createCreator();
    void registrate(std::shared_ptr<BaseConfig> configArg);

private:
    std::shared_ptr<BaseConfig> config;
};



#endif //LAB_03_CONFIG_SOLUTION_H
