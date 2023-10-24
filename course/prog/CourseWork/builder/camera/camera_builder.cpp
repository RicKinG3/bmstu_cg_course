#include "camera_builder.h"


bool CameraBuilder::isBuilt()
{
    return camera != nullptr;
}

void CameraBuilder::reset()
{
    camera.reset();
}

void CameraBuilder::build()
{
    camera = std::make_shared<Camera>();
}


void CameraBuilder::buildPosition(const Point &position)
{
    if (camera != nullptr)
    {
        auto camera_structure = std::make_shared<CameraStructure>();
        camera_structure->setPosition(position);
        camera = std::make_shared<Camera>(camera_structure);
    }
    else
    {
        auto camera_structure = std::make_shared<CameraStructure>(position, Point{0, 0, 0});
        camera = std::make_shared<Camera>(camera_structure);
    }
}

void CameraBuilder::buildDirection(const Point &direction)
{
    if (camera != nullptr)
    {
        auto camera_structure = std::make_shared<CameraStructure>();
        camera_structure->setDirection(direction);
        camera = std::make_shared<Camera>(camera_structure);
    }
    else
    {
        auto camera_structure = std::make_shared<CameraStructure>(Point{0, 0, 0}, direction);
        camera = std::make_shared<Camera>(camera_structure);
    }
}


std::shared_ptr<Object> CameraBuilder::get()
{
    return camera;
}


std::shared_ptr<BaseBuilder> CameraBuilderCreator::createBuilder()
{
    return std::make_shared<CameraBuilder>();
}
