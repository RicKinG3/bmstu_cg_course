#ifndef LAB_03_SCENE_COMMANDS_H
#define LAB_03_SCENE_COMMANDS_H


#include <string>
#include <memory>
#include "../base_command.h"
#include "../../drawer/base_drawer.h"


template <typename Manager>
class BaseSceneCommand : public BaseCommand<Manager> { };


template <typename Manager>
class DrawSceneCommand : public BaseSceneCommand<Manager>
{
    using Action = void(Manager::*)(std::shared_ptr<BaseDrawer>&);

public:
    explicit DrawSceneCommand(Action a, std::shared_ptr<BaseDrawer> &drawer_) : act(a)
    {
        drawer = drawer_;
    }

    void execute(std::shared_ptr<Manager> mng) override { ((*mng).*act)(drawer); }

private:
    Action act;
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //LAB_03_SCENE_COMMANDS_H
