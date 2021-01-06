#include "ActivationFunctions.h"
#include "NeuralNetwork.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>

class LightNetworkHelper{
    public:
    static NeuralNetwork* importFromFile(char* fileName); 
    static NeuralNetwork* importFromFlash(char* p);

};
