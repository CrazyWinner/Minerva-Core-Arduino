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
    static NeuralNetwork *importFromFile(char *fileName);
    static NeuralNetwork *importFromMemory(void *p);
    static NeuralNetwork *importFromMemory_P(void *pt);
};
