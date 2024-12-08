#define ll long long
class Solution {
    const int mod = 1e9 + 7;  // Correct definition of mod
    int dp[200][201][201];  // Ensure dp is properly declared

public:
    int countPairs(int index, std::vector<int>& nums, int gcd1, int gcd2) {
        if (index == nums.size()) {
            return (gcd1 && gcd2) && (gcd1 == gcd2);
        }
        if (dp[index][gcd1][gcd2] != -1) return dp[index][gcd1][gcd2];
        
        int skip = countPairs(index + 1, nums, gcd1, gcd2);
        int takeGcd1 = countPairs(index + 1, nums, std::gcd(gcd1, nums[index]), gcd2);
        int takeGcd2 = countPairs(index + 1, nums, gcd1, std::gcd(gcd2, nums[index]));

        return dp[index][gcd1][gcd2] = (0ll+skip + takeGcd1 + takeGcd2) % mod;  // Correct accumulation
    }

    int subsequencePairCount(std::vector<int>& nums) {
        memset(dp, -1, sizeof(dp));  // Initialize dp array
        return countPairs(0, nums, 0, 0);
    }
};