#include <iostream>
#include "LightNetwork.h"
#define LN LightNetwork
LN::NeuralNetwork nn(2);
int main(int argc, char *argv[])
{
    nn.addLayer(768, new LN::SIGMOID());
	nn.addLayer(46, new LN::SIGMOID());
	nn.addLayer(12, new LN::SIGMOID());
	float arr[] = {1,2};
	LN::Matrix in = LN::Matrix::fromArray(2,1,arr);
	LN::Matrix a = nn.guess(in);
	a.printDebug();
	std::cout << "Hello world!" << std::endl;
}