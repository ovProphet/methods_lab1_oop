#include <iostream>
#include <fstream>
#include "declarations.h"
#include "gtest/gtest.h"
using namespace std;

/*
class plant
public:
	+static plant* In(ifstream &ifst);
	+virtual void InData(ifstream &ifst) = 0;
	+virtual void Out(ofstream &ofst) = 0;
	+virtual void OutTree(ofstream &ofst,int& cnt);
	+int consonant();

class tree : public plant
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);
	void OutTree(ofstream &ofst,int& cnt);

class bush : public plant
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);

class flower : public plant
	void InData(ifstream &ifst);
	void Out(ofstream &ofst);

class container
	+void In(ifstream &ifst);
	+void Out(ofstream &ofst);
	+void OutTree(ofstream &ofst);
	+void Clear();
	+void Sort();
*/

TEST(clear_container,empty_container)
{
	container* c = new container;
	c->Clear();
	EXPECT_EQ(c->GetLen(),0);
	EXPECT_TRUE(c->GetPlant() == NULL);
	EXPECT_TRUE(c->GetNext() == NULL);
}
TEST(clear_container,nonempty_container)
{
	container* c = NULL;
	c = new container;
	c->In(ifstream("input.txt"));
	c->Clear();
	EXPECT_EQ(c->GetLen(),0);
	EXPECT_TRUE(c->GetPlant() == NULL);
	EXPECT_TRUE(c->GetNext() == NULL);
}

TEST(sort_container, reverse_container)
{
	ifstream ifst("sort_reverse.txt");
	container* c = new container,* first;
	c->In(ifst);
	first = c;
	c->Sort();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte" || c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte" || c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "OOOOO)))" || c->GetPlant()->GetName() == "Nyeea");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "OOOOO)))" || c->GetPlant()->GetName() == "Nyeea");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoonyee" || c->GetPlant()->GetName() == "Vasily");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoonyee" || c->GetPlant()->GetName() == "Vasily");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Sookomoo" || c->GetPlant()->GetName() == "Flower3");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Sookomoo" || c->GetPlant()->GetName() == "Flower3");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Za-Bor" || c->GetPlant()->GetName() == "BushNumba4");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Za-Bor" || c->GetPlant()->GetName() == "BushNumba4");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant() == NULL);
	first->Clear();
}
TEST(sort_container, sorted_container)
{
	ifstream ifst("sorted.txt");
	container* c = new container,* first;
	c->In(ifst);
	first = c;
	c->Sort();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte" || c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte" || c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "OOOOO)))" || c->GetPlant()->GetName() == "Nyeea");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "OOOOO)))" || c->GetPlant()->GetName() == "Nyeea");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoonyee" || c->GetPlant()->GetName() == "Vasily");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoonyee" || c->GetPlant()->GetName() == "Vasily");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Sookomoo" || c->GetPlant()->GetName() == "Flower3");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Sookomoo" || c->GetPlant()->GetName() == "Flower3");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Za-Bor" || c->GetPlant()->GetName() == "BushNumba4");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Za-Bor" || c->GetPlant()->GetName() == "BushNumba4");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant() == NULL);
	first->Clear();
}
TEST(sort_container, one_element_container)
{
	ifstream ifst("one_sort.txt");
	container* c = new container,*first;
	first=c;
	c->In(ifst);
	c->Sort();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte" || c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant() == NULL);
	first->Clear();
}
TEST(sort_container, empty_container)
{
	container* c = new container,*first;
	first=c;
	c->Sort();
	EXPECT_TRUE(c->GetPlant() == NULL);
	first->Clear();
}
TEST(consonant,no_consonants)
{
	ofstream ofst("trash.txt");
	plant* p = plant::In(ifstream("no_consonants.txt"));
	EXPECT_EQ(p->consonant(),0);
}
TEST(consonant,all_consonants)
{
	ofstream ofst("trash.txt");
	plant* p = plant::In(ifstream("all_consonants.txt"));
	EXPECT_EQ(p->consonant(),40);
}
TEST(consonant,empty_string)
{
	ofstream ofst("trash.txt");
	plant* p = plant::In(ifstream("empty_string.txt"));
	EXPECT_EQ(p->consonant(),0);
}
TEST(consonant,orchid)
{
	ofstream ofst("trash.txt");
	plant* p = plant::In(ifstream("orchid.txt"));
	EXPECT_EQ(p->consonant(),5);
}

TEST(plant_in,all_at_once)
{
	ifstream ifst("all_types.txt");
	plant* p = plant::In(ifst);
	EXPECT_TRUE(p->GetHabitat() == FOREST);
	EXPECT_TRUE(p->GetName() == "Toomoo");
	p = plant::In(ifst);
	EXPECT_TRUE(p->GetHabitat() == FOREST);
	EXPECT_TRUE(p->GetName() == "tewte");
	p = plant::In(ifst);
	EXPECT_TRUE(p->GetHabitat() == JUNGLE);
	EXPECT_TRUE(p->GetName() == "Za-Bor");
}

TEST(output_container,empty)
{
	ofstream ofst("trash.txt");
	container* c = new container;
	c->Out(ofst);
	c->Clear();
}
TEST(output_container,nonempty)
{
	ofstream ofst("trash.txt");
	container* c = new container,*first;
	c->In(ifstream("sorted.txt"));
	c->Out(ofst);
	c->Clear();
}

