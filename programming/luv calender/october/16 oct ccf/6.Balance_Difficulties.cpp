#include <bits/stdc++.h>
using namespace std;

bool isPossible(int mid, vector<int>& arr, int k) {
    int n = arr.size();
    int last = arr[0] + mid; // Initial position with added mid

    for (int i = 1; i < n; i++) {
        if (last + k < arr[i] - mid) {
            return false; // If we can't reach the current element with the constraints
        }
        last = min(arr[i] + mid, last + k); // Update last with the minimum possible
    }
    return true; // If we can reach all elements within the limits
}

int solve(int min1, int max1, vector<int>& arr, int k) {
    int result = -1; // Initialize answer
    while (min1 <= max1) {
        int mid = min1 + (max1 - min1) / 2;
        if (isPossible(mid, arr, k)) {
            result = mid; // Update the answer
            max1 = mid - 1; // Try for a smaller mid
        } else {
            min1 = mid + 1; // Try for a larger mid
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        int min1 = 0;
        int max1 = arr[n - 1];

        int midValue = solve(min1, max1, arr, k);
        cout << midValue << endl;
        vector<int> ans(n);
        ans[0] = arr[0] + midValue;

        for (int i = 1; i < n; i++) {
            ans[i] = min(arr[i] + midValue, ans[i - 1] + k); // Construct ans with constraints
        }
        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " "; // Add space for better formatting
        }
        cout << endl; // New line after each test case
    }
    return 0;
}
