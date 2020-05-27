// https://www.hackerrank.com/contests/projecteuler/challenges/euler044/problem

#include <cmath>
#include <cstdio>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long> get_pentagonal_numbers(long n) {
    auto result = vector<long>();
    for (long i = 1; i < n; ++ i) {
        result.push_back((i * (3*i - 1)) / 2);
    }
    return result;
}

long bin_search(const vector<long>& x, long& element, long left=0, long right=-1) {
    if (right == -1) 
        right = x.size();
    if (right - left < 1) 
        return -1;

    long middle = left + (right - left) / 2;

    if (x[middle] == element) {
        return middle;
    }

    if (element < x[middle]) {
        return bin_search(x, element, left, middle);
    }

    return bin_search(x, element, middle + 1, right);
}

int main() {
    long n, k;
    cin >> n >> k;
    auto pentagonal_numbers = get_pentagonal_numbers(2*n);

    for (long i = k; i < n-1; ++i) {
        auto diff = pentagonal_numbers[i] - pentagonal_numbers[i-k];
        if (bin_search(pentagonal_numbers, diff) >= 0) {
            cout << pentagonal_numbers[i] << endl;
            continue;
        }
        auto sum = pentagonal_numbers[i-k] + pentagonal_numbers[i];
        if (bin_search(pentagonal_numbers, sum) >= 0) {
            cout << pentagonal_numbers[i] << endl;
        }
    }
}
