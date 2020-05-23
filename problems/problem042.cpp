// https://www.hackerrank.com/contests/projecteuler/challenges/euler042/problem

#include <cmath>
#include <cstdio>
#include <iostream>

// n^2 + n - 2x = 0
// delta = 1 + 8x
// if sqrt(delta) is integer and odd: (-1 + sqrt(1+8x)) / 2
// else: -1

using namespace std;




int main() {
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; ++t0) {
        long long x;
        cin >> x;
        long long delta = 1 + 8*x;
        long long sqrt_delta = sqrt(delta);
        if (sqrt_delta * sqrt_delta != delta || sqrt_delta % 2 == 0) {
            cout << -1 << endl;
        } else {
            cout << (sqrt_delta - 1) / 2 << endl;
        }
    }

    return 0;
}