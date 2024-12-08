//User function Template for C++


class Solution {
  public:
    vector<int> bestPrice(int n,vector<vector<int>> price,int k,int q, vector<vector<int>> queries) {
        // code here
        vector<int>ans ;
        int max1 = INT_MIN ;
        for(int i =0 ; i < n ; i++){
            max1 = max(max1 ,price[i][0]) ;
            max1 = max(max1 , price[i][1]) ;
        }
        for(int i=0 ; i < q ; i++){
            max1 = max(max1 , queries[i][0]);
            max1 = max(max1 , queries[i][1]) ;
        }
        vector<int>count(max1+1 , 0);
        for(int i =0 ; i < n ; i++){
            for(int j=price[i][0] ; j<= price[i][1] ; j++){
                 count[j] ++ ;
           
            }
        }
        
        for(int i =0 ; i < q ; i++){
            int result = 0 ;
            for(int j=queries[i][0] ; j<= queries[i][1] ; j++){
                if(count[j] >= k) result ++ ;
            }
            ans.push_back(result) ;
        }
        return ans ;
    }
};

