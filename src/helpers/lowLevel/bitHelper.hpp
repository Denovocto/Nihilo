#include <cstdint>
namespace nihilo
{
template <typename _uintX>
uint8_t getByteFrom(const uint8_t numByte, const _uintX word)
{
	_uintX byteShift;
	_uintX mask;
	uint8_t wordSize = sizeof(_uintX);

	if (numByte >= wordSize) {
		byteShift = (wordSize * 8);
	} else {
		byteShift = (wordSize * 8) - (8 * (numByte + 1));
	}

	mask = 0xff << byteShift;
	return (word & mask) >> byteShift;
}

}
