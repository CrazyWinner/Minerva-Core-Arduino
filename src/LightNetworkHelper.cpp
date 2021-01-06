#include "LightNetworkHelper.h"

NeuralNetwork* LightNetworkHelper::importFromFile(char *fileName) {}
NeuralNetwork* LightNetworkHelper::importFromMemory(char *p)
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
        LN::Matrix* w = new LN::Matrix(rows,columns, (float*)p, false);
        p += rows * columns * sizeof(float);
        LN::Matrix* b = new LN::Matrix(rows,1, (float*)p, false);
        p += rows * sizeof(float);
        Layer *l = new Layer(columns, rows, new SIGMOID(), i, w, b);
        network->layers[i] = l;
    }
    return network;
}

NeuralNetwork* LightNetworkHelper::importFromMemory_P(char *p)
{
    unsigned char layerCount = pgm_read_word(p);
    NeuralNetwork *network = new NeuralNetwork(1, layerCount);
    

    p++;
    for(unsigned char i = 0; i < layerCount; i++)
    {
        unsigned char activation;
        activation = pgm_read_word(p);
        p++;
        float lr = 0;
		memcpy_P(&lr, p, sizeof(float));
        p += sizeof(float);
        uint16_t rows, columns;
        rows = 0;
		memcpy_P(&rows, p, sizeof(uint16_t));
        p += 2;
        columns = 0;
		memcpy_P(&columns, p, sizeof(uint16_t));
        p += 2;
        LN::Matrix* w = new LN::Matrix(rows,columns, (float*)p, true);
        p += rows * columns * sizeof(float);
        LN::Matrix* b = new LN::Matrix(rows,1, (float*)p, true);
        p += rows * sizeof(float);
        Layer *l = new Layer(columns, rows, new SIGMOID(), i, w, b);
        network->layers[i] = l;
    }
    return network;
}

