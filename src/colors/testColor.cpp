#include "color.hpp"
#include <iostream>
int main()
{
	nihilo::Color test(0x12abcdef);
	nihilo::Color white(255, 255, 255, 255);
	std::cout << std::hex << test << std::endl;
	std::cout << white << std::endl;
	return 0;
}
