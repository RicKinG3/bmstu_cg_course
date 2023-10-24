//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_CONFIG_EXCEPTIONS_H
#define LAB_03_CONFIG_EXCEPTIONS_H


#include "base_exceptions.h"


class ConfigException : public BaseException
{
public:
    ConfigException(std::string filename, std::string classname,
                    int cur_line, const char *time,
                    std::string info = "Configuration error"):
            BaseException(filename, classname, cur_line, time, info) {}
};


class NoFileException : public ConfigException
{
public:
    NoFileException(std::string filename, std::string classname,
                    int cur_line, const char *time,
                    std::string info = "No file"):
            ConfigException(filename, classname, cur_line, time, info) {};
};

class ReadException : public ConfigException
{
public:
    ReadException(std::string filename, std::string classname,
                  int cur_line, const char *time,
                  std::string info = "Reading error"):
            ConfigException(filename, classname, cur_line, time, info) {};
};

class NoConfigException : public ConfigException
{
public:
    NoConfigException(std::string filename, std::string classname,
                      int cur_line, const char *time,
                      std::string info = "No configuration"):
            ConfigException(filename, classname, cur_line, time, info) {};
};


#endif //LAB_03_CONFIG_EXCEPTIONS_H
