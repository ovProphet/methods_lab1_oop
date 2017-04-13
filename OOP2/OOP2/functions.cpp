#include <iostream>
#include <fstream>
#include "declarations.h"
using namespace std;

class tree;
void CheckValueArea(int value, int a, int b)
{
	if (!(a <= value && value <= b))
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
}
void InputFileCheck(ifstream& inputFile)
{
	if(!inputFile)
	{
		cout << "Cannot open input file." << endl;
		exit(1);
	}
}
void InputValuesCheck(ifstream& inputFile)
{
	if(inputFile.fail())
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
}
void OutputFileCheck(ofstream& outputFile)
{
	if(!outputFile)
	{
		cout << "Cannot open output file." << endl;
		exit(1);
	}
}
container::container()
{
	next = NULL;
	pl = NULL;
	length = 0;
}
container* container::GetNext()
{
	return next;
}
plant* container::GetPlant()
{
	return pl;
}
int container::GetLen()
{
	return length;
}
void container::Clear()
{
	container *prev = this, *cur = this;
	cur = cur->next;
	while(cur != NULL && cur->pl != NULL)
	{
		prev = cur;
		cur = cur->next;
		delete prev->pl;
		delete prev;
	}
	if(cur != this)
		delete cur;
	delete pl;
	next = NULL;
	pl = NULL;
	length = 0;
}
void container::In(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	container *cur = this;
	int cnt = 0;
	while(!inputFile.eof())
	{
		plant *p;
		if((p = plant::In(inputFile))!=0)
		{
			cur->pl = p;
			cur->next = new container;
			cur->next->next = NULL;
			cur->next->pl = NULL;
			cur->next->length = 0;
			cur = cur->next;
			++cnt;
		}
	}
	length = cnt;
}
void container::Out(ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	container* cur = this;
	outputFile << "Container contains " << length << " elements." << endl;
	int counter = 0;
	while(cur->pl != NULL)
	{
		outputFile << ++counter << ": ";
		cur->pl->Out(outputFile);
		cur = cur->next;
	}
}
void tree::InData(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	inputFile >> name >> age;
	InputValuesCheck(inputFile);
	if(age < 0)
	{
		cout << "Incorrect input values." << endl;
		exit(1);
	}
	int x;
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x,0,4);
	switch(x)
	{
	case 0:
		habitat = FOREST;
		break;
	case 1:
		habitat = FIELD;
		break;
	case 2:
		habitat = DESERT;
		break;
	case 3:
		habitat = TUNDRA;
		break;
	case 4:
		habitat = JUNGLE;
		break;
	}
}
void bush::InData(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	int mon;
	inputFile >> name >> mon;
	InputValuesCheck(inputFile);
	CheckValueArea(mon,0,11);
	switch(mon)
	{
	case 0:
		blooming = bush::JAN;
		break;
	case 1:
		blooming = bush::FEB;
		break;
	case 2:
		blooming = bush::MAR;
		break;
	case 3:
		blooming = bush::APR;
		break;
	case 4:
		blooming = bush::MAY;
		break;
	case 5:
		blooming = bush::JUN;
		break;
	case 6:
		blooming = bush::JUL;
		break;
	case 7:
		blooming = bush::AUG;
		break;
	case 8:
		blooming = bush::SEP;
		break;
	case 9:
		blooming = bush::OCT;
		break;
	case 10:
		blooming = bush::NOV;
		break;
	case 11:
		blooming = bush::DEC;
		break;
	}
	int x;
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 4);
	switch(x)
	{
	case 0:
		habitat = FOREST;
		break;
	case 1:
		habitat = FIELD;
		break;
	case 2:
		habitat = DESERT;
		break;
	case 3:
		habitat = TUNDRA;
		break;
	case 4:
		habitat = JUNGLE;
		break;
	}
}
void flower::InData(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	int x;
	inputFile >> name >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 3);
	switch(x)
	{
	case 0:
		type = flower::DOMESTIC;
		break;
	case 1:
		type = flower::GARDEN;
		break;
	case 2:
		type = flower::WILD;
		break;
	case 3:
		type = flower::BED;
		break;
	}
	inputFile >> x;
	InputValuesCheck(inputFile);
	CheckValueArea(x, 0, 4);
	switch(x)
	{
	case 0:
		habitat = FOREST;
		break;
	case 1:
		habitat = FIELD;
		break;
	case 2:
		habitat = DESERT;
		break;
	case 3:
		habitat = TUNDRA;
		break;
	case 4:
		habitat = JUNGLE;
		break;
	}
}
plant* plant::In(ifstream &inputFile)
{
	InputFileCheck(inputFile);
	plant *pl;
	int k;
	inputFile >> k;
	if(inputFile.eof())
	{
		return NULL;
	}
	InputValuesCheck(inputFile);
	CheckValueArea(k, 1, 3);
	switch(k)
	{
	case 1:
		pl = new tree;
		break;
	case 2:
		pl = new bush;
		break;
	case 3:
		pl = new flower;
		break;
	default:
		return 0;
	}
	pl->InData(inputFile);
	return pl;
}
int plant::Consonant()
{
	int res = 0;
	string alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for(int i = 0; i < alphabet.length(); ++i)
	{
		int c = count(name.begin(), name.end(), alphabet[i]);
		if (c > 0)
			res += c;
		if (res < 0)
		{
			cout << "Integer overflow." << endl;
			exit(1);
		}
	}
	return res;
}
bush::month bush::GetBlooming()
{
	return blooming;
}
flower::habita flower::GetType()
{
	return type;
}
void bush::Out(ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Bush: its name is " << name << ", its blooming month is ";
	switch(blooming)
	{
	case bush::JAN:
		outputFile << "January." << endl;
		break;
	case bush::FEB:
		outputFile << "February." << endl;
		break;
	case bush::MAR:
		outputFile << "March." << endl;
		break;
	case bush::APR:
		outputFile << "April." << endl;
		break;
	case bush::MAY:
		outputFile << "May." << endl;
		break;
	case bush::JUN:
		outputFile << "June." << endl;
		break;
	case bush::JUL:
		outputFile << "July." << endl;
		break;
	case bush::AUG:
		outputFile << "August." << endl;
		break;
	case bush::SEP:
		outputFile << "September." << endl;
		break;
	case bush::OCT:
		outputFile << "October." << endl;
		break;
	case bush::NOV:
		outputFile << "November." << endl;
		break;
	case bush::DEC:
		outputFile << "December." << endl;
		break;
	}
	switch(habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}
	outputFile << "Its name has " << Consonant() << " consonants.\n";
}
void tree::Out(ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Tree: its name is " << name << ", its age is estimated to be " << age << " years." << endl;

	switch(habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}
	outputFile << "Its name has " << Consonant() << " consonants.\n";
}
void tree::OutTree(ofstream &outputFile, int& cnt)
{
	OutputFileCheck(outputFile);
	outputFile << ++cnt << ": ";
	Out(outputFile);
}
long long tree::GetAge()
{
	return age;
}
void plant::OutTree(ofstream &outputFile, int& cnt)
{
	OutputFileCheck(outputFile);
}
void container::OutTree(ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	container* cur = this;
	outputFile << "Container contains " << length << " elements." << endl;
	int counter = 0;
	while(cur->pl != NULL)
	{
		cur->pl->OutTree(outputFile, counter);
		cur = cur->next;
	}
}
hab plant::GetHabitat()
{
	return habitat;
}
string plant::GetName()
{
	return name;
}
void container::Sort()
{
	container* start = this;
	for(int i = 0; i < start->length; ++i)
	{
		bool changed = false;
		container* cur = start;
		while(cur->next->pl != NULL)
		{
			int i1 = cur->pl->GetHabitat();
			int i2 = cur->next->pl->GetHabitat();
			if(i1 > i2 )
			{
				plant* buf;
				buf = cur->pl;
				cur->pl = cur->next->pl;
				cur->next->pl = buf;
				changed = true;
			}
			cur=cur->next;
		}
		if(!changed)
			break;
	}
}
void flower::Out(ofstream &outputFile)
{
	OutputFileCheck(outputFile);
	outputFile << "It is a Flower: its name is " << name << ". ";
	switch(type)
	{
	case flower::GARDEN:
		outputFile << "It's a garden flower." << endl;
		break;
	case flower::DOMESTIC:
		outputFile << "It's a domestic flower." << endl;
		break;
	case flower::WILD:
		outputFile << "It's a wild flower." << endl;
		break;
	case flower::BED:
		outputFile << "It's from a flower-bed." << endl;
		break;
	}

	switch(habitat)
	{
	case DESERT:
		outputFile << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		outputFile << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		outputFile << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		outputFile << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		outputFile << "Its natural habitat is field." << endl;
		break;
	}
	outputFile << "Its name has " << Consonant() << " consonants.\n";
}

