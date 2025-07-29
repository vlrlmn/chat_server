#ifndef PRIVATE_KEY_HPP
#define PRIVATE_KEY_HPP

#include <iostream>
#include <list>
#include "../helpers/BigInteger.hpp"
#include "../CipherText/CipherText.hpp"

class PrivateKey {
    PrivateKey(std::string privKey);
    PrivateKey(std::list<BigInteger> privKeys, BigInteger, BigInteger);

    long int DecipherLong(CipherText ciphNum);
    std::string DecipherString(CipherText ciphText);
    std::string ToString();
};

#endif