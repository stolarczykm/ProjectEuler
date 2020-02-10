// https://www.hackerrank.com/contests/projecteuler/challenges/euler038/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> get_digits(int n) {
    if (n == 0) return {0};
    auto res = vector<int>{};
    while (n > 0) {
        res.push_back(n % 10);
        n = n / 10;
    }
    return res;
}

bool is_pandigital_multiplier(int n, int k) {
    unordered_set<int> digits = {};
    int i = 1;
    while (true) {
        auto x = n * i;
        auto multiplier_digits = get_digits(x);
        for (auto d: multiplier_digits) {
            if (d == 0) {
                return false;
            }
            if (digits.find(d) != digits.end()) {
                return false;
            }
            digits.insert(d);
        };
        
        if (digits.size() == k) {
            if (k == 8 && digits.find(9) != digits.end()) {
                return false;
            }
            return true;
        }
        ++i;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 2; i < n; ++i) {
        if (is_pandigital_multiplier(i,  k)) {
            cout << i << endl;
        }
    }
}