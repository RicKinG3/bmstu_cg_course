#ifndef LAB_03_MODEL_DIRECTOR_H
#define LAB_03_MODEL_DIRECTOR_H


#include "../base_load_director.h"
#include "../../loader/loader_solution.h"
#include "../director_solution.h"
#include "../../loader/base_loader.h"
#include "../../builder/base_builder.h"
#include "../../config/config_solution.h"
#include "../../config/config.h"


class ModelDirector : public BaseLoadDirector {
public:

    ModelDirector(std::shared_ptr<BaseBuilder> builder_);

    ~ModelDirector() override = default;

    std::shared_ptr<Object> create() override;

    void setLoader(std::shared_ptr<BaseLoader> loaderArg) override;


private:
    std::shared_ptr<BaseLoader> loader;
    std::shared_ptr<BaseBuilder> builder;
};


class ModelDirectorCreator : public BaseDirectorCreator {
public:
    ModelDirectorCreator() = default;

    ~ModelDirectorCreator() = default;

    std::shared_ptr<BaseLoadDirector> getDirector(const std::string &fname) override;

private:
    void create_instance(const std::string &nameArg);

    std::shared_ptr<ModelDirector> director;
};

#endif //LAB_03_MODEL_DIRECTOR_H
