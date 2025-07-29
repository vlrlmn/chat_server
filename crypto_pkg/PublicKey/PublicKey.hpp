#ifndef PUBLIC_KEY_HPP
#define PUBLIC_KEY_HPP

#include <iostream>
#include <list>
#include "../CipherText/CipherText.hpp"
#include "../helpers/BigInteger.hpp"

class PublicKey {
    PublicKey(std::string);
    PublicKey(std::list<BigInteger> pubKeys);
    CipherText Encrypt(int long ciphNum);
    CipherText Encrypt(std::string ciphText);
    std::string ToString();
};

#endif