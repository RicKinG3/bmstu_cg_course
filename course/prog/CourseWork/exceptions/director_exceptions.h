#ifndef LAB_03_DIRECTOR_EXCEPTIONS_H
#define LAB_03_DIRECTOR_EXCEPTIONS_H


#include "base_exceptions.h"


class DirectorException : public BaseException {
public:
    DirectorException(std::string filename, std::string classname,
                      int cur_line, const char *time,
                      std::string info = "Director error") :
            BaseException(filename, classname, cur_line, time, info) {}
};


class NoLoaderException : public DirectorException {
public:
    NoLoaderException(std::string filename, std::string classname,
                      int cur_line, const char *time,
                      std::string info = "No loader") :
            DirectorException(filename, classname, cur_line, time, info) {};
};

class DirectorUndefined : public DirectorException {
public:
    DirectorUndefined(std::string filename, std::string classname,
                      int cur_line, const char *time,
                      std::string info = "Director Undefined") :
            DirectorException(filename, classname, cur_line, time, info) {};
};

class NoBuilderException : public DirectorException {
public:
    NoBuilderException(std::string filename, std::string classname,
                       int cur_line, const char *time,
                       std::string info = "No builder") :
            DirectorException(filename, classname, cur_line, time, info) {};
};


#endif //LAB_03_DIRECTOR_EXCEPTIONS_H
