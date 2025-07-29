#ifndef PRIVATE_KEY_HPP
#define PRIVATE_KEY_HPP

#include <iostream>
#include <list>
#include <gmpxx.h>
#include "../CipherText/CipherText.hpp"

class PrivateKey {
    PrivateKey(std::string privKey);
    PrivateKey(std::list<mpz_class> privKeys, mpz_class, mpz_class);

    long int DecipherLong(CipherText ciphNum);
    std::string DecipherString(CipherText ciphText);
    std::string ToString();
};

#endif