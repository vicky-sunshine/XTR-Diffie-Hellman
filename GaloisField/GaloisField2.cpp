#include "GaloisField2.hpp"
// constructors
GFP2::GFP2() {
  this->first = 0;
  this->second = 0;

}
GFP2::GFP2(const GFP& first, const GFP& second) {
  this->first = first;
  this->second = second;
}
GFP2::GFP2(const GFP& first) {
  /*
   1 + alpha + alpha^2 = 0
   1 = - alpha - alpha^2
   ex:
   3 in GF(P) -> (-3, -3)in  GF(P^2)
   */
  this->first = -first;
  this->second = -first;
}
// overloaded arithmetic operators as member functions
const GFP2 operator+(const GFP2& lhs, const GFP2& rhs) {
  return GFP2(lhs.first + rhs.first, lhs.second + rhs.second);
}

const GFP2 operator-(const GFP2& lhs, const GFP2& rhs) {
  return GFP2(lhs.first - rhs.first, lhs.second - rhs.second);
}

const GFP2 operator*(const GFP2& lhs, const GFP2& rhs) {
  /*
   z = x * y
   
   z1 = x2 * y2 - (x1 * y2 + x2 * y1)
   z2 = x1 * y1 - (x1 * y2 + x2 * y1)
   */
  
  GFP temp = lhs.first * rhs.second + lhs.second * rhs.first;
  GFP first = lhs.second * rhs.second - temp;
  GFP second = lhs.first * rhs.first - temp;
  return GFP2(first, second);
}

const GFP2 operator-(const GFP2& rhs) {
  return GFP2(-rhs.first, -rhs.second);
}

const GFP2 operator*(const GFP& lhs, const GFP2& rhs) {
  /*
   z = a number n * y
   
   z1 = n * y2 - (n * y2 + n * y1)
   z2 = n * y1 - (n * y2 + n * y1)
   */
  
  GFP first = lhs * rhs.first;
  GFP second = lhs * rhs.second;
  return GFP2(first, second);
}


const GFP2 inv(const GFP2& e);

GFP2 power_p(GFP2& base) {
  
  /*
   z = x^p
   
   z1 = x2
   z2 = x1
   */

  return GFP2(base.second, base.first);
}

GFP2 power_2(GFP2& base) {
  
  /*
   z = x^2
   
   z1 = x2 * x2 - 2 * x1 * x2
   z2 = x1 * x1 - 2 * x1 * x2
   */

  GFP temp = 2 * base.first * base.second;
  GFP first = base.second * base.second - temp;
  GFP second = base.first * base.first - temp;
  
  return GFP2(first, second);
}

// ouput format for GFP2
std::ostream& operator<<(std::ostream& os, const GFP2& e) {
  os << "(" << e.first << ", " << e.second << ")";
  return os;
}
