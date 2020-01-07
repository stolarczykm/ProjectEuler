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

template<class T, class S>
bool contains(unordered_map<T, S> m, T key) {
    if (m.find(key) == m.end()) {
        return false;
    }
    return true;
}



long collatz_sequence_length(long n, vector<long> &cache2) {
    if (n == 1) return 1;
    if (n < cache2.size() && cache2[n] > 0) {
        return cache2[n];
    }
    
    long sequence_length;
    if (n % 2) {
        sequence_length = collatz_sequence_length(3*n + 1, cache2) + 1;
    } else {
        sequence_length = collatz_sequence_length(n / 2, cache2) + 1;
    }

    if (n < cache2.size()) {
        cache2[n] = sequence_length;
    }
    return sequence_length;
}


int main() {
    vector<long> cache2 = vector<long>(5000001);
    unordered_map<long, int> cache_max_ind = unordered_map<long, int>();
    cache2[1] = 1;
    cache_max_ind[1] = 1;
    cache_max_ind[2] = 2;

    int t;
    cin >> t; 

    long max_n0 = 2;

    for (int t0 = 0; t0 < t; ++t0) {

        long n0;
        cin >> n0;

        for (int n1 = max_n0; n1 <= n0; ++n1) {
            int n = n1;
            collatz_sequence_length(n, cache2);
        }

        int which = 0;
        int max_length = -1;
        if (n0 < cache_max_ind.size()) {
            which = cache_max_ind[n0];
            max_length = cache2[which];
        } else {
            which = cache_max_ind[max_n0];
            max_length = cache2[which];
        }

        
        for (int z=max_n0; z <= n0; ++z) {
            if (cache2[z] >= max_length) {
                which = z;
                max_length = cache2[z];
            }
            cache_max_ind[z] = which;
        }
        cout << which << endl;

        max_n0 = max(n0, max_n0);
    }
    return 0;
}
