#include "model_director.h"
#include "../../exceptions/director_exceptions.h"
#include "../../builder/model/model_builder.h"


ModelDirector::ModelDirector(std::shared_ptr<BaseBuilder> builder_) {
    builder = builder_;
}


std::shared_ptr<Object> ModelDirector::create() {
    time_t cur_time = time(NULL);

    if (loader == nullptr) {
        throw NoLoaderException(__FILE__, __func__, __LINE__,
                                ctime(&cur_time));
    }

    if (builder == nullptr) {
        throw NoBuilderException(__FILE__, __func__, __LINE__,
                                 ctime(&cur_time));
    }

    builder->build();

    return loader->load(builder);
}

void ModelDirector::setLoader(std::shared_ptr<BaseLoader> loaderArg) {
    loader = loaderArg;
}

std::shared_ptr<BaseLoadDirector> ModelDirectorCreator::getDirector(const std::string &fname) {
    if (director == nullptr) {
        create_instance(fname);
    }

    return director;
}

void ModelDirectorCreator::create_instance(const std::string &nameArg) {
    auto config_solution = std::make_shared<ConfigSolution>();
    config_solution->registrate(ConfigCreator().createConfig());
    config_solution->createCreator()->getConfigInfo();

    director = std::make_shared<ModelDirector>(ModelBuilderCreator().createBuilder());
    director->setLoader(LoaderSolution().create_creator("model")->createLoader(nameArg));
}
