#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> P(n);
        for(int i=0;i<n;i++){
            cin>>P[i];
        }
        int m=-1;
        for (int i=0;i<n;i++)
        {
            if((i+1) !=(P[i])) 
                m=i+1;
        }
        // if (m==0) cout<<m<<endl;
        cout<<m+1<<endl;
   
    }
    return 0;
}