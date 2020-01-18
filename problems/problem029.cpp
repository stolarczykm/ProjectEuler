// https://www.hackerrank.com/contests/projecteuler/challenges/euler029/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> which_power = vector<int>(n+1, 0);
    vector<int> exponent = vector<int>(n+1, 0);

    for (long i = 2; i <= n; ++i) {
        if (which_power[i] > 0) continue;
        which_power[i] = 1;
        exponent[i] = i;
        auto power = i * i;
        int t = 2;
        while (power <= n) {
            which_power[power] = t;
            exponent[i] = i;
            power *= i;
            ++t;
        }
    }

    vector<int> new_powers = vector<int>(log2(n) + 2, 0);
    unordered_set<int>  powers_so_far = {};
    for (int i = 1; i <= log2(n) + 1; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (powers_so_far.find(i * j) == powers_so_far.end())
                ++new_powers[i];
            powers_so_far.insert(i * j);
        }
    }

    long combinations = 0L;
    for (int i = 2; i <= n; ++i) {
        combinations += new_powers[which_power[i]];
    }

    cout << combinations << endl;
}


