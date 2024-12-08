#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int N,M;
	    cin>>N>>M;
	    queue<long long>qu1;
	    qu1.push(3);
	    qu1.push(5);
	    qu1.push(7);
	    qu1.push(11);
	    qu1.push(13);
	    queue<long long>qu2;
	    qu2.push(17);
	    qu2.push(19);
	    qu2.push(23);
	    qu2.push(29);
	    qu2.push(31);
	    vector<vector<int>>v(N,vector<int>(M));
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(i%2==0){
    	            v[i][j]=qu1.front();
    	            qu1.push(qu1.front());
    	            qu1.pop();
	            }
	            else{
	                v[i][j]=qu2.front();
    	            qu2.push(qu2.front());
    	            qu2.pop();
	            }
	        }
	    }
	    for(int i=0;i<N;i++){
	        for(auto d:v[i]){
	            cout<<d<<" ";
	        }
	        cout<<endl;
	    }
	}

}