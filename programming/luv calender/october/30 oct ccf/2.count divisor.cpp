#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, counteven=0, countodd=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                if(i%2==0){
                    counteven++;
                }
                else{
                    countodd++;
                }
            }
        }
        if(counteven>countodd){
            cout<<1<<endl;
        }
        else if(counteven==countodd){
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    
}