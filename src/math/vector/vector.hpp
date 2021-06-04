#ifndef VECTOR_HPP
#define VECTOR_HPP

/**
 * @file vector.hpp
 * @brief An Implementation of a Vector with Linear Algebra Function Support.
 * A more elaborate description of swizzling
 */
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
namespace nihilo
{
/**
 * @class Vector vector.hpp
 * Vector of defined type and components.
 * Vector of static size and type with convenience Linear Algebra Function
 * Support.
 * @tparam _type Abstract Data Type or Primitive Data Type of which vector
 * components will consist of.
 * @tparam _components number of components the vector will consist of.
 */
template <typename _type, size_t _components> class Vector
{
  public:
	Vector();
	/**
	 * @name Vector Constructors
	 * Constructor of a Vector.
	 * @{
	 */
	Vector(const Vector<_type, _components>& other); // lvalue
	Vector<_type, _components>& operator=(Vector<_type, _components>&& other);
	Vector(const std::array<_type, _components>& other);
	Vector(std::array<_type, _components>&& other); // rvalue
	/**
	 * @}
	 */
	size_t components() const;

	virtual void print(std::ostream& os) const;
	_type& operator[](size_t idx);
	const _type& operator[](size_t idx) const;
	virtual Vector<_type, _components>
	add(const Vector<_type, _components>& other) const;
	Vector<_type, _components>
	operator+(const Vector<_type, _components>& other) const;
	virtual Vector<_type, _components>
	substract(const Vector<_type, _components>& other) const;
	Vector<_type, _components>
	operator-(const Vector<_type, _components>& other) const;
	Vector<_type, _components> multiply(const _type& scalar) const;
	Vector<_type, _components> operator*(const _type& scalar) const;
	virtual Vector<_type, _components>
	dot(const Vector<_type, _components>& other) const;
	virtual Vector<_type, _components>
	cross(const Vector<_type, _components>& other) const;
	friend std::ostream& operator<<(std::ostream& os,
	                                const Vector<_type, _components>& vector)
	{
		vector.print(os);
		return os;
	}
	~Vector() = default;
	/**
	 * @brief holds the size of the vector array counting from 1.
	 */
  private:
	double norm() const;
	Vector<_type, _components> unit() const;

  protected:
	std::array<_type, _components> vectorArray;
};
template <typename _type, size_t _components>
Vector<_type, _components>::Vector()
{
}
template <typename _type, size_t _components>
Vector<_type, _components>::Vector(const Vector<_type, _components>& other)
{
	vectorArray = other.vectorArray;
}

template <typename _type, size_t _components>
Vector<_type, _components>::Vector(const std::array<_type, _components>& other)
{
	vectorArray = other;
}

template <typename _type, size_t _components>
Vector<_type, _components>::Vector(std::array<_type, _components>&& other)
{
	for (size_t i = 0; i < other.components(); i++) {
		vectorArray[i] = other[i];
	}
}

template <typename _type, size_t _components>
Vector<_type, _components>&
Vector<_type, _components>::operator=(Vector<_type, _components>&& other)
{
	for (size_t i = 0; i < other.components(); i++) {
		vectorArray[i] = other[i];
	}
	return *this;
}

template <typename _type, size_t _components>
size_t Vector<_type, _components>::components() const
{
	return _components;
}

template <typename _type, size_t _components>
void Vector<_type, _components>::print(std::ostream& os) const
{
	os << "[ ";
	for (_type element : vectorArray)
		os << element << " ";
	os << "]" << std::endl;
}

template <typename _type, size_t _components>
_type& Vector<_type, _components>::operator[](size_t idx)
{
	return vectorArray[idx];
}

template <typename _type, size_t _components>
const _type& Vector<_type, _components>::operator[](size_t idx) const
{
	return vectorArray[idx];
}
template <typename _type, size_t _components>
Vector<_type, _components>
Vector<_type, _components>::add(const Vector<_type, _components>& other) const
{
	Vector<_type, _components> result;
	for (int i = 0; i < _components; i++)
		result[i] = other[i] + vectorArray[i];
	return result;
}

template <typename _type, size_t _components>
Vector<_type, _components> Vector<_type, _components>::operator+(
    const Vector<_type, _components>& other) const
{
	return this->add(other);
}

template <typename _type, size_t _components>
Vector<_type, _components> Vector<_type, _components>::substract(
    const Vector<_type, _components>& other) const
{
	Vector<_type, _components> result;
	for (int i = 0; i < _components; i++)
		result[i] = vectorArray[i] - other[i];
	return result;
}

template <typename _type, size_t _components>
Vector<_type, _components> Vector<_type, _components>::operator-(
    const Vector<_type, _components>& other) const
{
	return this->substract(other);
}

template <typename _type, size_t _components>
Vector<_type, _components>
Vector<_type, _components>::multiply(const _type& scalar) const
{
	Vector<_type, _components> result;
	for (int i = 0; i < _components; i++)
		result[i] = vectorArray[i] * scalar;
	return result;
}

template <typename _type, size_t _components>
Vector<_type, _components>
Vector<_type, _components>::operator*(const _type& scalar) const
{
	return this->multiply(scalar);
}
template <typename _type, size_t _components>
double Vector<_type, _components>::norm() const
{
	double radicand = 0;
	for (_type element : vectorArray)
		radicand += std::pow(element, 2);
	return std::sqrt(radicand);
}

template <typename _type, size_t _components>
Vector<_type, _components> Vector<_type, _components>::unit() const
{
	double norm = this->norm();
	return this->multiply(1 / norm);
}
} // namespace nihilo
#endif /* VECTOR_HPP */
