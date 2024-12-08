#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n<4) cout<<0<<endl;
	    else{
	        int a=n/4;
	        int b=n%4;
	        int c=n/4;
	        if(b==1){
	            cout<< a*c<<endl;
	        }
	        else if(b==2 ){
	            cout<<(a+1)*c<<endl;
	        }
	        else if(b==3){
	            cout<<(a+1)*c<<endl;
	        }
	        else cout<<(a)*c<<endl;
	    }
	}
}