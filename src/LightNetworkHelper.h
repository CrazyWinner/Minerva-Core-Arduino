
#include "ActivationFunctions.h"
#include "NeuralNetwork.h"
#include "Matrix.h"
#include <Arduino.h>
class LightNetworkHelper{
    public:
    static NeuralNetwork* importFromFile(char* fileName); 
    static NeuralNetwork* importFromFlash(char* p);

};
