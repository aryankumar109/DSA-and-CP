class Solution {
private:
    vector<vector<int>> dp;
    vector<vector<int>> a, b;

    int f(int d, int c) {
        if (d == dp.size()) return 0;
        if (dp[d][c] != -1) return dp[d][c];
        
        int m = a[d][c] + f(d + 1, c);
        
        for (int n = 0; n < a[0].size(); n++) {
            if (n != c) {
                m = max(m, b[c][n] + f(d + 1, n));
            }
        }
        
        return dp[d][c] = m;
    }
    
public:
    int maxScore(int n, int k, vector<vector<int>>& s, vector<vector<int>>& t) {
        a = s;
        b = t;
        dp = vector<vector<int>>(k, vector<int>(n, -1));
        
        int maxResult = 0;
        for (int start = 0; start < n; start++) {
            maxResult = max(maxResult, f(0, start));
        }
        
        return maxResult;
    }
};
