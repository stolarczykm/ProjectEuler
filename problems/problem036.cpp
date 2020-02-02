// https://www.hackerrank.com/contests/projecteuler/challenges/euler036/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int n_digits(long n, int base) {
    return floor(log(n) / log(base)) + 1;
}


bool is_palindrome(long n, int base) {
    auto digits = n_digits(n, base);
    long pow1 = pow(base, digits-1);
    for (int i = 0; i < digits/2; ++ i) {
        long digit_front = n / pow1;
        long digit_back = n % base;
        if (digit_front != digit_back) {
            return false;
        }
        n = (n - digit_front * pow1 - digit_back) / base;
        pow1 = pow1 / (base * base);
    }
    return true;
}


int main() {
    long n;
    int k;
    cin >> n >> k;

    long sum = 0;
    for (long i = 1; i < n; ++i) {
        if (is_palindrome(i, 10) && is_palindrome(i, k)) {
            sum += i;
        }
    }
    cout << sum << endl;

}