#include <iostream>
#include <unordered_map>
using namespace std;

int T, N, A[200005];
int ans[200005];
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> A[i];
        unordered_map<long long, int> cnt;
        int total = 0;
        for (int i = 1; i <= N; ++i) {
            long long val = A[i];
            cnt[val]++;
            total++;
            while (cnt[val] >= 2) {
                cnt[val] -= 2;
                total--;
                val *= 2;
                cnt[val]++;
            }
            ans[i] = total;
        }
        for (int i = 1; i <= N; ++i) cout << ans[i] << " " ;
        cout << endl;
    }
    return 0;
}