class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort (strs.begin() , strs.end())  ;
        string ch = "" ;
        int n = strs[0].size() ;
        int m = strs.size() ;
        string a = strs[0];
        string b = strs[m-1] ;
        for (int i = 0 ; i < n ; i++){
            if (a[i]== b[i] ){
                ch += a[i] ;
            }
            else break ;
        }
        return ch ;
    }
};