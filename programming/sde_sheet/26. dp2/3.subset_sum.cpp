class Solution {
private:
    // Helper function to solve the subset sum problem
    int solve(vector<int>& arr, int idx, int target, vector<vector<int>>& dp) {
        if (target == 0) return 1;  // Found a subset with the required sum
        if (idx == arr.size()) return 0;  // No more elements to consider
        if (dp[idx][target] != -1) return dp[idx][target];  // Return memoized result

        // Option 1: Don't take the current element
        int notTake = solve(arr, idx + 1, target, dp);
        
        // Option 2: Take the current element (only if it doesn't exceed the target)
        int take = 0;
        if (target >= arr[idx]) {
            take = solve(arr, idx + 1, target - arr[idx], dp);
        }
        
        // Store the result in the dp array and return
        return dp[idx][target] = take || notTake;
    }

    // Function to check for subset sum
    bool subsetsum(vector<int>& arr, int target) {
        int n = arr.size();
        // Create a 2D dp array initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(arr, 0, target, dp);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;  // Calculate total sum of the array
        }
        if (sum % 2 != 0) return false;  // If the sum is odd, partition is not possible
        int target = sum / 2;  // We need to find a subset with this sum
        return subsetsum(nums, target);
    }
};
