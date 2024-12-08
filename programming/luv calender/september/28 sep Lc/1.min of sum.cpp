class Solution {
public:
    int solve(int k){
        int ans = 0 ;
        while(k>0){
            ans += (k%10);
            k /= 10 ;
        }
        return ans ;
    }
    int minElement(vector<int>& nums) {
        vector<int>arr ;
        int min1 = INT_MAX ;
        for(int i=0 ; i< nums.size() ; i++){
            int p = solve(nums[i]) ;
            arr.push_back(p);
            min1 = min(p , min1) ;
        }
        return min1 ;
    }
};