#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n , k , t;
	cin>>t ;
	while(t--){
    	cin>>n>>k ;
    	vector<int>arr(n) ;
    	for(int i=0 ; i<n ; i++){
    	    cin>>arr[i] ;
    	}
    	int sum = 0 ;
    	int ans = 0 ;
    	for(int i=0 ; i < n ; i++){
    	    sum += arr[i];
    	    if(sum > k) break ;
    	    else ans ++ ;
    	}
    	cout<< ans << endl  ;
	}
	

}
