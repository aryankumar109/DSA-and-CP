#include <bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(vector<int>& nums) {
  int n = nums.size();
  vector<int> ans;
  ans.push_back(nums[0]);
  for (int i = 1; i < n; i++) {
    if (nums[i] > ans.back()) {
      ans.push_back(nums[i]);
    } else {
      auto low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
      ans[low] = nums[i];
    }
  }
  return ans.size();
}

static bool compare(const vector<int>& x, const vector<int>& y) {
    return x[0] < y[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> arr[i][j];
            }
        }
        sort(arr.begin(), arr.end(), compare);
        vector<int> finalarray;
        for (int i = 0; i < n; i++) {
            finalarray.push_back(arr[i][1]);
        }
        cout << longestIncreasingSubsequence(finalarray) << endl;
    }
    return 0;
}
