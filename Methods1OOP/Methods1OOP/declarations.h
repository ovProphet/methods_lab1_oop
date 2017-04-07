#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
enum hab{FOREST, FIELD, DESERT, TUNDRA, JUNGLE};
enum key{TREE, BUSH, FLOWER};
class plant
{
protected:
	string name;
	hab habitat;
public:
	static plant* In(ifstream &inputFile);
	virtual void InData(ifstream &inputFile) = 0;
	virtual void Out(ofstream &outputFile) = 0;
	virtual void OutTree(ofstream &outputFile, int& cnt);
	hab GetHabitat();
	int Consonant();
	string GetName();
};
class tree : public plant
{
private:
	long long age;
public:
	long long GetAge();
	void InData(ifstream &inputFile);
	void Out(ofstream &outputFile);
	void OutTree(ofstream &outputFile, int& cnt);
	tree() {}
};
class bush : public plant
{
private:
	enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	month blooming;
public:
	month GetBlooming();
	void InData(ifstream &inputFile);
	void Out(ofstream &outputFile);
	bush() {}
};
class flower : public plant
{
private:
	enum habita{DOMESTIC, WILD, GARDEN, BED};
	habita type;
public:
	habita GetType();
	void InData(ifstream &inputFile);
	void Out(ofstream &outputFile);
	flower() {}
};
class container
{
private:
	container *next;
	plant *pl;
	int length;
public:
	container* GetNext();
	plant* GetPlant();
	int GetLen();
	void In(ifstream &inputFile);
	void Out(ofstream &outputFile);
	void OutTree(ofstream &outputFile);
	void Clear();
	void Sort();
	container();
};