# XTR version for Diffie Hellman
This repo is a simple demo version for XTR-DH, which is used to reduces the computational cost of the DH scheme.

XTR, Efficient and Compact Subgroup Trace Representation, which is a method to represent elements of a subgroup of a multiplicative group of a finite field. It uses the trace over  GF(p^{2}) to represent elements of a subgroup of GF(p^6)

Please look at the [The XTR public key system](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.95.4291) for details. Also, there's keynote on [wiki](https://en.wikipedia.org/wiki/XTR).


## Architecture
```
├── BigNumber            # Basic bignumber arithmetic
│   ├── BigNumber.cpp
│   └── BigNumber.hpp
├── GaloisField          # Finite field
│   ├── GaloisField.cpp  # GF(P)
│   ├── GaloisField.hpp
│   ├── GaloisField2.cpp # GF(P^2), pair of GF(P)
│   └── GaloisField2.hpp
├── README.md
└── XTR-DH               # Sn(c) and Cn calculation
    ├── XTR.cpp
    ├── XTR.hpp
    └── main.cpp
```


## Example
you can find this example in `main.cpp`.
```
// My BigNumber is in hex
BigNumber p =  BigNumber("ED63D1E555335010A5515763B2A9D57DAD4CFE62E98A34B");
GFP::mod_prime = p; // set for all finitie field

BigNumber g1 = BigNumber("5979DD0F29B6D5787458232E258C35C12898230E4610C58");
BigNumber g2 = BigNumber("C328613C13A98B242CEF504BBFAAE7015C6C0F4D3BCF162");
GFP2 Tr_g = GFP2(g1,g2);
BigNumber a = BigNumber("9166EB14BA0E8757A9FBCF6AD13710AEA4EC4CF3288A");
BigNumber b = BigNumber("9C4B2B4734B0E8B24119D8C350AC19F199FDEB2BA5DA6");

// Alice select a to generate Tr(g^a)
std::vector<GFP2> Sa = Sn(a, Tr_g);
/// Sa[1] will be Tr(g^a)
std::cout << "Tr(g^a) :" <<  Sa[1] << std::endl;

// Bob select b to generate Tr(g^b)
std::vector<GFP2> Sb = Sn(b, Tr_g);
// Sb[1] will be Tr(g^b)
std::cout << "Tr(g^b) :" << Sb[1] << std::endl;

// Exchange
std::vector<GFP2> Sab = Sn(a,  Sb[1]);
// Sab[1] will be Tr(g^ab)
std::cout << "Tr(g^ab) :" << Sab[1] << std::endl;
```
