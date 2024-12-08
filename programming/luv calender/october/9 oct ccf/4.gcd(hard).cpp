#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int N,M;
	    cin>>N>>M;
	    queue<int>qu1;
	    qu1.push(2);
	    qu1.push(3);
	    queue<int>qu2;
	    qu2.push(3);
	    qu2.push(2);
	    vector<vector<int>>v(N,vector<int>(M,2));
	    if(N==M){
    	    for(int i=0;i<N;i++){
    	        v[i][i]=3;
    	    }
    	    for(int i=0;i<N;i++){
    	        for(auto d:v[i]){
    	            cout<<d<<" ";
    	        }
    	        cout<<endl;
    	    }
	    }
	    else if(N>M){
    	    for(int i=0;i<M;i++){
    	        v[i][i]=3;
    	    }
    	    for(int j=M;j<N;j++){
    	        v[j][M-1]=3;
    	    }
    	    for(int i=0;i<N;i++){
    	        for(auto d:v[i]){
    	            cout<<d<<" ";
    	        }
    	        cout<<endl;
    	    }
	    }
	    else{
    	    for(int i=0;i<N;i++){
    	        v[i][i]=3;
    	    }
    	    for(int j=N;j<M;j++){
    	        v[N-1][j]=3;
    	    }
    	    for(int i=0;i<N;i++){
    	        for(auto d:v[i]){
    	            cout<<d<<" ";
    	        }
    	        cout<<endl;
    	    }
	    }
	}

}
