#include "../helpers/lowLevel/bitHelper.hpp"
#include "../math/vector/vector.hpp"
#include <cstdint>
#include <ostream>
#include <string>
namespace nihilo
{
class Color : public Vector<uint8_t, 4>
{
  public:
	Color();
	Color(const uint32_t rgba);
	Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a);
	~Color() = default;
	void print(std::ostream& os) const override;

  private:
};
} // namespace nihilo
