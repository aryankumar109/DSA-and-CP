class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);

        for (size_t i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            for (int x = 0; x <= num; ++x) {
                if ((x | (x + 1)) == num) {
                    ans[i] = x;
                    break;
                }
            }
        }

        return ans ;
    }
};