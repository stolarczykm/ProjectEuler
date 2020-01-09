// https://www.hackerrank.com/contests/projecteuler/challenges/euler018/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int max_path(vector< vector<int> > triangle, int i = 0, int j = 0) {
    if (i == triangle.size() - 1) {
        return triangle[i][j];
    }
    return max(max_path(triangle, i+1, j), max_path(triangle, i+1, j+1)) + triangle[i][j];
}


int main() {
    int t0;
    cin >> t0;

    for (int i = 0; i < t0; ++i) {
        int n;
        cin >> n;
        vector< vector<int> > triangle;
        for (int j = 0; j < n; ++j) {
            vector<int> row;
            for (int k = 0; k <= j; ++k) {
                int elem;
                cin >> elem;
                row.push_back(elem);
            }
            triangle.push_back(row);
        }

        cout << max_path(triangle) << endl;
    }

    return 0;
}
