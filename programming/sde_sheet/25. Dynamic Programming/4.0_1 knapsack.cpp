#include <iostream>
#include <vector>
using namespace std;

int solve(int idx, int n, int w, vector<int>& values, vector<int>& weights , vector<vector<int>>&dp) {
    // Base case: no items left or weight capacity is 0
    if (idx == n || w <= 0) return 0;

    if (dp[idx][w] != -1) return dp[idx][w] ;
    // Option 1: Do not take the current item
    int nottake = solve(idx + 1, n, w, values, weights , dp);

    // Option 2: Take the current item (only if it fits in the knapsack)
    int take = 0;
    if (weights[idx] <= w) {
        take = values[idx] + solve(idx + 1, n, w - weights[idx], values, weights , dp);
    }

    // Return the maximum of taking or not taking the item
    return dp[idx][w] =  max(take, nottake);
}

int maxProfit(vector<int>& values, vector<int>& weights, int n, int w) {
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1))  ;
    return solve(0, n, w, values, weights , dp);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        vector<int> values(n), weights(n);

        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }

        cout << maxProfit(values, weights, n, w) << endl;
    }
    return 0;
}
