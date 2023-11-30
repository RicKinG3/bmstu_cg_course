
#ifndef SRC_LIGHT_H
#define SRC_LIGHT_H
#include <vector>
#include "/usr/include/eigen3/Eigen/Dense"
#include "config.hpp"

class Light
{
public:
    Light(Eigen::Matrix4f &transMat);
    Light(){};

    void setShadowMap(std::vector<std::vector<double>> &setShadowMap);
    std::vector<std::vector<double>> &getShadowMap();
    void clearShadowMap();

    void setAngles(int x_angle_, int y_angle);
    int getXAngle();
    int getYAngle();

    void setTransMtr(Eigen::Matrix4f &mtr);
    Eigen::Matrix4f &getTransMtr();

private:
    std::vector<std::vector<double>> shadow_map;
    Eigen::Matrix4f trans_mtr;
    int x_angle, y_angle;
};

#endif //SRC_LIGHT_H
