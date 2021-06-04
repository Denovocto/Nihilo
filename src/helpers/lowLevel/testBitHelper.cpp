#include "bitHelper.hpp"
#include <_types/_uint32_t.h>
#include <bitset>
#include <iostream>
int main()
{
	int chosenByte;
	std::cin >> chosenByte;
	uint8_t byte = nihilo::getByteFrom<uint32_t>(chosenByte, 0x12abcdef);
	std::cout << std::hex << static_cast<int>(byte) << std::endl;
}
