#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ULL = unsigned long long;


class Number {
private:
    vector<int> digits;

public:
    Number(const vector<int>& digits_ = {}): digits(digits_) {};
    Number(long long number) {
        while (number > 0) {
            digits.push_back(number % 10);
            number = number / 10;
        }
    };

    int length() const {
        return this->digits.size();
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

    long sum_digits() {
        long sum = 0;
        for (auto d: digits) {
            sum += d;
        }
        return sum;
    }

    friend ostream& operator<<(ostream& stream, const Number& num);

    friend Number operator*(const Number &lhs, const Number &rhs);
    friend Number operator*(const Number &lhs, const int &rhs);
    friend Number operator*(const int &lhs, const Number &rhs);
    
};

ostream& operator<<(ostream& os, const Number& num) {
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it)
        os << *it;
    return os;
}

Number operator*(const Number &lhs, const Number &rhs)  {
    Number result = Number(vector<int>(lhs.length() + rhs.length(), 0));
    
    for (int i = 0; i < lhs.length(); ++i) {
        int carry = 0;
        for (int j = 0; j < rhs.length(); ++j) {
            int t = carry + lhs.digits[i] * rhs.digits[j] + result.digits[i+j];
            carry = t / 10;
            result.digits[i+j] = t % 10;
        }
        result.digits[i + rhs.length()] = carry;
    }

    while (result.digits[result.length()-1] == 0) result.digits.pop_back();

    return result;
};

Number operator*(const Number &lhs, const int &rhs) {
    return lhs * Number(rhs);
}

Number operator*(const int &lhs, const Number &rhs) {
    return Number(lhs) * rhs;
}



int main() {
    int n;
    cin >> n;
    Number p = 1L, den = 2L, nom, t;

    for (int i = 2; i <= n; ++i) {
        t = den;
        den = 2*den + p;
        p = t;
        nom = p + den;

        if (nom.length() > den.length()) {
            cout << i << endl;

        }
    }

    return 0;
}