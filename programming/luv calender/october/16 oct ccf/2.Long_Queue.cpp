#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    int n ;
	    cin >> n ;
	    vector<int>arr(n) ;
	    for(int i=0 ; i < n ; i++){
	        cin >> arr[i] ;
	    }
	    
	    int target = arr[n-1] ;
	    int idx = n ;
	    for( int i = n-2 ; i >= 0 ; i--){
	        if(arr[i] <= (target/2)){
	            idx = i+1 ;
	        }
	        else break ;
	    } 
	    cout << idx <<endl ;
	    
	}
    return 0 ;
}
