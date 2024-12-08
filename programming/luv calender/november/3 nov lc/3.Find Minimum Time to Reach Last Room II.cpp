class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int row = moveTime.size();
        int col = moveTime[0].size();
        priority_queue<tuple<int, int, int,int>, vector<tuple<int, int, int,int>>,greater<tuple<int, int, int,int>>> pq;
        vector<vector<int>> times(row, vector<int>(col, INT_MAX));
        pq.push({0,0,0,0});
        vector<pair<int,int>> dir= {{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto [time, x, y,flip]=pq.top();
            pq.pop();
            if(x==row-1 && y==col-1) return time;
            int i=0;
            while(i<4){
                int newX= x+ dir[i].first;
                int newY = y+ dir[i].second;
                if(newX<row && newX>=0 && newY<col && newY>=0 && times[newX][newY]==INT_MAX){
                   if(time>=moveTime[newX][newY]) times[newX][newY]=time+ flip%2+1;
                   else times[newX][newY]=moveTime[newX][newY] +flip%2+1;
                    pq.push({times[newX][newY],newX,newY,flip%2+1});
                }
                i++;
            }
        }
        return -1;
    }
};