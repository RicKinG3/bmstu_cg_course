#include "model_builder.h"
#include "../../exceptions/builder_exceptions.h"


bool ModelBuilder::isBuilt()
{
    return modelStruct != nullptr;
}

void ModelBuilder::reset()
{
    modelStruct.reset();
}

void ModelBuilder::build()
{
    modelStruct = std::make_shared<FrameModelStructure>();
}


void ModelBuilder::buildCenter(const Point &center)
{
    if (modelStruct == nullptr)
    {
        time_t cur_time = time(NULL);
        throw BuildNotStartedException(__FILE__, __func__, __LINE__,
                                       ctime(&cur_time));
    }

    modelStruct->setCenter(center);
}

void ModelBuilder::buildPoint(const Point &point)
{
    if (modelStruct == nullptr)
    {
        time_t cur_time = time(NULL);
        throw BuildNotStartedException(__FILE__, __func__, __LINE__,
                                       ctime(&cur_time));
    }

    modelStruct->addPoint(point);
}

void ModelBuilder::buildEdge(const Edge &edge)
{
    if (modelStruct == nullptr)
    {
        time_t cur_time = time(NULL);
        throw BuildNotStartedException(__FILE__, __func__, __LINE__,
                                       ctime(&cur_time));
    }

    modelStruct->addEdge(edge);
}

void ModelBuilder::buildFace(const Face &face)
{
    if (modelStruct == nullptr)
    {
        time_t cur_time = time(NULL);
        throw BuildNotStartedException(__FILE__, __func__, __LINE__,
                                       ctime(&cur_time));
    }

    modelStruct->addFace(face);
}

std::shared_ptr<Object> ModelBuilder::get()
{
    return std::make_shared<FrameModel>(modelStruct);
}


std::shared_ptr<BaseBuilder> ModelBuilderCreator::createBuilder()
{
    return std::make_shared<ModelBuilder>();
}
