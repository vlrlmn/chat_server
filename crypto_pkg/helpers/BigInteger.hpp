#ifndef BIG_INTEGER_HPP
#define BIG_INTEGER_HPP

#include <string>
#include <iostream>
#include <algorithm>

class BigInteger {
private:
    std::string digits; 

    static std::string addStrings(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0;
        size_t maxLen = std::max(a.size(), b.size());

        for (size_t i = 0; i < maxLen || carry; ++i) {
            int digitA = (i < a.size()) ? a[i] - '0' : 0;
            int digitB = (i < b.size()) ? b[i] - '0' : 0;
            int sum = digitA + digitB + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }
        return result;
    }

public:
    BigInteger() : digits("0") {}

    BigInteger(const std::string& number) {
        std::string temp = number;
        while (temp.size() > 1 && temp[0] == '0') // убираем ведущие нули
            temp.erase(0, 1);
        std::reverse(temp.begin(), temp.end());
        digits = temp;
    }

    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        result.digits = addStrings(this->digits, other.digits);
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& bi) {
        std::string copy = bi.digits;
        std::reverse(copy.begin(), copy.end());
        return os << copy;
    }
};

#endif
