#include "CipherText.hpp"

mpz_class CipherText::Get() const {
    return value;
}

CipherText::CipherText(mpz_class ciphNum): value(ciphNum) {}

CipherText::CipherText(std::string ciphText): value(ciphText) {}

std::string CipherText::ToString() const {
    return value.get_str();
}