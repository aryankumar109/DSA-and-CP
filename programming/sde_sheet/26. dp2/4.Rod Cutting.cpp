class Solution {
private:
    int solve(int i, int j, vector<int>& cut1, vector<vector<int>>& dp) {
        if (i + 1 >= j) return 0; // No cuts needed if there are no segments
        if (dp[i][j] != -1) return dp[i][j]; // Return cached result
        
        int minCost = INT_MAX;
        for (int k = i + 1; k < j; k++) { // Iterate over possible cut positions
            int cost = solve(i, k, cut1, dp) + solve(k, j, cut1, dp) + cut1[j] - cut1[i];
            minCost = min(cost, minCost);
        }
        return dp[i][j] = minCost; // Cache the result
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<int> cut1;
        cut1.push_back(0);
        cut1.insert(cut1.end(), cuts.begin(), cuts.end());
        cut1.push_back(n);
        
        int m = cut1.size();
        vector<vector<int>> dp(m, vector<int>(m, -1)); // DP table initialized to -1
        
        return solve(0, m - 1, cut1, dp);
    }
};
