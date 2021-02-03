#pragma once
#include "Activation.h"
#include "NeuralNetwork.h"
#include "FullyConnected.h"
#include "Matrix.h"
#include <Arduino.h>
#include "DEFINE_INT.h"
class Minerva
{
public:
    static void importFromFile(NeuralNetwork& network, const char *fileName);
    static void importFromMemory(NeuralNetwork& network, const void *p);
    static void importFromMemory_P(NeuralNetwork& network, const void *pt);
	
};
