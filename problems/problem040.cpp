// https://www.hackerrank.com/contests/projecteuler/challenges/euler040/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


const vector<long long> POWERS_OF_TEN = {
    1, 
    10, 
    100, 
    1000, 
    10000, 
    100000, 
    1000000, 
    10000000, 
    100000000, 
    1000000000, 
    10000000000, 
    100000000000, 
    1000000000000, 
    10000000000000, 
    100000000000000, 
    1000000000000000, 
    10000000000000000, 
    100000000000000000, 
    1000000000000000000, 
};


vector<long long> get_boundaries() {
    vector<long long> result = {};
    long long t = 0;
    long long power = 1;
    for (int i = 1; i <= 17; ++i) {
        t += i*9*power;
        result.push_back(t);
        power *= (long long)10L;
    }
    result.push_back(__LONG_LONG_MAX__);
    return result;
}

long get_digit(long long position, vector<long long> boundaries) {
    int i = 0;
    for (; i < boundaries.size(); ++i) {
        if (position <= boundaries[i]) {
            break;
        }
    }
    long long number = (i > 0) ? (position - boundaries[i-1] + i) / (i + 1) + POWERS_OF_TEN[i] - 1 : position;
    int which_digit = (i > 0) ? (position - boundaries[i-1] + i) % (i + 1) : 0;
    return (number / POWERS_OF_TEN[i - which_digit]) % 10;
}


int main() {
    auto boundaires = get_boundaries();
    int t;
    cin >> t;
    for (int t0 = 0; t0 < t; ++t0) {
        long prod = 1;
        for (int j = 0; j < 7; ++j) {
            long long r;
            cin >> r;
            prod *= get_digit(r, boundaires);
        }
        cout << prod << endl;
    }
}