TEST(input_container,all_at_once)
{
	container* c = new container, *first;
	first = c;
	c->In(ifstream("sorted.txt"));
	EXPECT_EQ(c->GetLen(),10);
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "tewte");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Nyeea");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "OOOOO)))");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Toomoonyee");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Vasily");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Flower3");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Sookomoo");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "BushNumba4");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant()->GetName() == "Za-Bor");
	c = c->GetNext();
	EXPECT_TRUE(c->GetPlant() == NULL);
	first->Clear();
}
TEST(input_container,empty)
{
	container* c = new container;
	c->In(ifstream("empty.txt"));
	EXPECT_EQ(c->GetLen(),0);
	EXPECT_TRUE(c->GetPlant()==NULL);
	EXPECT_TRUE(c->GetNext()==NULL);
}

TEST(input_tree,all_at_once)
{
	ifstream ifst("trees.txt");
	tree* tr = new tree;
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetAge() == 2000000000000000);
	EXPECT_TRUE(tr->GetName() == "Gnav-ov-Stryka");
	EXPECT_TRUE(tr->GetHabitat() == FOREST);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetAge()== 55555);
	EXPECT_TRUE(tr->GetName() == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->GetHabitat() == FIELD);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetAge() == 55555);
	EXPECT_TRUE(tr->GetName() == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->GetHabitat() == DESERT);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetAge() == 55555);
	EXPECT_TRUE(tr->GetName() == "Kyr-Lun-Borgor");
	EXPECT_TRUE(tr->GetHabitat() == TUNDRA);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetAge() == 1337);
	EXPECT_TRUE(tr->GetName() == "Za-Bor");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
}
TEST(input_bush,all_at_once)
{
	ifstream ifst("bushes.txt");
	bush* tr = new bush;
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 4);
	EXPECT_TRUE(tr->GetName() == "Poomoo");
	EXPECT_TRUE(tr->GetHabitat() == FOREST);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 0);
	EXPECT_TRUE(tr->GetName() == "Nyeea");
	EXPECT_TRUE(tr->GetHabitat() == FIELD);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 1);
	EXPECT_TRUE(tr->GetName() == "Hoozooa");
	EXPECT_TRUE(tr->GetHabitat() == DESERT);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 2);
	EXPECT_TRUE(tr->GetName() == "Shoom");
	EXPECT_TRUE(tr->GetHabitat() == TUNDRA);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 3);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 5);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 6);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat()== JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 7);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 8);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 9);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 10);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
	tr->InData(ifst);
	EXPECT_TRUE((int)tr->GetBlooming() == 11);
	EXPECT_TRUE(tr->GetName() == "BushNumba4");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
}
TEST(input_flower,all_at_once)
{
	ifstream ifst("flowers.txt");
	flower* tr = new flower;
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetType() == 1);
	EXPECT_TRUE(tr->GetName() == "tewte");
	EXPECT_TRUE(tr->GetHabitat() == FOREST);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetType() == 0);
	EXPECT_TRUE(tr->GetName() == "Flower1");
	EXPECT_TRUE(tr->GetHabitat() == FIELD);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetType() == 2);
	EXPECT_TRUE(tr->GetName() == "Flower2");
	EXPECT_TRUE(tr->GetHabitat() == DESERT);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetType() == 3);
	EXPECT_TRUE(tr->GetName() == "Flower3");
	EXPECT_TRUE(tr->GetHabitat() == TUNDRA);
	tr->InData(ifst);
	EXPECT_TRUE(tr->GetType() == 3);
	EXPECT_TRUE(tr->GetName() == "Flower3");
	EXPECT_TRUE(tr->GetHabitat() == JUNGLE);
}
TEST(output_bush,all_at_once)
{
	ifstream ifst("bushes.txt");
	bush* b = new bush;
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
}
TEST(output_tree,all_at_once)
{
	tree* b = new tree;
	ifstream ifst("trees.txt");
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
}
TEST(output_flower,all_at_once)
{
	flower* b = new flower;
	ifstream ifst("flowers.txt");
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
	b->InData(ifst);
	b->Out(ofstream("trash.txt"));
}
TEST(output_plant,all_at_once)
{
	plant* pl;
	ifstream ifst("sort_reverse.txt");
	pl = plant::In(ifst);
	pl->Out(ofstream("trash.txt"));
	pl = plant::In(ifst);
	pl->Out(ofstream("trash.txt"));
	pl = plant::In(ifst);
	pl->Out(ofstream("trash.txt"));
}

TEST(output_trees_only,no_trees)
{
	container* c = new container;
	c->In(ifstream("no_trees.txt"));
	c->OutTree(ofstream("trash.txt"));
}
TEST(output_trees_only,all_trees)
{
	container* c = new container;
	c->In(ifstream("all_trees.txt"));
	c->OutTree(ofstream("trash.txt"));
}
TEST(output_trees_only,empty_container)
{
	container* c = new container;
	c->In(ifstream("empty.txt"));
	c->OutTree(ofstream("trash.txt"));
}
TEST(output_trees_only,mixed)
{
	container* c = new container;
	c->In(ifstream("input.txt"));
	c->OutTree(ofstream("trash.txt"));
}
TEST(trees_only,all)
{
	ifstream ifst("trees.txt");
	int cnt = 0;
	tree* tr = new tree;
	tr->InData(ifst);
	tr->OutTree(ofstream("trash.txt"),cnt);
	tr->InData(ifst);
	tr->OutTree(ofstream("trash.txt"),cnt);
	tr->InData(ifst);
	tr->OutTree(ofstream("trash.txt"),cnt);
	tr->InData(ifst);
	tr->OutTree(ofstream("trash.txt"),cnt);
	tr->InData(ifst);
	tr->OutTree(ofstream("trash.txt"),cnt);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar();
	return 0;
}