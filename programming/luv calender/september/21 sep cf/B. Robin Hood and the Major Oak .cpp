#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n , k ;
    cin >> n ;
    cin >> k ;
    int p = n - k + 1 ;
    if(p%2 == 0){
        if(k == 1 || (k/2)%2 == 0) cout<<"YES"<<'\n' ;
        else cout << "NO" << '\n' ;
    }else{
        if(k > 1 && ((k+1)/2)%2==0) cout <<"YES"<<'\n' ;
        else cout << "NO" << '\n' ;
    }
}

int main() {
  
    int t ; 
    cin >> t; 
    while(t--) {
        solve(); 
    }
}
