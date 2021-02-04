#pragma once
#include "DEFINE_INT.h"
#include "Layer.h"
class Conv2D : public Layer
{
private:
    INT_MNC filter_size_X, filter_size_Y, filter_count, padding_X, padding_Y;
    INT_MNC i_X, i_Y, i_Z;

public:
    Conv2D(const INT_MNC& fsx, const INT_MNC& fsy, const INT_MNC& f_c, const INT_MNC& pd_x, const INT_MNC& pd_y, Activation::ActivationType act,  INT_MNC l_Id);
    float get_result(const Matrix &in, INT_MNC p_id, Layer **layers);
    void init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix *w, Matrix *b);
    void getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const;
};
