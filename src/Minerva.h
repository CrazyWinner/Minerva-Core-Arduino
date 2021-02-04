#pragma once
#include "Activation.h"
#include "NeuralNetwork.h"
#include "FullyConnected.h"
#include "Conv2D.h"
#include "MaxPooling.h"
#include "Matrix.h"
#include "Matrix_P.h"
#include <Arduino.h>
#include "DEFINE_INT.h"
class Minerva
{
private:
    enum LoadType : uint8_t
    {
        MEMORY = 0,
        MEMORY_P,
        SDCARD
    };
    static void import(NeuralNetwork& network, void *p, LoadType loadType);	
	static void cpy(const void* sourcePtr, const void* destPtr, size_t size, LoadType loadType);
	static Matrix* getMatrix(const INT_MNC& r, const INT_MNC& c, float *arr, LoadType loadType);
public:
    static void importFromFile(NeuralNetwork& network, const char *fileName);
    static void importFromMemory(NeuralNetwork& network, const void *p);
    static void importFromMemory_P(NeuralNetwork& network, const void *pt);
	
};
