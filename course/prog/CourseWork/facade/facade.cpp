#include "facade.h"


Facade::Facade()
{
    drawManager = DrawManagerCreator().getManager();
    loadManager = LoadManagerCreator().getManager();
    sceneManager = SceneManagerCreator().getManager();
    transformManager = TransformManagerCreator().getManager();
}


void Facade::execute(std::shared_ptr<BaseCommand<DrawManager>> command)
{
command->execute(drawManager);
}

void Facade::execute(std::shared_ptr<BaseCommand<LoadManager>> command)
{
command->execute(loadManager);
}

void Facade::execute(std::shared_ptr<BaseCommand<SceneManager>> command)
{
command->execute(sceneManager);
}

void Facade::execute(std::shared_ptr<BaseCommand<TransformManager>> command)
{
command->execute(transformManager);
}
