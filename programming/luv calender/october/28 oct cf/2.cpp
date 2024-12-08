#include <bits/stdc++.h>
using namespace std;
#define int long long
int t = 1, n, m, k;
void Solve()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 1, r = 1e18, mid, res;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int x = 0, i = 0;
        while (i < n & x < 2)
        {
            if (i + 1 < n)
                if (a[i] + mid >= a[i + 1])
                    i += 2;
                else
                    x++, i++;
            else
                x++, i++;
        }
        if (x < 2)
            res = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--)
        Solve();
}