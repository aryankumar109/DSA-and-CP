class Solution {
private:
    bool isPalindrome(const string &s1) {
        int m = s1.size();
        for (int i = 0; i < m / 2; i++) {
            if (s1[i] != s1[m - i - 1]) return false;
        }
        return true;
    }
    
    int solve(int idx, string &str, vector<int>& dp) {
        if (idx == str.size()) return 0; // If we've reached the end of the string
        
        if (dp[idx] != -1) return dp[idx]; // Return cached result
        
        int minCost = INT_MAX;
        for (int j = idx; j < str.size(); j++) { // Include the character at j
            if (isPalindrome(str.substr(idx, j - idx + 1))) { // Check for palindrome
                int cost = 1 + solve(j + 1, str, dp); // Cut after j
                minCost = min(cost, minCost);
            }
        }
        
        return dp[idx] = minCost; // Cache the result
    }

public:
    int palindromicPartition(string str) {
        int n = str.size();
        vector<int> dp(n, -1); // DP array for memoization
        return solve(0, str, dp) - 1; // Subtract 1 because we count cuts
    }
};
