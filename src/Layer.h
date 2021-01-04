#pragma once
#include "Matrix.h"
#include "Activation.h"
#include "ActivationFunctions.h"
#include <math.h>       /* exp */
#include<algorithm> 
#include <vector>
namespace LightNetwork
{
    class Layer
    {
    private:
        float learning_rate;
        Activation* activator;
        Matrix* weights;
        Matrix* bias;     
        int layerId;   
    public:
        int i_size,p_count;
        Layer(int i_s, int p_c, Activation* act, int l_Id);
        ~Layer();
        float get_result(Matrix& in, int p_id, std::vector<Layer*>* layers);
       
    };

} // namespace LightNetwork