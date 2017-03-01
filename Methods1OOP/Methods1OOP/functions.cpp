#include <iostream>
#include <fstream>
#include "declarations.h"
using namespace std;

class tree;
container::container()
{
	next = NULL;
	pl = NULL;
	len = 0;
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
	len = 0;
}
void container::In(ifstream &ifst)
{
	container *cur = this;
	int cnt = 0;
	while(!ifst.eof())
	{
		plant *p;
		if((p = plant::In(ifst))!=0)
		{
			cur->pl = p;
			cur->next = new container;
			cur->next->next = NULL;
			cur->next->pl = NULL;
			cur->next->len = 0;
			cur = cur->next;
			++cnt;
		}
	}
	len = cnt;
}
void container::Out(ofstream &ofst)
{
	container* cur = this;
	ofst << "Container contains " << len << " elements." << endl;
	int counter = 0;
	while(cur->pl != NULL)
	{
		ofst << ++counter << ": ";
		cur->pl->Out(ofst);
		cur = cur->next;
	}
}
void tree::InData(ifstream &ifst)
{
	ifst >> name >> age;
}
void bush::InData(ifstream &ifst)
{
	int mon;
	ifst >> name >> mon;
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
}
plant* plant::In(ifstream &ifst)
{
	plant *pl;
	int k;
	ifst >> k;
	switch(k)
	{
	case 1:
		pl = new tree;
		break;
	case 2:
		pl = new bush;
		break;
	default:
		return 0;
	}
	pl->InData(ifst);
	return pl;
}
int plant::consonant()
{
	int res = 0;
	string alphabet = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
	for(int i = 0; i < alphabet.length(); ++i)
	{
		int c = count(name.begin(),name.end(), alphabet[i]);
		if (c > 0)
			res += c;
	}
	return res;
}
void bush::Out(ofstream &ofst)
{
	ofst << "It is a Bush: its name is " << name << ", its blooming month is ";
	switch(blooming)
	{
	case bush::JAN:
		ofst << "January." << endl;
		break;
	case bush::FEB:
		ofst << "February." << endl;
		break;
	case bush::MAR:
		ofst << "March." << endl;
		break;
	case bush::APR:
		ofst << "April." << endl;
		break;
	case bush::MAY:
		ofst << "May." << endl;
		break;
	case bush::JUN:
		ofst << "June." << endl;
		break;
	case bush::JUL:
		ofst << "July." << endl;
		break;
	case bush::AUG:
		ofst << "August." << endl;
		break;
	case bush::SEP:
		ofst << "September." << endl;
		break;
	case bush::OCT:
		ofst << "October." << endl;
		break;
	case bush::NOV:
		ofst << "November." << endl;
		break;
	case bush::DEC:
		ofst << "December." << endl;
		break;
	}
	ofst << "Its name has " << consonant() << " consonants.\n";
}
void tree::Out(ofstream &ofst)
{
	ofst << "It is a Tree: its name is " << name << ", its age is estimated to be " << age << " years." << endl;
	ofst << "Its name has " << consonant() << " consonants.\n";
}