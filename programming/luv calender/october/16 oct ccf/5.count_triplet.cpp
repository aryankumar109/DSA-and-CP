#include <bits/stdc++.h>
using namespace std;

/*
i) j is in [i, k], then abs(Ai - Ak) = abs(k - i)
ii) If j is minimum, then 2j = i + k - abs(Ai - Ak)
iii) If j is maximum, then 2j = i + k + abs(Ai - Ak)

Clearly in i) case, difference b/w indexes i and k can at max be 100

In ii)
2j = i + k - abs(Ai - Ak)
Let's assume that i <= k
Since j is minimum, j < i
i.e. 2j < 2i
=> i + k - abs(Ai - Ak) < 2i
=> k - abs(Ai - Ak) < i
=> k - i < abs(Ai - Ak)
Now, since abs(Ai - Ak) <= 100
i.e. k - i < 100

In iii)
2j = i + k + abs(Ai - Ak)
Let's assume that i <= k
Since j is maximum, j > k
i.e. 2j > 2k
=> i + k + abs(Ai - Ak) > 2k
=> i + abs(Ai - Ak) > k
=> k - i < abs(Ai - Ak)
Now, since abs(Ai - Ak) <= 100
i.e. k - i < 100

Hence, in all the cases, the difference b/w indexes i and k can at max be 100
*/

int main() {
    #ifdef ABHISHEK_SRIVASTAVA
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        long long triplets = 0;

        for (int i = 1; i <= n; i++)
            for (int k = max(1, i - 100); k <= min(n, i + 100); k++) {
                int diff = abs(arr[i] - arr[k]);
                if (diff == abs(i - k)) // Case i)
                    triplets += abs(i - k) + 1; // j can be anywhere in between i and k
                if ((i + k - diff) % 2 == 0) { // Case ii)
                    int j = (i + k - diff) / 2;
                    triplets += (j > 0 && j < min(i, k)); // j should be minimum
                } 
                if ((i + k + diff) % 2 == 0) { // Case iii)
                    int j = (i + k + diff) / 2;
                    triplets += (j > max(i, k) && j <= n); // j should be maximum
                }
            }
        cout << triplets << '\n';
    }

    return 0;
}
