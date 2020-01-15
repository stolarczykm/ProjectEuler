// https://www.hackerrank.com/contests/projecteuler/challenges/euler025/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include "number.h"

using namespace std;


vector<long> first_terms(int n) {
    vector<long> result = {};
    auto t1 = Number(1);
    auto t2 = Number(1);

    int term = 2;
    while (t2.length() < n) {
        auto temp = t1;
        t1 = t2;
        t2 = t2 + temp;
        ++term;
        for (int i = result.size(); i < t2.length(); ++i) {
            result.push_back(term);
        }
    }
    result[0] = 1;


    return result;
}


int main() {
    auto results = first_terms(5001);
    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << results[n-1] << endl;
    }

    return 0;
}
