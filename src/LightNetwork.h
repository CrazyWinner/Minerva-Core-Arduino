#include "ActivationFunctions.h"
#include "NeuralNetwork.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
namespace LightNetwork{
class LightNetworkHelper{
    static void exportToFile(NeuralNetwork network, char* fileName);
    static NeuralNetwork* importFromFile(char* fileName); 


};
}