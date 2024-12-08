#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ratings(n);
        for (int i = 0; i < n; ++i) {
            cin >> ratings[i];
        }
        if(n==2){
            cout<< ratings[1]-ratings[0]<<endl ;
            continue ;
        }
        long long int remaining = ratings[n-2] ;
        for (int i=n-3 ; i >= 0 ; i -- ){
            remaining -= ratings[i] ;
        }
        cout << ratings[n-1] - remaining << endl ;
    }
    return 0;
}