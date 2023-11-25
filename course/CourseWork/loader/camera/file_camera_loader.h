#ifndef LAB_03_FILE_CAMERA_LOADER_H
#define LAB_03_FILE_CAMERA_LOADER_H


#include <fstream>
#include "camera_loader.h"
#include "../../builder/camera/camera_builder.h"


class FileCameraLoader : public CameraLoader {
public:
    FileCameraLoader(const std::string &name);

    ~FileCameraLoader() override = default;

    void open() override;

    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<BaseBuilder> src_builder) override;

private:
    std::shared_ptr<std::ifstream> file;
    std::string filename;

    Point read_position();

    Point read_direction();
};


class FileCameraLoaderCreator : public LoaderCreator {
public:
    FileCameraLoaderCreator() = default;

    ~FileCameraLoaderCreator() override = default;

    std::shared_ptr<BaseLoader> createLoader(const std::string &name) override;
};


#endif //LAB_03_FILE_CAMERA_LOADER_H
