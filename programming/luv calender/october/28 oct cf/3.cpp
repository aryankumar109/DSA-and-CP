#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n ;
    cin >> n ;
    string s;
    cin >> s;
    long long int ans = 0, c = 0;

    for (int i = n-1 ; i >=0 ; i--) {
        if (c >= i) {
            ans += i+1;
            c--;
            continue;
        }
        if (s[i] == '1') {
            c++;
        } else {
            ans += i+1 ;
            c--;
            if (c < 0) c = 0;
        }
        
    }

    cout << ans << '\n';
}

int main(){
    int t ;
    cin >> t  ;
    while(t--){
        solve() ;
    }
    return 0; 
}
