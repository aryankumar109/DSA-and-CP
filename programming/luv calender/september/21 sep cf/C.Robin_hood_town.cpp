#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        ll arr[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (n == 1 || n == 2)
            cout << -1 << "\n";
        else
        {
            double HAvg = sum / n / 2.0;
            sort(arr, arr + n);
            int mid = (n / 2);
            if (arr[mid] < HAvg)
                cout << 0 << "\n";
            else
            {
                ll res = (arr[mid] * 2 * n) + 1 - sum;
                if (res < 0)
                    cout << 0 << "\n";
                else
                    cout << res << "\n";
            }
        }
    }

    return 0;
}