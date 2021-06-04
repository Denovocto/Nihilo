#include <iostream>

void func()
{
	const char* name = __PRETTY_FUNCTION__;
	std::cout << name << std::endl;
}

int main() { func(); }
