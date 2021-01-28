#include "Minerva.h"
NeuralNetwork *Minerva::importFromFile(char *fileName) {}
NeuralNetwork *Minerva::importFromMemory(void *p)
{
    /*
    unsigned char layerCount = *p;
    NeuralNetwork *network = new NeuralNetwork(1, layerCount);
    

    p++;
    for(unsigned char i = 0; i < layerCount; i++)
    {
        unsigned char activation;
        activation = *p;
        p++;
        float lr = *p;
        p += sizeof(float);
        uint16_t rows, columns;
        rows = *p;
        p += 2;
        columns = *p;
        p += 2;
        MNC::Matrix* w = new MNC::Matrix(rows,columns, (float*)p, false);
        p += rows * columns * sizeof(float);
        MNC::Matrix* b = new MNC::Matrix(rows,1, (float*)p, false);
        p += rows * sizeof(float);
        Layer *l = new Layer(columns, rows, new SIGMOID(), i, w, b);
        network->layers[i] = l;
    }
    return network;
	*/
    return nullptr;
}

NeuralNetwork *Minerva::importFromMemory_P(void *p)
{
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
    NeuralNetwork *network = new NeuralNetwork(inX, inY, inZ, layerCount);
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
        network->layers[i] = l;
    }
    return network;
}
