#include "model.h"

#include "transformationmatrix4x4.h"


struct Model::ModelImpl
{
    void initCoordinates();

    TransformationMatrix4x4 coordinates;
};

void Model::ModelImpl::initCoordinates()
{
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            coordinates[r][c] = r * 4 + c;
        }
    }
}


Model::Model()
    :impl(std::make_unique<ModelImpl>())
{
    impl->initCoordinates();
}

Model::~Model() = default;

const TransformationMatrix4x4& Model::getCoordinates()
{
    return impl->coordinates;
}
