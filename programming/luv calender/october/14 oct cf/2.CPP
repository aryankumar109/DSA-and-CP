#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    vector<int> n_values(t), k_values(t);
    
    for (int i = 0; i < t; ++i) {
        cin >> n_values[i];
    }
    
    for (int i = 0; i < t; ++i) {
        cin >> k_values[i];
    }
    
    for (int i = 0; i < t; ++i) {
        int n = n_values[i], k = k_values[i];
        
        if (n == k || k == 0) {
            cout << 1 << endl;
        } else {
            long long result = 1;
            for (int j = 0; j < k; ++j) {
                result = (result * 2) % MOD;
            }
            cout << result << endl;
        }
    }
    
    return 0;
}
