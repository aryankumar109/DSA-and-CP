#include <iostream>
using namespace std;

void print(int l) {
    cout << 0 << " " << 0 << " " << l << " " << l << endl;
    cout << 0 << " " << l << " " << l << " " << 0 << endl;
}

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int l = min(x, y);
    print(l);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


