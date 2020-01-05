// https://hackerrank.com/contests/projecteuler/challenges/euler009/problem

#include <iostream>
#include <cmath>

using namespace std;


bool is_pythagorean(long a, long b, long c) {
    return a*a + b*b == c*c;
}


long solve(long n) {
    long largest_product = -1;
    for (long i = 1; i < n/3; ++i) {
        long nominator = n * n - 2 * n * i;
        long denominator = 2 * (n - i);
        if (nominator % denominator != 0) continue;
        long j = nominator / denominator;
        long k = n - i - j;

        if (is_pythagorean(i, j, k) ) {
            long product = i*j*k;
            if (product > largest_product) {
                largest_product = product;
            }
        }

    }
    return largest_product;
};


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
