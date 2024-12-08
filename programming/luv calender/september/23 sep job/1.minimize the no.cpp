#include<numeric>
#include<vector>
class Solution {
  public:
    int gcd (int a , int b){
        while(b!= 0){
            int temp = b ;
            b = a%b ;
            a = temp ;
        }
        return a ;
    }
    long long lcm(int a , int b){
        return (static_cast<long long>(a)*b) / gcd(a,b) ;
    }
    long long lcmOfArray(vector<int>&arr1){
        long long result = arr1[0];
        for(int i=1 ; i <arr1.size() ; i++){
            result = lcm(result , arr1[i]);
        }
        return result ;
    }
    int minMod(int n, int arr[]) {
        // code here
        if(n==1) return 1 ;
        bool flag = false ;
        for (int i=0 ; i < n ; i++){
            if(arr[i]==1) flag = true ;
        }
        vector<int>arr1;
        for(int i=0 ; i<n ; i++){
            arr1.push_back(arr[i]);
        }
        if(flag){
            long long result = lcmOfArray(arr1);
            return (int) result;
        }
        else return 1 ;
    }
};