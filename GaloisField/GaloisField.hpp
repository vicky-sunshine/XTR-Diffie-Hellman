/*
 Define Galois Field Element GF(p)
 */

#ifndef GFP_hpp
#define GFP_hpp

#include <iostream>
#include <sstream>
#include "BigNumber.hpp"

class GFP{
private:
  std::vector<BigNumber> extend_eculidean(BigNumber a, BigNumber b) const;
public:
  // member
  static BigNumber mod_prime; // let all Finite Field Share the same memory
  BigNumber i;

  // constructors
  GFP();
  GFP(long long); // directly convert from an int
  GFP(const std::string&);
  GFP(BigNumber);

  // overloaded logical operators as member functions
  friend bool operator==(const GFP&, const GFP&);
  friend bool operator!=(const GFP&, const GFP&);
  friend bool operator>(const GFP&, const GFP&);
  friend bool operator<(const GFP&, const GFP&);
  friend bool operator>=(const GFP&, const GFP&);
  friend bool operator<=(const GFP&, const GFP&);

  // overloaded arithmetic operators as member functions
  friend const GFP operator+(const GFP&, const GFP&);
  friend const GFP operator-(const GFP&, const GFP&);
  friend const GFP operator*(const GFP&, const GFP&);
  friend const GFP operator/(const GFP&, const GFP&);
  friend const GFP operator%(const GFP&, const GFP&);
  friend const GFP operator-(const GFP&);

  friend const GFP inv(const GFP&);
  friend std::vector<GFP> sqrt(GFP&);
  friend GFP pow(GFP& base, BigNumber& power);

  // ouput format for GFP
  friend std::ostream& operator<<(std::ostream&, const GFP&);
  std::string to_string() const;

};

#endif /* GFP_hpp */
