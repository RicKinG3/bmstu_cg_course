#ifndef LAB_03_CONFIG_H
#define LAB_03_CONFIG_H

#include <string>
#include <fstream>
#include <iostream>

#include "base_config.h"
#include "../loader/loader_solution.h"
#include "../loader/camera/file_camera_loader.h"
#include "../loader/model/file_model_loader.h"
#include "../director/model/model_director.h"
#include "../director/camera/camera_director.h"
#include "../director/director_solution.h"

#define CFG_FILE "../data/config.txt"


class Config : public BaseConfig {
public:
    Config();

    ~Config() override;

    virtual void getConfigInfo() override;

private:
    std::shared_ptr<std::ifstream> file;
    std::string filename;

    std::string guiLib;
    std::string source;
    std::string modelType;

    void readConfigFile();
};


class ConfigCreator : public BaseConfigCreator {
public:
    explicit ConfigCreator();

    ~ConfigCreator() override = default;

    std::shared_ptr<BaseConfig> createConfig() override;

private:
    void createInstance();

    std::shared_ptr<Config> config;
    std::string filename;
};

#endif //LAB_03_CONFIG_H
