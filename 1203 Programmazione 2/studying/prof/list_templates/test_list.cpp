
#include <iostream>
#include <string>
#include "list.h"


void test_list_of_strings()
{
	List<std::string> mylist;

	mylist.insert("Corrado");	
	mylist.insert("Giuseppe");	
	mylist.insert("Maria");	
	
	mylist.show();
	
	if (mylist.exist("Giuseppe"))
		cout << "'Giuseppe' trovato" << endl;

	cout << endl;
	
	//mylist.delete_first();
	//mylist.delete_first();
	
	mylist.delete_element("Maria");
	
	mylist.show();

	//if (mylist.exist("Giuseppe"))
	//	cout << "'Giuseppe' trovato" << endl;
}

void test_list_of_ints()
{
	List<int>	intlist;
	
	intlist.insert(20);
	intlist.insert(10);
	intlist.insert(15);
	intlist.insert(4);
	intlist.insert(30);
	intlist.show();
	std::cout << std::endl;
	intlist.delete_element(10);
	intlist.delete_element(15);
	intlist.show();
}

void test_ordered_list_of_ints()
{
	OrderedList<int>	intlist;
	
	intlist.insert(20);
	intlist.insert(10);
	intlist.insert(15);
	intlist.insert(4);
	intlist.insert(30);
	intlist.show();
	std::cout << std::endl;
	intlist.delete_element(10);
	intlist.delete_element(15);
	intlist.show();
}

int main(int argc, char ** argv)
{
	//test_list_of_ints();
	test_ordered_list_of_ints();
}

