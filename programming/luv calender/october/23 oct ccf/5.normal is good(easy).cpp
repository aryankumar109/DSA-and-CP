#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n ;
    cin >> n ;
    vector<int>v(n);
    for(int i =0 ; i< n ; i++){
        cin >> v[i] ;
    }
    ll len = 1;
    ll i = 1;
    ll ans = 0;
    while (i < n)
    {
        if (v[i] == v[i - 1])
            len++;
        else
        {
            ans += (len * (len + 1)) / 2;
            len = 1;
        }
        i++;
    }
    ans += (len * (len + 1)) / 2;
    cout << ans << endl;
}

int32_t main(){
    int t ;
    cin >> t ;
    while(t--){
        solve() ;
    }
}