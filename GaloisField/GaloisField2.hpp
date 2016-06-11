/*
 Define Galois Field Element GF(p^2)
 where p ≡ 2 mod 3
 */

#ifndef GaloisField2_hpp
#define GaloisField2_hpp

#include <iostream>
#include <sstream>
#include "GaloisField.hpp"

class GFP2{
public:
  GFP first;
  GFP second;

  // constructors
  GFP2();
  GFP2(const GFP&, const GFP&);
  GFP2(const GFP&);
  
  // overloaded arithmetic operators as member functions
  friend const GFP2 operator+(const GFP2&, const GFP2&);
  friend const GFP2 operator-(const GFP2&, const GFP2&);
  friend const GFP2 operator*(const GFP2&, const GFP2&);
  friend const GFP2 operator-(const GFP2&); // neggation
  friend const GFP2 operator*(const GFP&, const GFP2&);

  friend const GFP2 inv(const GFP2&);
  friend GFP2 power_p(GFP2& base);
  friend GFP2 power_2(GFP2& base);

  // ouput format for GFP2
  friend std::ostream& operator<<(std::ostream&, const GFP2&);
};


#endif /* GaloisField2_hpp */
