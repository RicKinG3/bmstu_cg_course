#ifndef LAB_03_LOADER_SOLUTION_H
#define LAB_03_LOADER_SOLUTION_H


#include <map>
#include <memory>
#include <string>

#include "base_loader.h"


class LoaderSolution
{
public:
    LoaderSolution();
    ~LoaderSolution() = default;

    std::shared_ptr<LoaderCreator> create_creator(const std::string &objectType);
    bool registrate(const std::string objectType, std::shared_ptr<LoaderCreator> loaderCreator);
    bool check(const std::string &object_type);

private:
    using callback_map = std::map<const std::string, std::shared_ptr<LoaderCreator>>;
    std::shared_ptr<callback_map> callback;
};




#endif //LAB_03_LOADER_SOLUTION_H
