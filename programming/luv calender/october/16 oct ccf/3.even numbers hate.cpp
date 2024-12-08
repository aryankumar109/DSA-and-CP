#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    
    int t ;
    cin >> t ;
    while(t--){
        int even = 0 , odd  = 0 ;
        int n ;
        cin >> n ;
        vector<int>arr(n) ;
        for(int i=0 ; i < n ; i++){
            cin >> arr[i] ;
        }
        for(int i=0 ; i < n ; i++){
            if(arr[i]%2 == 0){
                even ++ ;
                
            }
            else odd ++ ;
        }
        if(odd ==0) cout<<0<<endl ;
        if(odd ==1) cout<<n<<endl ;
        if(odd >1){
            odd -- ;
            cout<< 1+ even+ odd/2 << endl ;
        }
    }
    return 0 ;
}


