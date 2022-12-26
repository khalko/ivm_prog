#include "main.h"
#include <iostream>

void hello_world(int year)
{
	std::cout << "Hello world of " << year << "!" << std::endl;
}

int main()
{
	int year;
	std::cout << "What year is it?" << std::endl;
	std::cin >> year;
    hello_world(year);
    return 0;
}
