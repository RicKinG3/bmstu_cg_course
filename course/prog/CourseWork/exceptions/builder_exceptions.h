#ifndef LAB_03_BUILDER_EXCEPTIONS_H
#define LAB_03_BUILDER_EXCEPTIONS_H

#include "base_exceptions.h"


class BuilderException : public BaseException
{
public:
    BuilderException(std::string filename, std::string classname,
                     int cur_line, const char *time,
                     std::string info = "Building error"):
            BaseException(filename, classname, cur_line, time, info) {}
};


class BuildNotStartedException : public BuilderException
{
public:
    BuildNotStartedException(std::string filename, std::string classname,
                             int cur_line, const char *time,
                             std::string info = "Build has not started"):
            BuilderException(filename, classname, cur_line, time, info) {};
};

class BuilderNotRegisteredException  : public BuilderException
{
public:
    BuilderNotRegisteredException(std::string filename, std::string classname,
                                  int cur_line, const char *time,
                                  std::string info = "No fitting registered builder"):
            BuilderException(filename, classname, cur_line, time, info) {};
};


#endif //LAB_03_BUILDER_EXCEPTIONS_H
