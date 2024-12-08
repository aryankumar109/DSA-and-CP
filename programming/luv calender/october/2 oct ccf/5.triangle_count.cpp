#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(v.begin(), v.end());

    vector<pair<ll, ll>> vp;
    for (ll i = 0; i < n - 1; i++)
    {
        vp.push_back({v[i + 1] - v[i] + 1, v[i + 1] + v[i] - 1});
    }
    sort(vp.begin(), vp.end());
    ll ans = vp[0].second - vp[0].first + 1;
    ll mx = vp[0].second;
    for (ll i = 1; i < vp.size(); i++)
    {
        ll x = vp[i].first;
        ll y = vp[i].second;
        if (x > mx)
        {
            ans += (y - x + 1);
            mx = y;
        }
        else
        {
            if (y > mx)
            {
                ans += (y - mx);
                mx = y;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ll tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}