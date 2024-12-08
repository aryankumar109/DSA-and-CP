#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int count=0;
    for(int i=0; i<n; i++)
    {
        count += (s[i]=='1');
    }
    if (count&1)
    {
        cout << 1 << endl;
    }
    else if (count>0)cout << 0 << endl;
    else cout << n << endl;
}

int main()
{   
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}