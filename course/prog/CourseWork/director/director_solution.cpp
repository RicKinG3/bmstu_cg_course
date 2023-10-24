//
// Created by User on 02.06.2023.
//

// TODO: Director solution this delete

#include "director_solution.h"
#include "../exceptions/director_exceptions.h"

DirectorSolution::DirectorSolution() {
    static auto directorMap = std::make_shared<callback_map>();
    callback = directorMap;
}


std::shared_ptr<BaseDirectorCreator> DirectorSolution::createCreator(const std::string &objectType) {
    callback_map::const_iterator it = callback->find(objectType);

    if (it == callback->end()) {
        time_t cur_time = time(NULL);

        throw DirectorUndefined(__FILE__, __func__, __LINE__,
                                ctime(&cur_time));
    }

    return it->second;
}

bool DirectorSolution::registrate(const std::string objectType, std::shared_ptr<BaseDirectorCreator> directorCreator) {
    if (check(objectType)) {
        callback->erase(objectType);
    }

    return callback->insert(callback_map::value_type(objectType, directorCreator)).second;
}

bool DirectorSolution::check(const std::string &objectType) {
    return callback->count(objectType) > 0;
}