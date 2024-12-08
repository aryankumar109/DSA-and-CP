#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        map<int, int> factors;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0) {
                    factors[j]++;
                    if (j != (nums[i] / j)) {
                        factors[nums[i] / j]++;
                    }
                }
            }
        }

        map<int, long long> gcdCnt;
        for (auto it = factors.rbegin(); it != factors.rend(); it++) {
            long long val = it->second;
            long long res = (val * (val - 1)) / 2;
            gcdCnt[it->first] = res; 
            for (int j = it->first * 2; j <= nums.back(); j += it->first) {
                gcdCnt[it->first] -= gcdCnt[j];
            }
        }

        vector<long long> vec;
        vector<int> res, ans;
        long long start = 0;

        for (auto it : gcdCnt) {
            if (it.second == 0) continue;
            start += it.second;
            ans.push_back(it.first);
            vec.push_back(start - 1);
        }

        for (auto it : queries) {
            long long val = it;
            auto itl = lower_bound(vec.begin(), vec.end(), val);
            int index = itl - vec.begin();
            res.push_back(ans[index]);
        }

        return res;
    }
};
