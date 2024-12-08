#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T; // Read number of test cases
    while (T--) {
        int X, Y, Z;
        cin >> X >> Y >> Z; // Read X, Y, Z
        if (Y - X == Z - Y) {
            cout << 0 << endl; // Already in AP
        } else {
            cout << 1 << endl; // At least one operation needed
        }
    }
}