// https://www.hackerrank.com/contests/projecteuler/challenges/euler024/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


string f(long N, int string_length=4) {
    vector<int> indexes = vector<int>(string_length);
    for (int i = 0; i < string_length; ++i) {
        long mod = i + 1;
        indexes[string_length-1-i] = N % mod;
        N = N / mod;
    }

    vector<bool> is_taken = vector<bool>(string_length, false);
    string result(string_length, 'a');

    for (int i = 0; i < string_length; ++i) {
        int new_idx = 0;
        int j = 0;
        while (is_taken[new_idx] || j < indexes[i]) {
            if (is_taken[new_idx]) ++new_idx;
            else {++j; ++new_idx;}
        }
        result[i] = (char)(new_idx + 'a');
        is_taken[new_idx] = true;
    }

    return result;
}


int main() {
    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        long n;
        cin >> n;
        cout << f(n-1, 13) << endl;
    }

    return 0;
}
