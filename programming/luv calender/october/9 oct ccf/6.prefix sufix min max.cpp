#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int B[n];
        for (int i = 0; i < n; ++i) cin >> B[i];
        int A[n];
        memset(A, 0, sizeof A);
        A[0] = 2e6;
        int sum = A[0], mx = A[0];
        for (int i = 1; i < n; ++i) {
            A[i] = B[i] + mx - sum;
            sum += A[i];
        }
        for (int i = 0; i < n; ++i) cout << A[i] << " ";
        cout << "\n";
    }
    return 0;
}