#ifndef LAB_03_FACADE_H
#define LAB_03_FACADE_H

#include <memory>
#include "../commands/base_command.h"


class Facade {
public:
    Facade();

    ~Facade() = default;

    // only base + try in one execute
    void execute(std::shared_ptr<BaseCommand<DrawManager>> command);

    void execute(std::shared_ptr<BaseCommand<LoadManager>> command);

    void execute(std::shared_ptr<BaseCommand<SceneManager>> command);

    void execute(std::shared_ptr<BaseCommand<TransformManager>> command);

private:
    std::shared_ptr<DrawManager> drawManager;
    std::shared_ptr<LoadManager> loadManager;
    std::shared_ptr<SceneManager> sceneManager;
    std::shared_ptr<TransformManager> transformManager;
};


#endif //LAB_03_FACADE_H
