#include <iostream>
#include <vector>

using namespace std;
using ULL = unsigned long long;

int main(int argc, char const *argv[]) {
    int n;
    ULL k;
    cin >> n >> k;
    
    long count = 0;
    
    auto vec = new vector<ULL>(n+1, 1);
    auto prev_vec = new vector<ULL>(n+1, 1);
    vector<ULL>* temp;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            auto t = (*prev_vec)[j] + (*prev_vec)[j-1];
            t = min(t, k+1); 
            (*vec)[j] = t;

            
            if ((*vec)[j] > k) count++;
        }

        temp = prev_vec;
        prev_vec = vec;
        vec = temp;
    }
    cout << count << endl;
}