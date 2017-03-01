#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum key{TREE,BUSH,FLOWER};
class plant
{
protected:
	string name;
public:
	static plant* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0;
	virtual void Out(ofstream &ofst) = 0;
};
class tree : public plant
{
private:
	long long age;
public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	tree() {}
};
class bush : public plant
{
private:
	enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};
	month blooming;
public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	bush() {}
};
class flower : public plant
{
private:
	enum habitat{DOMESTIC, WILD, GARDEN, BED};
	habitat type;
public:
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
	void In(ifstream &ifst);
	void Out(ofstream &ofst);
	void Clear();
	container();
};