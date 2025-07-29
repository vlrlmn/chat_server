#ifndef CIPHER_TEXT_HPP
#define CIPHER_TEXT_HPP

#include <iostream>
#include "BigInteger.hpp"

class CipherText {
    CipherText(BigInteger ciphNum);
    CipherText(std::string ciphText);
    BigInteger Get();
    std::string ToString();
};

#endif