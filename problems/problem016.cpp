// https://www.hackerrank.com/contests/projecteuler/challenges/euler016/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<long> get_sums(int n) {
    auto sums = vector<long>();
    vector<int> digits = {1};

    for (int i = 0; i <= n; ++i) {
        int remainder = 0; 
        long sum = 0;
        for (int j = 0; j < digits.size(); ++j) {
            sum += digits[j]);
            int digit_double = digits[j] * 2 + remainder;
            digits[j] = digit_double % 10;
            remainder = digit_double / 10;
        }
        sums.push_back(sum);
        if (remainder > 0) {
            digits.push_back(remainder);
        }
    }
    return sums;
}


int main() {
    vector<long> sums = get_sums(1000);


    int t;
    cin >> t; 

    for (int t0 = 0; t0 < t; ++t0) {
        int n;
        cin >> n;

        cout << sums[n] << endl;
    }
}