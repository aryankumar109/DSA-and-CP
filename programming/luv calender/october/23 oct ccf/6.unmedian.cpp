#include <bits/stdc++.h>
using namespace std;

int main() {
	int t ;
    cin >> t ;
    while(t--){
        int  n ;
        cin >> n ;
        vector<int>arr(n) ;
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        int min1_idx ;
        int max1_idx ;
        for(int i =0 ; i<n ; i++){
            cin >> arr[i] ;
            min1 = min(min1 , arr[i]);
            max1 = max(max1 , arr[i]) ;
            if(min1 == arr[i]) min1_idx = i+1 ;
            if(max1 == arr[i]) max1_idx = i+1 ;
        }
        if(min1_idx > max1_idx) {
            cout << -1 << endl ;
            continue ;
        }
        cout<<(n-2)<<endl ;
        for(int i =0 ; i<n-2 ; i++){
            
            cout<<1<<" "<<3<<endl ;
        }
    }
}
