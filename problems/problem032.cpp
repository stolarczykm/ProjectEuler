// https://www.hackerrank.com/contests/projecteuler/challenges/euler032/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int n_digits(long a) {
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
    set<long> products = {};
    vector<bool> digits_i;
    vector<bool> digits_j;
    for (long i = 1; i < pow(10, n/2); ++i) {
        auto i_digits = n_digits(i);

        auto min_j_digits = (n /2) - i_digits;
        auto max_j_digits = ((n+1) / 2) - i_digits;
        long j_start = max(i+1, (long)pow(10L, min_j_digits - 1));
        long j_end = (long)pow(10L, max_j_digits); 
        for (long j = j_start; j < j_end; ++j) {
            long product = i * j;

            if (is_pandigital(i, j, product, n)) {
                products.insert(product);
            }
        }
    }

    long sum = 0;
    for (auto product: products) {
        sum += product;
    }

    return sum;

}


int main() {
    int n;
    cin >> n;

    // cout << is_pandigital(39, 186, 7254, 9) << endl;
    cout << brute_force(n) << endl;
}