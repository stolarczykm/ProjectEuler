// https://www.hackerrank.com/contests/projecteuler/challenges/euler031/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


const vector<int> COINS = {1, 2, 5, 10, 20, 50, 100, 200};
const long MOD = 1000000009L;
const long MAX_N = 100000;





int main() {
    vector< vector<long> > combinations(MAX_N, vector<long>(COINS.size(), 1));

    for (int i = 1; i < combinations.size(); ++i) {
        for (int j = 1; j < COINS.size(); ++j) {
            combinations[i][j] = (
                combinations[i][j-1]
                + (i - COINS[j] >= 0 ? combinations[i - COINS[j]][j] : 0)
            ) % MOD;
        }
    }

    int t;
    cin >> t;

    for (int t0 = 0; t0 < t; ++t0) {
        int n;
        cin >> n;

        
        cout << combinations[n][COINS.size() - 1] << endl;


    }
}


