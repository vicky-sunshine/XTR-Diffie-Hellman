#include "BigNumber.hpp"
#include "GaloisField.hpp"
#include "GaloisField2.hpp"
#include "XTR.hpp"

int main(int argc, const char * argv[]) {
  
  // Demo
  BigNumber p =  BigNumber("ED63D1E555335010A5515763B2A9D57DAD4CFE62E98A34B");
  GFP::mod_prime = p; // set for all finitie field
  BigNumber g1 = BigNumber("5979DD0F29B6D5787458232E258C35C12898230E4610C58");
  BigNumber g2 = BigNumber("C328613C13A98B242CEF504BBFAAE7015C6C0F4D3BCF162");
  GFP2 Tr_g = GFP2(g1,g2);
  BigNumber a = BigNumber("9166EB14BA0E8757A9FBCF6AD13710AEA4EC4CF3288A");
  BigNumber b = BigNumber("9C4B2B4734B0E8B24119D8C350AC19F199FDEB2BA5DA6");
  
  std::cout << "p: " << p << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "Tr(g): " << Tr_g << std::endl << std::endl;

  // Alice generate key
  std::cout << "Alice select a to generate Tr(g^a)" << std::endl;
  std::vector<GFP2> Sa = Sn(a, Tr_g);
  std::cout << "Tr(g^a) :" << std::endl<< Sa[1] << std::endl << std::endl;
  
  // Bob generate key
  std::cout << "Bob select b to generate Tr(g^b)" << std::endl;
  std::vector<GFP2> Sb = Sn(b, Tr_g);
  std::cout << "Tr(g^b) :" << std::endl<< Sb[1] << std::endl << std::endl;
  
  // Exchange
  std::cout << "Exchange" << std::endl;
  std::vector<GFP2> Sab = Sn(a,  Sb[1]);
  std::cout << "Tr(g^ab) :" << std::endl<< Sab[1] << std::endl;
  
  
  return 0;
}
