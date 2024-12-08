
#include<bits/stdc++.h>
using namespace std;

static bool compare(pair<int,int>&A , pair<int ,int>&B){
    if(max(A.first, A.second) == max(B.first, B.second)) 
        return min(A.first, A.second) < min(B.first, B.second);
    return max(A.first, A.second) < max(B.first, B.second);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n ;
        cin>>n ;
        vector<pair<int,int>>a(n);

        for(auto &i : a) cin >> i.first >> i.second;

        sort(a.begin(), a.end(), compare );
        for(auto &i : a) cout << i.first << " " << i.second << " ";
        cout << endl ;
    }
    return 0 ;
}
