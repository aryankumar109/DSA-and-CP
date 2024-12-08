#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{


    int t; 
    cin >> t;

    while(t--) {   
        ll n, k, subtract = 0; cin >> n >> k;
        ll answer = k;

        vector<ll>a(n);
        for(auto &i : a) cin >> i;
        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++) {
            a[i] -= subtract; 
            k -= min(k, (n - i) * a[i]); 

            if(k == 0) break; 
            else answer++; 

            subtract += a[i];
        }

        cout << answer <<endl ;
    }
}