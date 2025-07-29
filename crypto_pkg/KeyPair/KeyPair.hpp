#ifndef KEY_PAIR_HPP
#define KEY_PAIR_HPP

#include <iostream>
#include "../PrivateKey/PrivateKey.hpp"
#include "../PublicKey/PublicKey.hpp"

class KeyPair {
    static KeyPair Generate(int n=128);
    PublicKey GetPublicKey();
    PrivateKey GetPrivateKey();
    KeyPair(PublicKey pubKey, PrivateKey privKey);
    KeyPair(std::string);
    std::string ToString();
};

#endif