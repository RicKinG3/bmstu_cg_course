#include "loader_solution.h"
#include "../exceptions/director_exceptions.h"

LoaderSolution::LoaderSolution()
{
    static auto loaderMap = std::make_shared<callback_map>();
    callback = loaderMap;
}


std::shared_ptr<LoaderCreator> LoaderSolution::create_creator(const std::string &objectType)
{
    callback_map::const_iterator it = callback->find(objectType);

    if (it == callback->end())
    {
        time_t cur_time = time(NULL);
        throw NoLoaderException(__FILE__, __func__, __LINE__,
                                ctime(&cur_time));
    }

    return it->second;
}

bool LoaderSolution::registrate(const std::string objectType, std::shared_ptr<LoaderCreator> loaderCreator)
{
    if (check(objectType))
    {
        callback->erase(objectType);
    }

    return callback->insert(callback_map::value_type(objectType, loaderCreator)).second;
}

bool LoaderSolution::check(const std::string &object_type)
{
    return callback->count(object_type) > 0;
}
