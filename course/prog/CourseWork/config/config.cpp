#include "config.h"
#include "../exceptions/config_exceptions.h"


Config::Config() {
    filename = CFG_FILE;
    file = std::make_shared<std::ifstream>();

    file->open(filename);

    if (!file) {
        time_t cur_time = time(NULL);
        throw NoFileException(__FILE__, __func__, __LINE__,
                              ctime(&cur_time));
    }
}

Config::~Config() {
    file->close();
}


void Config::readConfigFile() {
    time_t cur_time = time(NULL);

    if (!std::getline(*file, guiLib)) {
        throw ReadException(__FILE__, __func__, __LINE__,
                            ctime(&cur_time));
    }

    if (!std::getline(*file, source)) {
        throw ReadException(__FILE__, __func__, __LINE__,
                            ctime(&cur_time));
    }

    if (!std::getline(*file, modelType)) {
        throw ReadException(__FILE__, __func__, __LINE__,
                            ctime(&cur_time));
    }
}

void Config::getConfigInfo() {
    readConfigFile();

    if (source == "textfile") {
        LoaderSolution().registrate("camera", std::make_shared<FileCameraLoaderCreator>());
        LoaderSolution().registrate("model", std::make_shared<FileModelLoaderCreator>());
    }

    if (modelType == "frame") {
        DirectorSolution().registrate("camera", std::make_shared<CameraDirectorCreator>());
        DirectorSolution().registrate("model", std::make_shared<ModelDirectorCreator>());
    }
}


ConfigCreator::ConfigCreator() {
    filename = CFG_FILE;
}

std::shared_ptr<BaseConfig> ConfigCreator::createConfig() {
    config = std::make_shared<Config>();

    if (config == nullptr) {
        createInstance();
    }

    return config;
}

void ConfigCreator::createInstance() {
    config = std::make_shared<Config>();
}
