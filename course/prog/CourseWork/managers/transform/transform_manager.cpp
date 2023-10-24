#include "transform_manager.h"
#include "../../visitor/transform_visitor.h"
#include "../../transformer/transformer_factory.h"

void TransformManager::transform(size_t id, const Point &move_params,
                                 const Point &scale_params,
                                 const Point &rotate_params) {
    auto object_iter = SceneManagerCreator().getManager()->getScene()->getObjectIter(id);
    //(*object_iter)->transform(move_params, scale_params, rotate_params);
    auto transformer = TransformerFactory(rotate_params, scale_params, move_params).create();
    std::shared_ptr<Visitor> visitor = TransformVisitorFactory(transformer).create();
    (*object_iter)->accept(visitor);
}


std::shared_ptr<TransformManager> TransformManagerCreator::getManager() {
    if (manager == nullptr) {
        createInstance();
    }

    return manager;
}

void TransformManagerCreator::createInstance() {
    static auto _manager = std::make_shared<TransformManager>();
    manager = _manager;
}
