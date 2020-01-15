// https://www.hackerrank.com/contests/projecteuler/challenges/euler026/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


int unit_fraction_cycle_length(int denominator) {
    int t = 10;
    auto set_of_t = unordered_map<int, int>(); 
    int div, mod, i=0;
    while (set_of_t.find(t) == set_of_t.end()) {
        set_of_t[t] = i;
        div = t / denominator;
        mod = t % denominator;
        t = mod * 10;
        ++i;
    }
    if (t == 0) return 0;
    return i - set_of_t[t];
}



int main() {
    int cache_size = 10001;
    vector<int> cache = vector<int>(cache_size, 0);
    vector<int> cache2 = vector<int>(cache_size, 0);
    for (int i = 2; i < cache_size; ++i) {
        cache[i] = unit_fraction_cycle_length(i);
    }

    int idx_max = 0;
    for (int i = 0; i < cache_size; ++i) {
        cache2[i] = idx_max;
        if (cache[i] > cache[idx_max])
            idx_max = i;
    }

    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << cache2[n] << endl;
    }

    return 0;
}
