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
	int x;
	ifst >> x;
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
	int x;
	ifst >> x;
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
void flower::InData(ifstream &ifst)
{
	int x;
	ifst >> name >> x;
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
	ifst >> x;
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
	case 3:
		pl = new flower;
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
	
	switch(habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}
	ofst << "Its name has " << consonant() << " consonants.\n";
}
void tree::Out(ofstream &ofst)
{
	ofst << "It is a Tree: its name is " << name << ", its age is estimated to be " << age << " years." << endl;

	switch(habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}
	ofst << "Its name has " << consonant() << " consonants.\n";
}
void tree::OutTree(ofstream &ofst,int& cnt)
{
	ofst << ++cnt << ": ";
	Out(ofst);
}

void plant::OutTree(ofstream &ofst,int& cnt)
{
}
void container::OutTree(ofstream &ofst)
{
	container* cur = this;
	ofst << "Container contains " << len << " elements." << endl;
	int counter = 0;
	while(cur->pl != NULL)
	{
		cur->pl->OutTree(ofst,counter);
		cur = cur->next;
	}
}
	
hab plant::GetHabitat()
{
	return habitat;
}
void container::Sort()
{
	container* start = this;
	for(int i = 0; i < start->len; ++i)
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
void flower::Out(ofstream &ofst)
{
	ofst << "It is a Flower: its name is " << name << ". ";
	switch(type)
	{
	case flower::GARDEN:
		ofst << "It's a garden flower." << endl;
		break;
	case flower::DOMESTIC:
		ofst << "It's a domestic flower." << endl;
		break;
	case flower::WILD:
		ofst << "It's a wild flower." << endl;
		break;
	case flower::BED:
		ofst << "It's from a flower-bed." << endl;
		break;
	}
	switch(habitat)
	{
	case DESERT:
		ofst << "Its natural habitat is desert." << endl;
		break;
	case TUNDRA:
		ofst << "Its natural habitat is tundra." << endl;
		break;
	case FOREST:
		ofst << "Its natural habitat is forest." << endl;
		break;
	case JUNGLE:
		ofst << "Its natural habitat is jungle." << endl;
		break;
	case FIELD:
		ofst << "Its natural habitat is field." << endl;
		break;
	}
	ofst << "Its name has " << consonant() << " consonants.\n";

}