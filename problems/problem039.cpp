// https://www.hackerrank.com/contests/projecteuler/challenges/euler039/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


vector<long> count_pythagorean_triples(long p) {
    long a, b, c, t;
    vector<long> triples = vector<long>(p+1);

    for (long n = 1; n <= p; ++n) {
        for (long m = n+1; 2*m*(m+n) <= p; ++m) {
            if (gcd(m,n) != 1 | (m % 2 == 1 & n % 2 == 1)) continue;
            a = m*m - n*n;
            b = 2*m*n;
            c = m*m + n*n;
            for (long k = 1; k * 2*m*(m+n) <= p; ++k) {
                ++triples[k*(a+b+c)];
            }
        }
    }
    return triples;
}


int main() {
    auto triples = count_pythagorean_triples(5*1e6);
    auto results = vector<long>(triples.size());

    long which_max = 0;
    for (long i = 0; i < results.size(); ++i) {
        if (triples[i] > triples[which_max]) {
            which_max = i;
        }
        results[i] = which_max;
    }
    
    long t, n;
    cin >> t;
    for (long i = 0; i < t; ++i) {
        cin >> n;
        cout << results[n] << endl;
    }
    
}