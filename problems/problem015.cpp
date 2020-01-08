// https://www.hackerrank.com/contests/projecteuler/challenges/euler015/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;


long choose_modulo(int n, int k, long mod, vector<vector<long> >& cache) {
    if (n == 1) return 1;
    if (n == k || k == 0) return 1;

    if (k > n-k) k = n-k;

    if (n < cache.size()) {
        if (k < cache[n].size() && cache[n][k] > 0) {
            return cache[n][k];
        }
    }
    long result = (choose_modulo(n-1, k, mod, cache) + choose_modulo(n-1, k-1, mod, cache)) % mod; 
    if (n >= cache.size()) {
        for (int i = cache.size(); i <= n; ++i) {
            cache.push_back(vector<long>(i+1, 0));
            cache[i][0] = 1;
            cache[i][i] = 1;
        }
    }
    cache[n][k] = result;
    return result;
}

int main() {
    vector< vector<long> > cache = vector< vector<long> >();
    cache.push_back({1});
    cache.push_back({1, 1});
    cache.push_back({1, 2, 1});

    int t;
    cin >> t; 

    for (int t0 = 0; t0 < t; ++t0) {
        long m, n;
        cin >> m >> n;

        cout << choose_modulo(n+m, n, 1000000007L, cache) << endl;
    }
}