#ifndef LAB_03_BASE_COMMANDS_H
#define LAB_03_BASE_COMMANDS_H

#include <memory>

#include "../managers/draw/draw_manager.h"
#include "../managers/load/load_manager.h"
#include "../managers/scene/scene_manager.h"
#include "../managers/transform/transform_manager.h"


template <typename Manager>
class BaseCommand
{
public:
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<Manager>) = 0;
};


#endif //LAB_03_BASE_COMMANDS_H
