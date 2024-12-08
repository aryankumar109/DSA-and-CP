class Solution {

public:
   // Function to find minimum number of attempts needed in
   // order to find the critical floor.

   int min_moves(int eggs, int floors ,  vector<vector<int>> & dp)
   {
       if (eggs == 1) {
           return floors;
       }
       if (floors == 0 || floors == 1) {
           return floors;
       }
       if(dp[eggs][floors] != -1) return dp[eggs][floors] ;
       int ans = 1e9;
       for (int i = 1; i <= floors; i++) {

           // eggs break from this floor , so try below
           // floors
           int op1 = min_moves(eggs - 1, i - 1, dp);

           // eggs break from this floor , so try remaining
           // above floors
           int op2 = min_moves(eggs, floors - i , dp);

           // temp stores minimum moves to find thresold
           // floor in worst case
           int temp = 1 + max(op1, op2);

           // we have to minimize the maximum answer
           ans = min(ans, temp);
       }
       return dp[eggs][floors] = ans;
   }

   int eggDrop(int n, int k) { 
       vector<vector<int>>dp(n+1 , vector<int>(k+1 ,-1)) ;
       return min_moves(n, k ,dp); 
       
   }
};