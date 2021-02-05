#pragma once
#include "DEFINE_INT.h"
#include "Matrix.h"
#include "Activation.h"
#include <Arduino.h>
class Layer
{
private:
    bool deleteAfter = true;
    bool cacheEnabled = false;

public:
    Activation::ActivationType activationType;
    float *cache = nullptr;
    bool cached = false;
    enum LayerType : uint8_t
    {
        FULLY_CONNECTED = 0,
        CONVOLUTIONAL,
        MAX_POOLING,
		FLATTEN
    };
    Matrix3D *weights;
    Matrix3D *bias;
    INT_MNC layerId;
    void enableCache(bool e);
    bool isCacheEnabled();
    void resetCache();
    Layer(Activation::ActivationType act, INT_MNC l_Id);
    ~Layer();
    virtual float get_result(const Matrix3D &in, const INT_MNC& x,  const INT_MNC& y,  const INT_MNC& z, Layer **layers) = 0;
    virtual void init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix3D *w, Matrix3D *b) = 0;
    virtual void getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const = 0;
};
