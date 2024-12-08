#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , k ;
    cin >> n ;
    cin >> k ;
    vector<int>arr(n);
    for(int i=0; i< n ; i++){
        cin >> arr[i] ;
    }
    int ans = 0 , count = 0  ;
    for(int i=0 ; i< n ; i++){
        if(arr[i] >= k ) ans += arr[i] ;
        if(ans > 0 && arr[i] == 0 ) {
            count ++ ; 
            ans -- ;
        }
    }
    cout << count << "\n" ;
}

int main() {
  
    int t ; 
    cin >> t; 
    while(t--) {
        solve(); 
    }
}
