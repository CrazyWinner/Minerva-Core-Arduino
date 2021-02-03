#include "Minerva.h"
void Minerva::importFromFile(NeuralNetwork& network, const char *fileName) {}
void Minerva::importFromMemory(NeuralNetwork& network, const void *p)
{
  import(network, (void*)p, MEMORY);
}

void Minerva::importFromMemory_P(NeuralNetwork& network, const void *p)
{
  import(network, (void*)p, MEMORY_P);
}

void Minerva::import(NeuralNetwork& network, void *p, LoadType loadType){
    uint16_t layerCount;
    cpy(&layerCount, p, sizeof(layerCount), loadType);
    p += sizeof(layerCount);
    uint32_t inX1, inY1, inZ1;
    cpy(&inX1, p, sizeof(inX1), loadType);
    p += sizeof(inX1);
    cpy(&inY1, p, sizeof(inY1), loadType);
    p += sizeof(inY1);
    cpy(&inZ1, p, sizeof(inZ1), loadType);
    p += sizeof(inZ1);
    INT_MNC inX = inX1;
    INT_MNC inY = inY1;
    INT_MNC inZ = inZ1;
	network.init(inX, inY, inZ, layerCount);
    Activation::ActivationType type;
    for (uint16_t i = 0; i < layerCount; i++)
    {
        cpy(&type, p, sizeof(type), loadType);
        p += sizeof(type);
        Layer *l;
        switch (type)
        {
        case Layer::FULLY_CONNECTED:
        {
            Activation::ActivationType activationType;
            uint32_t p_count;
            cpy(&activationType, p, sizeof(activationType), loadType);
            p += sizeof(activationType);
            p += sizeof(float);
            cpy(&p_count, p, sizeof(p_count), loadType);
            p += sizeof(p_count);
            l = new FullyConnected(p_count, activationType, i);
            Matrix *w = getMatrix(p_count, inX * inY * inZ, (float *)p, loadType);
            p += inX * inY * inZ * p_count * sizeof(float);
            Matrix *b = getMatrix(p_count, 1, (float *)p, loadType);
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

Matrix* Minerva::getMatrix(const INT_MNC& r, const INT_MNC& c, float *arr, LoadType type){
		switch(type){
		case MEMORY:
		  return new Matrix(r, c, arr);
		case MEMORY_P:
		  return new Matrix_P(r, c, arr);
		default:
		  break;
	}
}

void Minerva::cpy(const void* sourcePtr, const void* destPtr, size_t size, LoadType type){
	switch(type){
		case MEMORY:
		  memcpy(sourcePtr, destPtr, size);
		  break;
		case MEMORY_P:
		  memcpy_P(sourcePtr, destPtr, size);
		  break;
		default:
		  break;
	}
	
}


