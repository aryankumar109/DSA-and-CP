class Solution {
public:
    vector<vector<int>> dp;

    int func(int i, int j, vector<int>& chk, string& s, string& p) {
        if (j > i)
            return -1;
        if (i < 0) {
            return 0;
        }
        if (j < 0) {
            return func(i - 1, -1, chk, s, p) + chk[i];
        }
        if (dp[i][j] != -2)
            return dp[i][j];

        if (s[i] == p[j]) {
            dp[i][j] = func(i - 1, j - 1, chk, s, p);
        } else {
            dp[i][j] = -1;
        }
        if (func(i - 1, j, chk, s, p) != -1) {
            dp[i][j] = max(dp[i][j], func(i - 1, j, chk, s, p) + chk[i]);
        }

        return dp[i][j];
    }

    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size(), m = pattern.size();
        vector<int> chk(n, 0);
        for (auto i : targetIndices)
            chk[i] = 1;

        dp.assign(n, vector<int>(m, -2));

        return func(n - 1, m - 1, chk, source, pattern);
    }
};

//tc -> O(n^2)
//sc -> O(n^2)