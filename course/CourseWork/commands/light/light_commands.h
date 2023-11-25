//
// Created by max on 29.10.23.
//

#ifndef COURSEWORK_LIGHT_COMMANDS_H
#define COURSEWORK_LIGHT_COMMANDS_H

#include "base_command.h"

template<typename Manager>
class BaselightCommand : public BaseCommand<Manager> {
};

template<typename Manager>
class AddLightCommand : public BaselightCommand<Manager> {
    using Action = void (Manager::*)(const Point &, const Point &);

public:
    explicit AddLightCommand(Action a, Point &pos, Point &dir) : act(a) {
        position = pos;
        direction = dir;
    }

    void execute(std::shared_ptr<Manager> mng) override { ((*mng).*act)(position, direction); }

private:
    Action act;
    Point position, direction;
};




#endif //COURSEWORK_LIGHT_COMMANDS_H
