/*
 * cin_cout.cpp
 */
 #include <iostream>
 
int main(int argc, char * argv[])
{
	std::cout << "Insert a number:";
	// scanf("%d", &a);
	int a;
	std::cin >> a;
	int b = a * 2;
	std::cout << "The value is : " << b << std::endl;
	return 0;
}

