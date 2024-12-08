//Back-end complete function Template for C++

class Solution{
public:
    vector<int> maxStudent(int n,int m,int q,vector<int> &arr,vector<int> &strength,vector<vector<int>> &transfers){
        vector<vector<int>> A;
        vector<int> res,oddness(m+1,0);
        vector<set<int>> lib(m+1);
        vector<priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>> school(m+1);
        for(int i=0;i<n;i++){
            int strength_i=strength[i],school_i=arr[i]-1;
            A.push_back({strength_i,school_i});
            lib[school_i].insert(i);
            school[school_i].push({strength_i,i});
            oddness[school_i]=school[school_i].top()[0];
        }
        priority_queue<vector<int>,vector<vector<int>>> ans;
        for(int i=0;i<m;i++){
            if(oddness[i]>0) ans.push({oddness[i],i});
        }
        for(int j=0;j<q;j++){
            int c=transfers[j][0]-1,d=transfers[j][1]-1;
            int b=A[c][1];
            lib[b].erase(c);
            while(school[b].size() and lib[b].find(school[b].top()[1])==lib[b].end()){
                school[b].pop();
            }
            if(school[b].size()){
                oddness[b]=school[b].top()[0];
                ans.push({oddness[b],b});
            }
            else{
                oddness[b]=0;
            }
            A[c][1]=d;
            int a=A[c][0];
            lib[d].insert(c);
            school[d].push({a,c});
            if(oddness[d]!=school[d].top()[0]){
                oddness[d]=school[d].top()[0];
                ans.push({oddness[d],d});
            }
            int score=ans.top()[0],idx=ans.top()[1];
            while(oddness[idx]!=score){
                ans.pop();
                score=ans.top()[0];
                idx=ans.top()[1];
            }
            res.push_back(score);
        }
        return res;
    }
};
