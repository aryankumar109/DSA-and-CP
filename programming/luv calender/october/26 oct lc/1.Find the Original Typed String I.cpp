class Solution {
private :
    int solve(int ans , vector<int>&groups){
        for (int g : groups) {
            ans += g;
        }
        return ans+1 ;
    }
public:
    int possibleStringCount(string word) {
        if (word.empty()== true) return 0;
            
        else{
            vector<int> groups;
            int count = 0;
            for (int i = 1; i < word.size(); ++i) {
                if (word[i] == word[i - 1]) {
                    count++;
                } else {
                    groups.push_back(count);
                    count = 0;
                }
            }
            groups.push_back(count);
            int total_possibilities = 0;
            
            
    
            return solve(total_possibilities , groups) ;
        }
        return 0 ;
    }
};


