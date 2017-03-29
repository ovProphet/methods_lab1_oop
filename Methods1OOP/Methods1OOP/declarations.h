#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
enum hab{FOREST,FIELD,DESERT,TUNDRA,JUNGLE};
enum key{TREE,BUSH,FLOWER};
class plant
{
protected:
	string name;
	hab habitat;
public:
	static plant* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0;
	virtual void Out(ofstream &ofst) = 0;
	virtual void OutTree(ofstream &ofst,int& cnt);
	hab GetHabitat();
	int consonant();
	string GetName();
};
class tree : public plant
{
private:
	long long age;
public:
	long long GetAge();
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	void OutTree(ofstream &ofst,int& cnt);
	tree() {}
};
class bush : public plant
{
private:
	enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	month blooming;
public:
	month GetBlooming();
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	bush() {}
};
class flower : public plant
{
private:
	enum habita{DOMESTIC, WILD, GARDEN, BED};
	habita type;
public:
	habita GetType();
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	flower() {}
};
class container
{
private:
	container *next;
	plant *pl;
	int len;
public:
	container* GetNext();
	plant* GetPlant();
	int GetLen();
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void OutTree(ofstream &ofst);
	void Clear();
	void Sort();
	container();
};