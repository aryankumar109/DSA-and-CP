class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int count = 0;
            map<char, int> mpp;
            for (int j = i; j < n; ++j) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
                    mpp[word[j]]++;
                } else {
                    count++  ;
                }
                
                if (mpp.size() == 5 && count == k) {
                    ans++;
                    
                }
            }
        }
        
        return ans;
    }
};
