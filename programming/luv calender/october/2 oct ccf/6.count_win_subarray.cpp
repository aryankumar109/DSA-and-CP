#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long result = count(a.begin(), a.end(), 1);
    int left = -1;

    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            if (i - 1 >= 0 && a[i - 1]) {
                left = max(left, i - 1);
            }
            if (i - 2 >= 0 && a[i - 2]) {
                left = max(left, i - 2);
            }
        }
        result += left - 0 + 1;
    }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solution() << endl;
    }
    return 0;
}
