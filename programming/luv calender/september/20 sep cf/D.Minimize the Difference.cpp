#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define ll long long 

void manualReverse(vector<ll>& a, int n) {
    for (int i = 1; i <= n / 2; ++i) {
        swap(a[i], a[n - i + 1]);
    }
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        manualReverse(a, n);

        ll s1 = 0, s2 = 0, mn = LLONG_MAX, mx = 0;
        for (int i = 1; i <= n; ++i) {
            s1 += a[i];
            mx = max(mx, (s1 + i - 1) / i);
        }
        for (int i = n; i >= 1; --i) {
            s2 += a[i];
            mn = min(mn, s2 / (n - i + 1));
        }
        cout << mx - mn << '\n';
    }
    return 0;
}
