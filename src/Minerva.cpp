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
			Serial.println("FULLY_CONNECTED");
            Activation::ActivationType activationType;
            uint32_t temp;
			INT_MNC p_count;
            cpy(&activationType, p, sizeof(activationType), loadType);
            p += sizeof(activationType);
            p += sizeof(float);
			
            cpy(&temp, p, sizeof(temp), loadType);
            p += sizeof(temp);
			p_count = temp;			

            l = new FullyConnected(p_count, activationType, i);
            Matrix *w = getMatrix(p_count, inX * inY * inZ, (float *)p, loadType);
            p += inX * inY * inZ * p_count * sizeof(float);
            Matrix *b = getMatrix(p_count, 1, (float *)p, loadType);
            p += p_count * sizeof(float);
		
            l->init(inX, inY, inZ, w, b);
        } 
		break;
		case Layer::CONVOLUTIONAL:
        {
			Serial.println("CONVOLUTIONAL");
			 Activation::ActivationType activationType;
			 uint32_t temp;
             INT_MNC filter_size_X, filter_size_Y, filter_count, padding_X, padding_Y;
			 cpy(&activationType, p, sizeof(activationType), loadType);
			 p += sizeof(activationType);
             p += sizeof(float);
			 
			 cpy(&temp, p, sizeof(temp), loadType);
             p += sizeof(temp);
			 filter_size_X = temp;
			 
			 cpy(&temp, p, sizeof(temp), loadType);
             p += sizeof(temp);
			 filter_size_Y = temp;
			 
			 cpy(&temp, p, sizeof(temp), loadType);
             p += sizeof(temp);
			 filter_count = temp;
			 
			 cpy(&temp, p, sizeof(temp), loadType);
             p += sizeof(temp);
			 padding_X = temp;
			 
			 cpy(&temp, p, sizeof(temp), loadType);
             p += sizeof(temp);
			 padding_Y = temp;
			 
             l = new Conv2D(filter_size_X, filter_size_Y, filter_count, padding_X, padding_Y, activationType, i);
             Matrix *w = getMatrix(filter_size_X * filter_size_Y, filter_count, (float *)p, loadType);
             p += filter_size_X * filter_size_Y * filter_count * sizeof(float);
             Matrix *b = getMatrix(filter_count, 1, (float *)p, loadType);
             p += filter_count * sizeof(float);
             l->init(inX, inY, inZ, w, b);
        }
        break;
		case Layer::MAX_POOLING:
        {
			Serial.println("MAX_POOLING");
			uint32_t temp;
            INT_MNC poolingSize_X, poolingSize_Y;
			
			cpy(&temp, p, sizeof(temp), loadType);
            p += sizeof(temp);
			poolingSize_X = temp;
			
			
            cpy(&temp, p, sizeof(temp), loadType);
            p += sizeof(temp);
			poolingSize_Y = temp;
            l = new MaxPooling(poolingSize_X, poolingSize_Y, i);
			l->init(inX, inY, inZ, nullptr, nullptr);
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


