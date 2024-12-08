long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<int> d(denominations, denominations + n);
    vector<long> dp(value + 1, 0);
    
    dp[0] = 1;  
    
    for (int coin : d) {
        for (int i = coin; i <= value; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[value];
}