// https://www.hackerrank.com/contests/projecteuler/challenges/euler032/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;



bool has_unique_digits(long a, int n) {
    auto digits = vector<bool>(n, false);
    while (a > 0) {
        int digit = a % 10;
        if (digit < 1 || digit > n) return false;
        if (digits[digit-1]) return false;
        digits[digit-1] = true;
        a = a / 10;
    }
    return true;
}

bool n_digits(long a) {
    int count = 0; 
    while (a > 0) {
        a = a / 10;
        count++;
    }
    return count;
}

bool is_pandigital(long a, long b, long c, int n) {
    auto digits = vector<bool>(n, false);
    while (a > 0) {
        int digit = a % 10;
        if (digit < 1 || digit > n) return false;
        if (digits[digit-1]) return false;
        digits[digit-1] = true;
        a = a / 10;
    }

    while (b > 0) {
        int digit = b % 10;
        if (digit < 1 || digit > n) return false;
        if (digits[digit-1]) return false;
        digits[digit-1] = true;
        b = b / 10;
    }

    while (c > 0) {
        int digit = c % 10;
        if (digit < 1 || digit > n) return false;
        if (digits[digit-1]) return false;
        digits[digit-1] = true;
        c = c / 10;
    }

    for (auto x: digits) {
        if (!x) return false;
    }
    return true;
}




long brute_force(int n) {
    long sum = 0;
    for (long i = 1; i < pow(10, n); ++i) {
        if (!has_unique_digits(i, n)) continue;
        auto i_digits = n_digits(i);

        for (long j = i+1; j <= pow(10, n - i_digits) / i; ++j) {
            if (!has_unique_digits(j, n)) continue;

            long product = i * j;
            if (is_pandigital(i, j, product, n)) {
                sum += product;
            }
        }
    }
    return sum;

}



int main() {
    int n;
    cin >> n;

    // cout << is_pandigital(39, 186, 7254, 9) << endl;
    cout << brute_force(n) << endl;
}


