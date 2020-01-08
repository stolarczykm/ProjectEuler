// https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long next_collatz_number(long n) {
    if (n % 2 == 1) {
        return 3*n + 1;
    }
    return n / 2;
}


long collatz_sequence_length(long n, vector<long> &cache) {
    if (n == 1) return 1;
    if (n < cache.size() && cache[n] > 0) {
        return cache[n];
    }
    
    long sequence_length;
    if (n % 2) {
        sequence_length = collatz_sequence_length(3*n + 1, cache) + 1;
    } else {
        sequence_length = collatz_sequence_length(n / 2, cache) + 1;
    }

    if (n < cache.size()) {
        cache[n] = sequence_length;
    }
    return sequence_length;
}


int main() {
    vector<long> sequence_lengths_cache = vector<long>(5000001);
    vector<long> result_cache = vector<long>(5000001);
    sequence_lengths_cache[1] = 1;
    result_cache[1] = 1;
    result_cache[2] = 2;

    int t;
    cin >> t; 

    long max_n0 = 2;

    for (int t0 = 0; t0 < t; ++t0) {

        long n0;
        cin >> n0;

        for (int n1 = max_n0; n1 <= n0; ++n1) {
            int n = n1;
            collatz_sequence_length(n, sequence_lengths_cache);
        }

        int which = 0;
        int max_length = -1;
        if (n0 <= max_n0) {
            which = result_cache[n0];
            max_length = sequence_lengths_cache[which];
        } else {
            which = result_cache[max_n0];
            max_length = sequence_lengths_cache[which];
        }

        
        for (int z=max_n0; z <= n0; ++z) {
            if (sequence_lengths_cache[z] >= max_length) {
                which = z;
                max_length = sequence_lengths_cache[z];
            }
            result_cache[z] = which;
        }
        cout << which << endl;

        max_n0 = max(n0, max_n0);
    }
    return 0;
}
