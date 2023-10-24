#include "camera_director.h"
#include "../../exceptions/director_exceptions.h"


CameraDirector::CameraDirector(std::shared_ptr<BaseBuilder> builder_) {
    builder = builder_;
}


std::shared_ptr<Object> CameraDirector::create() {
    time_t cur_time = time(NULL);

    if (loader == nullptr) {
        throw NoLoaderException(__FILE__, __func__, __LINE__,
                                ctime(&cur_time));
    }

    if (builder == nullptr) {
        throw NoBuilderException(__FILE__, __func__, __LINE__,
                                 ctime(&cur_time));
    }

    return loader->load(builder);
}

void CameraDirector::setLoader(std::shared_ptr<BaseLoader> loaderArg) {
    loader = loaderArg;
}


std::shared_ptr<BaseLoadDirector> CameraDirectorCreator::getDirector(const std::string &fname) {
    if (director == nullptr) {
        create_instance(fname);
    }

    return director;
}

void CameraDirectorCreator::create_instance(const std::string &nameArg) {
    auto config_solution = std::make_shared<ConfigSolution>();
    config_solution->registrate(ConfigCreator().createConfig());
    config_solution->createCreator()->getConfigInfo();

    director = std::make_shared<CameraDirector>(CameraBuilderCreator().createBuilder());
    director->setLoader(LoaderSolution().create_creator("camera")->createLoader(nameArg));
}
