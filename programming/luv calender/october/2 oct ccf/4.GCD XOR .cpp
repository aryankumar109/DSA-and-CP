#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T  ;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        bool allEqual = true;
        for (int i = 0; i < N; i++) {
            if (A[i] != K) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            cout << 0 << endl;
        } else {
            int start = -1, end = N;
            for (int i = 0; i < N; i++) {
                if (A[i] != K) {
                    if (start == -1) {
                        start = i;
                    }
                    end = i;
                }
            }

            if (start == end) {
                cout << 1 << endl;
            } else {
                bool x = true, d = true;
                int f = (A[start] ^ K);

                for (int i = start; i <= end; i++) {
                    if (A[i] % K != 0) {
                        d = false;
                    }
                    if ((A[i] ^ K) != f) {
                        x = false;
                    }
                }

                if (x || d) {
                    cout << 1 << endl;
                } else {
                    cout << 2 << endl;
                }
            }
        }
    }
    return 0;
}
