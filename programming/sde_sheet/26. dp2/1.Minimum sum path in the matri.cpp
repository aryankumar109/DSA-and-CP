#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base case: if we are out of bounds
    if (i >= n || j >= m) return INT_MAX; // Use INT_MAX to signify invalid path
    
    // Base case: reached the bottom-right cell
    if (i == n - 1 && j == m - 1) return grid[i][j];
    
    // Check memoization
    if (dp[i][j] != -1) return dp[i][j];
    // Recursive calls to move down and right
    int down = solve(i + 1, j, n, m, grid, dp);
    int right = solve(i, j + 1, n, m, grid, dp);
    
    // Store the result in dp
    dp[i][j] = grid[i][j] + min(down, right);
    
    return dp[i][j];
}
int minSumPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> dp(n, vector<int>(m, -1)); // Correct size for dp
    return solve(0, 0, n, m, grid, dp);
}