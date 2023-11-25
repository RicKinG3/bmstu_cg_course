//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_LOADER_EXCEPTIONS_H
#define LAB_03_LOADER_EXCEPTIONS_H


#include "base_exceptions.h"


class LoaderException : public BaseException
{
public:
    LoaderException(std::string filename, std::string classname,
                    int cur_line, const char *time,
                    std::string info = "Load error"):
            BaseException(filename, classname, cur_line, time, info) {}
};


class NoFileException : public LoaderException
{
public:
    NoFileException(std::string filename, std::string classname,
                    int cur_line, const char *time,
                    std::string info = "No file"):
            LoaderException(filename, classname, cur_line, time, info) {};
};

class IncorrectInputException : public LoaderException
{
public:
    IncorrectInputException(std::string filename, std::string classname,
                            int cur_line, const char *time,
                            std::string info = "Incorrect input"):
            LoaderException(filename, classname, cur_line, time, info) {};
};


#endif //LAB_03_LOADER_EXCEPTIONS_H
