//
// Created by User on 29.05.2023.
//

#ifndef LAB_03_MANAGER_EXCEPTIONS_H
#define LAB_03_MANAGER_EXCEPTIONS_H

#include "base_exceptions.h"


class ManagerException : public BaseException
{
public:
    ManagerException(std::string filename, std::string classname,
                     int cur_line, const char *time,
                     std::string info = "Manager error"):
            BaseException(filename, classname, cur_line, time, info) {}
};


class NoMainCameraException : public ManagerException
{
public:
    NoMainCameraException(std::string filename, std::string classname,
                          int cur_line, const char *time,
                          std::string info = "No main camera"):
            ManagerException(filename, classname, cur_line, time, info) {};
};

#endif //LAB_03_MANAGER_EXCEPTIONS_H
