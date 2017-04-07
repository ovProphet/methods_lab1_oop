#include <iostream>
#include <fstream>
#include "declarations.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Error!\nWaited: command input_file output_file\n";
		exit(1);
	}
	
	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	outputFile << "Start" << endl;
	container* c = new container;
	c->In(inputFile);
	outputFile << "Filled container:" << endl;
	c->Out(outputFile);

	outputFile << "Elements of the first type only:" << endl;
	c->OutTree(outputFile);
	
	c->Sort();
	outputFile << "Sorted container:" << endl;
	c->Out(outputFile);

	c->Clear();
	outputFile << "Empty container:" << endl;
	c->Out(outputFile);

	outputFile<< "Stop" << endl;
	return 0;
}