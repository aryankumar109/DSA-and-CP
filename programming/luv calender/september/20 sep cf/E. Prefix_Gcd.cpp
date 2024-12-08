#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200200;
int a[MAXN];
int n;

void solve() {
    cin >> n;
    int g = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
    }
    
    for(int i = 0; i < n; i++) {
        a[i] /= g;
    }
    
    int cur = 0;
    for(int t = 0; t < n; t++) {
        int nc = INT_MAX;
        for(int i = 0; i < n; i++) {
            nc = min(nc, gcd(cur, a[i]));
        }
        cur = nc;
        ans += cur;
        if(cur == 1) {
            ans += n - t - 1;
            break;
        }
    }
    cout << ans * g << '\n';
}

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
