// https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long largest_product(string num, int k) {
    if (num.size() < k) {
        throw "String is too short";
    }

    long largest_product = 0;
    for (int i = 0; i < num.size() - k; ++i) {
        long product = 1;
        for (int j = 0; j < k; ++j) {
            product *= (num[i+j] - '0');
        }

        if (product > largest_product) {
            largest_product = product;
        }
    }

    return largest_product;
}


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        cout << largest_product(num, k) << endl;
    }
    return 0;
}


