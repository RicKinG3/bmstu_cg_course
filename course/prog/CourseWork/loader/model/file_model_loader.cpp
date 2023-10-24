#include "file_model_loader.h"
#include "../../exceptions/loader_exceptions.h"

#include <iostream>


FileModelLoader::FileModelLoader(const std::string &name) {
    file = std::make_shared<std::ifstream>();
    filename = name;
}


void FileModelLoader::open() {
    file->open(filename);
    if (!file) {
        time_t cur_time = time(NULL);
        throw NoFileException(__FILE__, __func__, __LINE__,
                              ctime(&cur_time));
    }
}

void FileModelLoader::close() {
    if (!file) {
        time_t cur_time = time(NULL);
        throw NoFileException(__FILE__, __func__, __LINE__,
                              ctime(&cur_time));
    }
    file->close();
}

std::shared_ptr<Object> FileModelLoader::load(std::shared_ptr<BaseBuilder> srcBuilder) {
    std::shared_ptr<BaseModelBuilder> builder = std::dynamic_pointer_cast<BaseModelBuilder>(srcBuilder);

    open();

    int pointsCount = readCount();

    builder->buildCenter(readPoint());

    for (int i = 0; i < pointsCount; i++)
        builder->buildPoint(readPoint());

    int edges_count = readCount();

    for (int i = 0; i < edges_count; i++)
        builder->buildEdge(readEdge());

    int face_count = readCount();
    for (int i = 0; i < face_count; i++)
        builder->buildFace(readFace());

    close();

    return builder->get();
}

int FileModelLoader::readCount() {
    int count = 0;
    *file >> count;

    return count;
}

Point FileModelLoader::readPoint() {
    double x = 0, y = 0, z = 0;
    *file >> x >> y >> z;

    return Point{x, y, z};
}

Edge FileModelLoader::readEdge() {
    size_t startIndex = 0, endIndex = 0;
    *file >> startIndex >> endIndex;

    return Edge{startIndex, endIndex};
}


Face FileModelLoader::readFace() {
    size_t point_a = 0, point_b = 0,  point_c;
    *file >> point_a >> point_b >> point_c;

    return Face{point_a, point_b, point_c};
}


std::shared_ptr<BaseLoader> FileModelLoaderCreator::createLoader(const std::string &name) {
    return std::make_shared<FileModelLoader>(name);
}
