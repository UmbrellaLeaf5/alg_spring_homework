#pragma once

// std libs:
#include <stdexcept>

// my libs:
#include <util.hpp>

// @brief значение температуры в градусах цельсия
class Temperature {
 public:
  Temperature() = default;

  Temperature(float value) : value_{value} {
    if (value < -273.15)
      throw std::logic_error("temperature cannot be less than absolute zero");
  }

  Temperature(const Temperature& p) = default;

  Temperature& operator=(const Temperature& p) = default;

  Temperature& operator=(float p) {
    *this = Temperature(p);
    return *this;
  }

  Temperature& operator+=(const Temperature& t) {
    value_ += t.value_;
    return *this;
  }

  Temperature& operator-=(const Temperature& t) {
    value_ -= t.value_;
    return *this;
  }

  auto operator<=>(const Temperature& b) const = default;
  auto operator<=>(float value) const { return value_ <=> value; }

  friend std::istream& operator>>(std::istream& is, Temperature& vec);

  explicit operator float() const { return value_; }
  explicit operator std::string() const {
    // https://en.wikipedia.org/wiki/Degree_symbol?useskin=vector
    return ErasedZerosStr(value_) + " °C";
  }

 private:
  // температура не должна быть слишком большой
  // (поэтому здесь float, а не double)
  float value_;
};

// здесь важно именно копирование, так как += и -= модифицирующие
inline Temperature operator+(Temperature a, Temperature b) { return a += b; }
inline Temperature operator-(Temperature a, Temperature b) { return a -= b; }

inline std::ostream& operator<<(std::ostream& os, const Temperature& t) {
  return os << std::string(t);
}

inline std::istream& operator>>(std::istream& is, Temperature& t) {
  return is >> t.value_;
}
