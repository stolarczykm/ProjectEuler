#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Number {
private:
    vector<int> digits;

public:
    Number(vector<int> digits_ = {}): digits(digits_) {};
    Number(long long number) {
        while (number > 0) {
            digits.push_back(number % 10);
            number = number / 10;
        }
    };

    int length() const {
        return this->digits.size();
    }

    operator long() const {
        long sum = 0;
        long multiplier = 1;
        for (int i = 0; i < digits.size(); ++i) {
            sum += digits[i] * multiplier;
            multiplier *= 10;
        }
        return sum;
    }

    Number operator+(Number &other) {
        int i = 0;
        int sum = 0;

        Number result = Number();

        while (i < this->length() && i < other.length()) {
            sum = this->digits[i] + other.digits[i] + sum;
            result.digits.push_back(sum % 10);

            sum = sum / 10;
            ++i;
        }

        while (i < this->length()) {
            sum = this->digits[i] + sum;
            result.digits.push_back(sum % 10);

            sum = sum / 10;
            ++i;
        }

        while (i < other.length()) {
            sum = other.digits[i] + sum;
            result.digits.push_back(sum % 10);
            sum = sum / 10;
            ++i;
        }

        while (sum > 0) {
            result.digits.push_back(sum % 10);
            sum = sum / 10;
            ++i;
        }

        return result;
    };

    Number operator*(Number &other) {
        Number result = Number(vector<int>(this->length() + other.length(), 0));
        
        for (int i = 0; i < length(); ++i) {
            int carry = 0;
            for (int j = 0; j < other.length(); ++j) {
                int t = carry + digits[i] * other.digits[j] + result.digits[i+j];
                carry = t / 10;
                result.digits[i+j] = t % 10;
            }
            result.digits[i + other.length()] = carry;
        }

        while (result.digits[result.length()-1] == 0) result.digits.pop_back();

        return result;
    };

    long sum_digits() {
        long sum = 0;
        for (auto d: digits) {
            sum += d;
        }
        return sum;
    }
    
};