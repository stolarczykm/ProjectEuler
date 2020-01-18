// https://www.hackerrank.com/contests/projecteuler/challenges/euler030/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

bool is_sum_of_digit_powers(long n, int power) {
    long sum_of_digit_powers = 0;
    long n_copy = n;
    while (n > 0) {
        sum_of_digit_powers += pow(n % 10, power);
        n = n / 10;
    }
    return n_copy ==  sum_of_digit_powers;
}


int main() {
    int max_digits = 7;
    int n;
    cin >> n;

    long sum = 0;
    for (long i = 10; i < pow(10, max_digits); ++i) {
        if (is_sum_of_digit_powers(i, n)) {
            // cout << i << endl;
            sum += i;
        }
    }
    cout << sum << endl;
}


