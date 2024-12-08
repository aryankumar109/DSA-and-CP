class Solution {
private:
    bool solve(int idx, string s, unordered_set<string>& set1 , vector<int>&dp) {
        if (idx == s.size()) return true; // Reached the end of the string
        if (dp[idx] != -1) return dp[idx] ;
        for (int j = idx + 1; j <= s.size(); j++) {
            string sub = s.substr(idx, j - idx); // Get the substring from idx to j
            if (set1.find(sub) != set1.end() && solve(j, s, set1 , dp )) {
                return dp[idx] = true; // Found a valid substring and continue searching
            }
        }
        return dp[idx] = false; // No valid split found
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set1(wordDict.begin(), wordDict.end()); // Initialize the set
        vector<int>dp(s.size()  , -1);
        return solve(0, s, set1 , dp); // Start recursion from index 0
    }
};




        