void container::MultiMethod(ofstream &ofst)
{
	ofst << "Multimethod." << endl;
	int l = GetLen();
	for(int i = 0; i < l - 1; i++) 
	{
		container* cur = this;
		int left = i;
		plant* pl1 = cur->pl;
		while(left)
		{
			cur = cur->next;
			pl1 = cur->pl;
			--left;
		}
		for(int j = i + 1; j < l; j++) 
		{
			cur = this;
			left = j;
			plant* pl2 = cur->pl;
			while(left)
			{
				cur = cur->next;
				pl2 = cur->pl;
				--left;
			}
			pl1->MultiMethod(pl2, ofst);
			pl1->Out(ofst);
			pl2->Out(ofst);
		}
	}
}
void tree::MultiMethod(plant* &other, ofstream &ofst)
{
	other->MMTree(ofst);
}
void bush::MultiMethod(plant* &other, ofstream &ofst)
{
	other->MMBush(ofst);
}
void flower::MultiMethod(plant* &other, ofstream &ofst)
{
	other->MMFlower(ofst);
}
void tree::MMTree(ofstream &ofst)
{
	ofst << "-A tree and a tree:" << endl;
}
void tree::MMBush(ofstream &ofst)
{
	ofst << "-A bush and a tree:" << endl;
}
void tree::MMFlower(ofstream &ofst)
{
	ofst << "-A flower and a tree:" << endl;
}
void bush::MMTree(ofstream &ofst)
{
	ofst << "-A tree and a bush:" << endl;
}
void bush::MMBush(ofstream &ofst)
{
	ofst << "-A bush and a bush:" << endl;
}
void bush::MMFlower(ofstream &ofst)
{
	ofst << "-A flower and a bush:" << endl;
}
void flower::MMTree(ofstream &ofst)
{
	ofst << "-A tree and a flower:" << endl;
}
void flower::MMBush(ofstream &ofst)
{
	ofst << "-A bush and a flower:" << endl;
}
void flower::MMFlower(ofstream &ofst)
{
	ofst << "-A flower and a flower:" << endl;
}