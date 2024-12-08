#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
#define ll long long 

void solve(){
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    ll q;
    cin>>q;
    vector<ll>a(n);
    for(auto &it:a)cin>>it;
    vector<ll>b(m);
    for(auto &it:b)cin>>it;
 
    vector<ll> uniqueElements;
    
    unordered_set<ll> seen;

    for (int i : b ) {
        if (seen.find(i) == seen.end()) {
            uniqueElements.push_back(i);
            seen.insert(i);             
        }
    }
    ll k = uniqueElements.size();
    for(int i=0 ; i< min(n,k) ; i++){
        if(a[i] != uniqueElements[i]){
            cout<<"TIDAK"<<endl;
            return;
        }
    }
    cout<<"YA"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
