#include <iostream>
using namespace std ;
 
int main() {
    int t , n , x , y ;
    cin >> t ;
    while (t--){
        cin>>n >>x>>y ;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        int a = min(x,y);
        int ans = n/a ;
        if(n%a !=0 ) ans ++ ;
        cout << ans << endl ; 
    }
}