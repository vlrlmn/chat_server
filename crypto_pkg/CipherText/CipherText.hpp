#ifndef CIPHER_TEXT_HPP
#define CIPHER_TEXT_HPP

#include <iostream>
#include <gmpxx.h>

class CipherText {
    private:
        mpz_class value;
    public:
        explicit CipherText(mpz_class ciphNum);
        explicit CipherText(std::string ciphText);
        mpz_class Get() const;
        std::string ToString() const;
};

#endif