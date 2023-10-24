//
// Created by User on 02.06.2023.
//

#ifndef LAB_03_DIRECTOR_SOLUTION_H
#define LAB_03_DIRECTOR_SOLUTION_H

#include "base_load_director.h"
#include <map>
#include <iostream>

class DirectorSolution {
public:
    DirectorSolution();

    ~DirectorSolution() = default;

    std::shared_ptr<BaseDirectorCreator> createCreator(const std::string &objectType);

    bool registrate(const std::string objectType, std::shared_ptr<BaseDirectorCreator> directorCreator);

    bool check(const std::string &objectType);

private:
    using callback_map = std::map<const std::string, std::shared_ptr<BaseDirectorCreator>>;
    std::shared_ptr<callback_map> callback;
};


#endif //LAB_03_DIRECTOR_SOLUTION_H
