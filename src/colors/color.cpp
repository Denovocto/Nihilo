#include "color.hpp"

namespace nihilo
{
Color::Color() { vectorArray.fill(0); }
Color::Color(const uint32_t rgba)
{
	uint8_t r = getByteFrom<uint32_t>(0, rgba);
	uint8_t g = getByteFrom<uint32_t>(1, rgba);
	uint8_t b = getByteFrom<uint32_t>(2, rgba);
	uint8_t a = getByteFrom<uint32_t>(3, rgba);
	std::array<uint8_t, 4> tempColor = {r, g, b, a};
	vectorArray.swap(tempColor);
}

Color::Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a)
{
	std::array<uint8_t, 4> tempColor = {r, g, b, a};
	vectorArray.swap(tempColor);
}

void Color::print(std::ostream& os) const
{
	os << "[ ";
	for (uint8_t element : vectorArray)
		os << static_cast<uint32_t>(element) << " ";
	os << "]" << std::endl;
}
} // namespace nihilo
