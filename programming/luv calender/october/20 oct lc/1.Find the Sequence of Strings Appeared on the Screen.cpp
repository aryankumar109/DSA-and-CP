class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans ;
        string result ="" ;
        int i = 0 ;
        while(target != result){
            
            result += "a" ;
            while(result != target.substr(0 , i+1)){
                ans.push_back(result);
                result[i] ++ ;
            }
            ans.push_back(result);
            i ++ ;
        }
        return ans  ;
    }
};