#include "LightNetwork.h"

using namespace LightNetwork;
void LightNetworkHelper::exportToFile(NeuralNetwork network, char* fileName){
  std::ofstream myfile;
  unsigned char x = 255;
  myfile.open ("example.txt");
  myfile << x;
  myfile.close();
}

