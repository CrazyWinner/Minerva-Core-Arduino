#pragma once
#include "Layer.h"
#include "DEFINE_INT.h"
class FullyConnected : public Layer
{
private:
    INT_MNC i_size, p_count;

public:
    float get_result(const MNC::Matrix &in, INT_MNC p_id, Layer **layers);
    FullyConnected(INT_MNC p_c, Activation::ActivationType act, INT_MNC l_Id);
    void init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, MNC::Matrix *w, MNC::Matrix *b);
    void getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const;
};
