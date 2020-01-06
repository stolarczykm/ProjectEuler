// https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<long, long> prime_decomposition(long n) {
    map<long, long> decomposition = map<long, long>();

    for (long p = 2; p*p <= n & n > 1; ++p) {
        long cnt = 0;
        while (n % p == 0) {
            n = n / p;
            ++cnt;
        }
        if (cnt > 0) {
            decomposition[p] = cnt;
        }
    }

    if (n > 1) decomposition[n] = 1;

    return decomposition;

}

long count_divisors(long n) {
    auto decomposition = prime_decomposition(n);
    long divisors = 1;
    for (auto it = decomposition.begin(); it != decomposition.end(); ++it) {
        divisors *= it->second+1;
    }
    return divisors;
}

long solve(long n, vector<long>* cache) {
    long divisors = 0;
    long i = 1;
    long triangle_number = 0;
    long max_divisors = 0;
    while (divisors <= n) {
        if (i < cache->size()) {
            triangle_number = (i*(i+1))/ 2;
            divisors = (*cache)[i]; 
        } else {
            triangle_number = (i*(i+1))/ 2;
            divisors = count_divisors(triangle_number);
        }

        max_divisors = max(divisors, max_divisors);

        if (i >= cache->size()) {
            cache->push_back(max_divisors);
        }
        
        ++i;
    }
    return triangle_number; 
    
}


int main() {
    // (*cache)[i] is maximum number of dividors of first i traingle numbers
    vector<long>* cache = new vector<long>(0);
    cache->push_back(0);
    cache->push_back(1);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        long n;
        cin >> n;

        cout << solve(n, cache) << endl;
    }
    delete cache;
    return 0;
}

