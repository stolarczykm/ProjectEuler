// https://www.hackerrank.com/contests/projecteuler/challenges/euler020/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "number.h"
using namespace std;


vector <long> factorial_digit_sums(int n) {
    vector <long> result = {};

    auto factorial = Number(1);
    result.push_back(factorial.sum_digits());
    for (int i = 1; i <= n; ++i) {
        auto multiplier = Number(i);
        factorial = factorial * multiplier;
        result.push_back(factorial.sum_digits());
    }
    return result;
};


int main() {
    auto results = factorial_digit_sums(1000);

    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << results[n] << endl;
    }

    return 0;
}



