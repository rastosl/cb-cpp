#ifndef _MODEL_H
#define _MODEL_H

#include <memory>

#include "transformationmatrix4x4.h"


class Model
{
public:
    Model();
    ~Model();

    const TransformationMatrix4x4& getCoordinates();

private:
    struct ModelImpl;
    std::unique_ptr<ModelImpl> impl;
};

#endif // !_MODEL_H
