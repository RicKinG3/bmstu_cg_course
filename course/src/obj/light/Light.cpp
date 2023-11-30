#include "Light.h"


std::vector<std::vector<double>> &Light::getShadowMap() { return shadow_map; }

Light::Light(Eigen::Matrix4f &transMatrix_) {
    trans_mtr = transMatrix_;
    for (size_t i = 0; i < LIGHT_SHADOW_X; i++) { shadow_map.push_back(std::vector<double>(LIGHT_SHADOW_Y, 0)); }
}

void Light::setShadowMap(std::vector<std::vector<double>> &setShadowMap) {
    shadow_map = setShadowMap;
}

void Light::clearShadowMap() {
    for (size_t i = 0; i < shadow_map.size(); i++) {
        for (size_t j = 0; j < shadow_map.at(0).size(); j++)
            shadow_map.at(i).at(j) = 0;
    }
}

void Light::setAngles(int x_angle_, int y_angle) {
    x_angle = x_angle_;
    y_angle = y_angle;
}

int Light::getXAngle() { return x_angle; }

int Light::getYAngle() { return y_angle; }

Eigen::Matrix4f &Light::getTransMtr() { return trans_mtr; }

void Light::setTransMtr(Eigen::Matrix4f &mtr) { trans_mtr = mtr; }