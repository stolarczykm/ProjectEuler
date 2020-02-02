// https://www.hackerrank.com/contests/projecteuler/challenges/euler034/problem

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <tuple>

using namespace std;


vector<int> get_digits(int n) {
    if (n == 0) return {0};
    auto res = vector<int>{};
    while (n > 0) {
        res.push_back(n % 10);
        n = n / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<long> factorials = {};
    long r = 1;
    factorials.push_back(r);
    for (int i = 1; i < 10; ++i) {
        r *= i;
        factorials.push_back(r);
    }

    long sum = 0;
    for (int i = 10; i <= n; ++i) {
        auto digits = get_digits(i);
        auto rem = 0;
        for (auto d: digits) {
            rem = (rem + factorials[d]) % i;
        }
        if (rem == 0) {
            sum += i;
        }
    }
    cout << sum << endl;



}