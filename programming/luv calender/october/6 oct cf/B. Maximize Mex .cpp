#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long 

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &it : v) {
        cin >> it;
    }
    map<ll, ll> mp, mp1;
    
    for (auto it : v) {
        mp1[it]++;
    }
    
    int cnt = 0;

    while (true) {
        if (mp1[cnt] > 0) {
            mp1[cnt]--;
            ll f = mp1[cnt];
            for (int i = 0; i < f; i++) {
                mp[cnt % x]++;
            }
            cnt++;
        } else if (mp[cnt % x] > 0) {
            mp[cnt % x]--;
            cnt++;
        } else {
            break;
        }
    }
    
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
