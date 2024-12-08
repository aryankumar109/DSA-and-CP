#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t ;
	cin >> t ;
	while(t--){
	    int n , k ;
	    cin >> n >> k ;
	    vector<int>arr(n);
	    for(int i=0 ; i < n ; i++){
	        cin >> arr[i] ;
	    }
	    sort(arr.begin() , arr.end()) ;
	    int p = n-k ;
	    int score ;
	    if(k==1 )  score = arr[n-1] + arr[n-2] + arr[0] + arr[n-k] ;
	    else score = arr[n-1] + arr[n-2] + arr[0] + arr[n-k-1] ;
	    cout << score << endl ;
	    
	}

}
