#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v) {
        cin >> it;
    }
    
    sort(v.begin(), v.end());
    int ans = (v[0] + v[1]) / 2;
    for (int i = 2; i < n; i++) {
        ans = (ans + v[i]) / 2;
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
