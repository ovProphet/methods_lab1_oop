#include <iostream>
#include <fstream>
#include <string>

using namespace std;
enum key{TREE,BUSH};
class plant
{
protected:
	string name;
public:
	static plant* In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0;
	virtual void Out(ofstream &ofst) = 0;
	virtual void OutTree(ofstream &ofst,int& cnt);
};
class tree : public plant
{
private:
	long long age;
public:
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
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	bush() {}
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
	void OutTree(ofstream &ofst);
	void Clear();
	container();
};