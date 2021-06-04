#include "vector.hpp"
#include <array>

int main()
{
	std::array<double, 3> arr = {1, 2, 3};
	nihilo::Vector<double, 3> vec3 = arr;
	std::cout << "Components: " << vec3.components() << std::endl;
	std::cout << "Values: " << vec3[0] << vec3[1] << vec3[2] << std::endl;
	std::cout << "Add: " << vec3 + vec3 << std::endl;
	std::cout << "Sub: " << vec3 - vec3 << std::endl;
	std::cout << "Mult: " << vec3 * 3 << std::endl;
	std::cout << "Norm: " << vec3.norm() << std::endl;
	std::cout << "Unit: " << vec3.unit() << std::endl;
	std::cout << vec3 << std::endl;
	return 0;
}
