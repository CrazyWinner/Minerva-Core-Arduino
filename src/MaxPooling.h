#pragma once
#include "DEFINE_INT.h"
#include "Layer.h"

class MaxPooling : public Layer
{
private:
    INT_MNC pooling_size_X;
    INT_MNC pooling_size_Y;
    INT_MNC i_X, i_Y, i_Z;

public:
    MaxPooling(const INT_MNC& sizeX, const INT_MNC& sizeY, INT_MNC l_Id);
    float get_result(const Matrix &in, INT_MNC p_id, Layer **layers);
    void init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix *w, Matrix *b);
    void getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const;
};
