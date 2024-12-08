class Solution {
  public:
    int specialSubarrays(int n, vector<int> &arr, int k) {
        
        int max1  =0 ;
        int count = 0 , left , right ;
        for(int i=0 ; i< n ; i++){
            max1 = arr[i] ;
            for(int j = i ; j < n ; j ++ ){
                left = arr[i] ;
                max1 = max(max1 , arr[j]) ;
                right = arr[j] ;
                if(abs(max1 -left - right) % k == 0) count ++ ;
            }
        }
        return count ;
    }
};