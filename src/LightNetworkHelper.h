#include "ActivationFunctions.h"
#include "NeuralNetwork.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
namespace LightNetwork{
class LightNetworkHelper{

    static NeuralNetwork* importFromFile(char* fileName); 
    static NeuralNetwork* importFromFlash(char* p);

};
}