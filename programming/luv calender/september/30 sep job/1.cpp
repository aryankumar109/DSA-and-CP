class Solution {
  public:
    vector<long long> finalArray(int n, vector<int> &B) {
        // code here
        vector<long long> C(n,0);
        for(int i = 0; i<n; i++){
            int num = B[i]-1;
            int j=i+1;
            while(j<n && num>0){
                C[j]+=num;
                j++;
                num--;
            }
            
        }
        vector<long long> ans(n);
        for(int i = 0; i<n; i++){
            ans[i]=B[i] + C[i];
        }
        return ans;
    }
};