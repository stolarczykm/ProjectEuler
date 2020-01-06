// https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long max_product(vector< vector<int> > grid, int k=4) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector< vector<long> > max_products(rows, vector<long>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            long largest_product = 0;
            if (i >= k-1) {
                long product_vertical = 1;
                for (int t = 0; t<k; ++t) {
                    product_vertical *= grid[i-t][j];
                }
                largest_product = max(largest_product, product_vertical);
            }   
            if (j >= k-1) {
                long product_horizontal = 1;
                for (int t = 0; t<k; ++t) {
                    product_horizontal *= grid[i][j-t];
                }
                largest_product = max(largest_product, product_horizontal);
            }   
            if (j >= k-1 & i >= k-1) {
                long product_diagonal = 1;
                for (int t = 0; t<k; ++t) {
                    product_diagonal *= grid[i-t][j-t];
                }
                long product_second_diagonal = 1;
                for (int t = 0; t<k; ++t) {
                    product_second_diagonal *= grid[i-t][j-k+t+1];
                }
                largest_product = max(largest_product, product_diagonal);
                largest_product = max(largest_product, product_second_diagonal);
            }   
            if (i >= 1) {
                largest_product = max(largest_product, max_products[i-1][j]);
            }
            if (j >= 1) {
                largest_product = max(largest_product, max_products[i][j-1]);
            }

            max_products[i][j] = largest_product;
        }
    }

    return max_products[rows-1][cols-1];

}


int main(){
    vector< vector<int> > grid(20,vector<int>(20));
    for(int grid_i = 0;grid_i < 20;grid_i++){
    	for(int grid_j = 0;grid_j < 20;grid_j++){
    		cin >> grid[grid_i][grid_j];
    		// grid[grid_i][grid_j] = grid_i == grid_j ? (19-grid_i) : 0;

    	}
    }
    cout << max_product(grid) << endl;
    return 0;
}
