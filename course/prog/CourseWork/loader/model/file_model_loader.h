#ifndef LAB_03_FILE_MODEL_LOADER_H
#define LAB_03_FILE_MODEL_LOADER_H

#include <fstream>
#include "model_loader.h"
#include "../../builder/model/model_builder.h"


class FileModelLoader : public ModelLoader {
public:
    FileModelLoader(const std::string &name);

    ~FileModelLoader() override = default;

    void open() override;

    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> srcBuilder) override;

private:
    std::shared_ptr<std::ifstream> file;
    std::string filename;

    int readCount();

    Point readPoint();

    Edge readEdge();
    Face readFace();
};


class FileModelLoaderCreator : public LoaderCreator {
public:
    FileModelLoaderCreator() = default;

    ~FileModelLoaderCreator() override = default;

    std::shared_ptr<BaseLoader> createLoader(const std::string &name) override;
};

#endif //LAB_03_FILE_MODEL_LOADER_H
