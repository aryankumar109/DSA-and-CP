class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i=0 , j = m-1 ;
        map<int,int>mpp2 ;
        map<int,int>mpp1 ;
        for(int i=0 ; i < word2.size() ; i++) {
            mpp2[word2[i]-'a'] ++ ; 
            mpp1[word1[i] - 'a'] ++ ;
        }
        long long int ans = 0 ;
        while(i <=j && j < n){
            bool flag = true ;
            for(int k=0 ; k<26 ; k++){
                if(mpp1[k] < mpp2[k]){
                    flag = false ;
                    break ;
                } 
            }
            if(flag){
                ans += (n-i) - (j-i+1) +1 ; mpp1[word1[i] - 'a']--; ; i ++ ; 
            }else{
                j ++ ; mpp1[word1[j] - 'a'] ++ ;
            }
            if(i > j ) {
                 j ++ ; mpp1[word1[j] - 'a'] ++ ;
            }
        }
        return ans ;
    }
};