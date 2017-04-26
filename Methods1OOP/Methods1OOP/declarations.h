#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
enum hab{FOREST,FIELD,DESERT,TUNDRA,JUNGLE};
enum key{TREE,BUSH,FLOWER};
/*(1)*/
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
	/*month m;
	//It's better to replace that enum in string (1)*/
	month blooming;
public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	bush() {}
};
class flower : public plant
{
private:
	enum habita{DOMESTIC, WILD, GARDEN, BED};
	/*habita h;
	//It's better to replace that enum in string after (1)*/
	habita type;
public:
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	flower() {}
};
/*class node
{
public: 
	plant *pl;
	node *next;
}
class container
{
private:
	node *cont;
	int len;
...*/
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
	void Sort();
	container();
};