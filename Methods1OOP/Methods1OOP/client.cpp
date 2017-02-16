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

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	ofst << "Start" << endl;
	container* c = new container;
	c->In(ifst);
	ofst << "Filled container:" << endl;
	c->Out(ofst);

	c->Clear();
	ofst << "Empty container:" << endl;
	c->Out(ofst);

	ofst<< "Stop" << endl;
	return 0;
}