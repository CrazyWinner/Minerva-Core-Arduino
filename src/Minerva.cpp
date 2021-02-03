#include "Minerva.h"
void Minerva::importFromFile(NeuralNetwork& network, const char *fileName) {}
void Minerva::importFromMemory(NeuralNetwork& network, const void *p2)
{

}

void Minerva::importFromMemory_P(NeuralNetwork& network, const void *p2)
{
	void *p = (void*)p2;
    uint16_t layerCount;
    memcpy_P(&layerCount, p, sizeof(layerCount));
    p += sizeof(layerCount);
    uint32_t inX1, inY1, inZ1;
    memcpy_P(&inX1, p, sizeof(inX1));
    p += sizeof(inX1);
    memcpy_P(&inY1, p, sizeof(inY1));
    p += sizeof(inY1);
    memcpy_P(&inZ1, p, sizeof(inZ1));
    p += sizeof(inZ1);
    INT_MNC inX = inX1;
    INT_MNC inY = inY1;
    INT_MNC inZ = inZ1;
	network.init(inX, inY, inZ, layerCount);
    Activation::ActivationType type;
    for (uint16_t i = 0; i < layerCount; i++)
    {
        memcpy_P(&type, p, sizeof(type));
        p += sizeof(type);
        Layer *l;
        switch (type)
        {
        case Layer::FULLY_CONNECTED:
        {
            Activation::ActivationType activationType;
            uint32_t p_count;
            memcpy_P(&activationType, p, sizeof(activationType));
            p += sizeof(activationType);
            p += sizeof(float);
            memcpy_P(&p_count, p, sizeof(p_count));
            p += sizeof(p_count);
            l = new FullyConnected(p_count, activationType, i);
            MNC::Matrix *w = new MNC::Matrix(p_count, inX * inY * inZ, (float *)p, true);
            p += inX * inY * inZ * p_count * sizeof(float);
            MNC::Matrix *b = new MNC::Matrix(p_count, 1, (float *)p, true);
            p += p_count * sizeof(float);
            l->init(inX, inY, inZ, w, b);
        }
        break;
        default:
            break;
        }

        l->getOutDimensions(inX, inY, inZ);
        network.layers[i] = l;
    }
}
