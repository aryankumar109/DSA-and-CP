class Solution{
	public:
	int solve(int arr[], int index,int prev, int n,vector<vector<int>>&dp){
	    if(index==n)return 0;
	    if(dp[index][prev+1]!=-1)return dp[index][prev+1];
	    int not_take = solve(arr,index+1,prev,n,dp);
	    int take = 0;
	    if(prev==-1||arr[prev]<arr[index]){ 
	        take = arr[index] + solve(arr,index+1,index, n,dp);
	    }  
	    return dp[index][prev+1] = max(take,not_take);
	}
	int maxSumIS(int arr[], int n)  
	{   
	    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	    return solve(arr,0,-1,n,dp);
	} 
};
