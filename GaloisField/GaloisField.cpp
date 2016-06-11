#include "GaloisField.hpp"
// Initial Finite Field Prime Number
BigNumber GFP::mod_prime = 1;

// private method
/*
 decryption
 use extend eculidean algorithm to find a, b s.t ap + bq = gcd(a,b)
 */
std::vector<BigNumber> GFP::extend_eculidean(BigNumber a, BigNumber b) const {
  BigNumber q,x,lastx,y,lasty,temp1,temp2,temp3;
  x=0;
  y=1;
  lastx=1;
  lasty=0;
  while (b!=0) {
    q= a/b;
    temp1= a%b;
    a=b;
    b=temp1;

    temp2 = x;
    x=lastx-q*x;
    lastx = temp2;

    temp3 = y;
    y = lasty-q*y;
    lasty=temp3;

  }
  std::vector<BigNumber> result{lastx, lasty};
  return result;
}



// constructors
GFP::GFP() {
  this->i = BigNumber(0);
}

GFP::GFP(long long input) {
  this->i = input % mod_prime;
}

GFP::GFP(const std::string& input) {
  this->i = BigNumber(input) % mod_prime;

}

GFP::GFP(BigNumber input) {
  this->i = input % mod_prime;
}


// overloaded logical operators as member functions
bool operator==(const GFP& lhs, const GFP& rhs) {
  return lhs.i == rhs.i;
}

bool operator!=(const GFP& lhs, const GFP& rhs) {
  return lhs.i != rhs.i;
}

bool operator>(const GFP& lhs, const GFP& rhs) {
  return lhs.i > rhs.i;
}

bool operator<(const GFP& lhs, const GFP& rhs) {
  return lhs.i < rhs.i;
}

bool operator>=(const GFP& lhs, const GFP& rhs) {
  return lhs.i >= rhs.i;
}

bool operator<=(const GFP& lhs, const GFP&rhs) {
  return lhs.i <= rhs.i;
}


// arithmetic
const GFP operator+(const GFP& lhs, const GFP& rhs) {
  BigNumber add = lhs.i + rhs.i;
  if (add < 0) {
    add = rhs.mod_prime + add;
  }

  return GFP(add % rhs.mod_prime);
}

const GFP operator-(const GFP& lhs, const GFP& rhs) {
  BigNumber sub = lhs.i - rhs.i;
  if (sub < 0) {
    sub = rhs.mod_prime + sub ;
  }
  return GFP(sub% rhs.mod_prime);
}

const GFP operator*(const GFP& lhs, const GFP& rhs) {
  BigNumber mul = lhs.i * rhs.i;
  if (mul < 0) {
    mul = rhs.mod_prime + mul;
  }
  return GFP(mul % rhs.mod_prime);
}

const GFP operator/(const GFP& lhs, const GFP& rhs) {
  BigNumber rhs_inv = inv(rhs).i;
  BigNumber div = lhs.i * rhs_inv % rhs.mod_prime;
  return GFP(div);
}

const GFP operator%(const GFP& lhs, const GFP& rhs) {
  BigNumber mod = lhs.i % rhs.i;
  if (mod < 0) {
    mod = rhs.mod_prime + mod;
  }
  return GFP(mod % rhs.mod_prime);
}

const GFP operator-(const GFP& rhs) {
  BigNumber sub = (rhs.mod_prime - rhs.i) % rhs.mod_prime;
  return GFP(sub);
}

const GFP inv(const GFP& rhs) {
  std::vector<BigNumber> result = rhs.extend_eculidean(rhs.i, rhs.mod_prime);
  BigNumber inv = result[0] % rhs.mod_prime;
  if (inv < 0 ) {
    inv =  (rhs.mod_prime + inv) % rhs.mod_prime;
  }

  return GFP(inv);
}

std::vector<GFP> sqrt(GFP& input) {

  BigNumber power = (input.mod_prime+1)/4;
  GFP r1 = pow(input, power);
  GFP r2 = (GFP::mod_prime - r1);
  std::vector<GFP> root{r1,r2};

  return root;
}

GFP pow(GFP& base, BigNumber& power) {
  GFP sum = base;
  if  (power ==0) return 1;

  GFP odd(1);
  while (base!=1 && power>1){
    if (power % 2 != 0){ // odd
      odd = odd * base;
    }
    power = power / 2;
    base = base * base;
  }

  return base * odd;
}

// output
std::ostream& operator<<(std::ostream& os, const GFP& rhs) {
  os << rhs.i;
  return os;
}

std::string GFP::to_string() const{
  std::stringstream ss;
  std::string str;
  ss << (*this).i;
  ss >> str;
  return str;
}
