#include "LightNetworkHelper.h"

NeuralNetwork* LightNetworkHelper::importFromFile(char *fileName) {}
NeuralNetwork* LightNetworkHelper::importFromFlash(char *p)
{
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
        LN::Matrix* w = new LN::Matrix(rows,columns, (float*)p);
        p += rows * columns * sizeof(float);
        LN::Matrix* b = new LN::Matrix(rows,1, (float*)p);
        p += rows * sizeof(float);
        Layer *l = new Layer(columns, rows, new SIGMOID(), i, w, b);
       // l->weights->printDebug();
       //  l->bias->printDebug();
        network->layers[i] = l;
      //  network->layers.push_back(l);
    }
    return network;
}
